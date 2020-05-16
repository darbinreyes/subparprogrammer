// Express is our HTTP server.
const express = require("express");
// We need body-parser for easy access to form data provided in the body of an POST 
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser"); 
// Mongoose is our DB API.
const mongoose = require("mongoose");

/** Mongoose setup START **/
// "yelpnutritionv5" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/yelpnutritionv5", {useNewUrlParser: true, useUnifiedTopology: true});

const Nutrition = require("./models/nutrition");
const Comment = require("./models/comment");
const seedDB = require("./seedDB");
seedDB();
/** Mongoose setup END **/

/** Express setup START **/
const app = express();

app.use(express.static("public")); // Tell express where to look for CSS files.

// Enable x-www-form-urlencoded in body-parser. Tell express to use body-parser.
app.use(bodyParser.urlencoded({extended: true})); 
/** Express setup END **/

// Add a GET request handler for /.
app.get("/", function (exp_request, exp_response) {
    console.log("GET @ /.");
    exp_response.render("landing.ejs");
});

// This is our fake database.
// nutritions = [
// {name: "Mango", image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg"},
// {name: "Lime", image: "https://upload.wikimedia.org/wikipedia/commons/6/68/Lime-Whole-Split.jpg"},
// {name: "Strawberry", image: "https://upload.wikimedia.org/wikipedia/commons/e/e1/Strawberries.jpg"},
// {name: "Avocado", image: "https://upload.wikimedia.org/wikipedia/commons/c/c0/Avocado-board.jpg"},
// {name: "Green Leaf Lettuce", image: "https://upload.wikimedia.org/wikipedia/commons/8/85/HK_food_%E8%94%AC%E8%8F%9C_vegetable_Lettuce_%E7%94%9F%E8%8F%9C_Lactuca_Sativa_green_leaves_with_fresh_clear_water_January_2019_SSG_02.jpg"},
// {name: "Tomato", image: "https://upload.wikimedia.org/wikipedia/commons/b/b7/Tomato-top.png"},
// {name: "Mango", image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg"},
// {name: "Lime", image: "https://upload.wikimedia.org/wikipedia/commons/6/68/Lime-Whole-Split.jpg"},
// {name: "Strawberry", image: "https://upload.wikimedia.org/wikipedia/commons/e/e1/Strawberries.jpg"},
// {name: "Avocado", image: "https://upload.wikimedia.org/wikipedia/commons/c/c0/Avocado-board.jpg"},
// {name: "Green Leaf Lettuce", image: "https://upload.wikimedia.org/wikipedia/commons/8/85/HK_food_%E8%94%AC%E8%8F%9C_vegetable_Lettuce_%E7%94%9F%E8%8F%9C_Lactuca_Sativa_green_leaves_with_fresh_clear_water_January_2019_SSG_02.jpg"},
// {name: "Tomato", image: "https://upload.wikimedia.org/wikipedia/commons/b/b7/Tomato-top.png"}
// ];

// Add a GET request handler for /.
app.get("/campgrounds", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds.");
    // Display the nutritions array obtained from the DB.
    Nutrition.find({}, function(err, nutritions){
        if(err) {
            console.log("DB.find() failed: ");
            console.log(err);
        } else {
            console.log("DB.find() successful. Found " + nutritions.length + " entries.");
            console.log(nutritions);
            exp_response.render("campgrounds/index.ejs", {nutritions: nutritions});
        }
    });
});

app.post("/campgrounds", function (exp_request, exp_response){
    console.log("POST @ /campgrounds.");
    // Get form data specifying what will be added.
    // Add new entry to DB.
    // redirect to /campgrounds.
    var entryName = exp_request.body.name;
    var entryImage = exp_request.body.image;
    var entryEnergy = exp_request.body.energy;
    var entryDescription = exp_request.body.description;

    newEntry = new Nutrition({
        name: entryName,
        image: entryImage,
        energy: entryEnergy,
        description: entryDescription
    });

    newEntry.save(function(err, entry){
        if(err) {
            console.log("Failed to add new entry: ");
            console.log(err);
        } else {
            console.log("New entry added successfully: ");
            console.log(entry);
        }
        exp_response.redirect("/campgrounds"); // Redirect upon completion of DB.save() otherwise the new entry may not be visible if we redirect before the save completes.
    });

});

app.get("/campgrounds/new", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds/new.");
    // Show the form for adding a new entry to the DB.
    exp_response.render("campgrounds/new.ejs");
});

app.get("/campgrounds/:id", function(exp_request, exp_response){
    // Example valid ID: 5e878925d90bb0b95ec6bf14, string, 24 chars.
    console.log("GET @ /camgrounds/" + exp_request.params.id);
    
    // TODO/FYI: App errors our when ID argument below is invalid.

    // Show the details of the DB entry with given ID.
    //Nutrition.findById(exp_request.params.id, function(err, entry){
    Nutrition.findById(exp_request.params.id).populate("comments").exec(function(err, entry){
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            console.log(entry);
            exp_response.render("campgrounds/show.ejs", {entry: entry});
        }
    });
});

//
// ==================== Comment Routes ======================
//

app.get("/campgrounds/:id/comments/new", function(exp_request, exp_response){
    // Form for adding a comment.
    console.log("GET @ /camgrounds/" + exp_request.params.id + "/comments/new");
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            console.log(entry);
            exp_response.render("comments/new.ejs", {entry: entry});
        }
    });
});

app.post("/campgrounds/:id/comments", function(exp_request, exp_response){
    console.log("POST @ /camgrounds/" + exp_request.params.id + "/comments");
    // Add a new comment to the DB entry with the specified ID.
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            console.log(entry);
            Comment.create(exp_request.body.comment, function(err, created_comment){
                if(err){
                    console.log("create() error: ");
                    console.log(err);
                } else {
                    console.log("create() successful: ");
                    console.log(created_comment);
                    console.log("pushing() comment: ");
                    entry.comments.push(created_comment);
                    entry.save(function(err, saved_entry){
                        if(err) {
                            console.log("save() error: ");
                            console.log(err);
                        } else {
                            console.log("save() successful: ");
                            exp_response.redirect("/campgrounds/" + exp_request.params.id);
                        }
                    });
                }
            });
        }
    });
});

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});