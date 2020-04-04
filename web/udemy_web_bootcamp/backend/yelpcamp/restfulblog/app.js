// Express is our HTTP server.
const express = require("express");
// We need body-parser for easy access to form data provided in the body of an POST 
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser");
// Mongoose is our DB API.
const mongoose = require("mongoose");

/** Mongoose setup START **/
// "restfulblog" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/restfulblog", {useNewUrlParser: true, useUnifiedTopology: true});
// Define schema for the data to be added to the DB.
const blogSchema = mongoose.Schema({
    title: String,
    image: String,
    thetext: String,
    date: {type: Date, default: Date.now}
});

// "blogs" will show up in "mongoose shell>>> use restfulblog; show collections"
// "mongoose shell>>> db.blogs.find()" will display all DB entries.
// Get an instance of the DB for the given schema.
const Blog = mongoose.model("Blog", blogSchema);

/** Mongoose setup END **/

/* Test adding an entry */
// blog0 = new Blog({
//     title: "Science: Mangos reverse aging.",
//     image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg",
//     thetext: "A new study shows that mangos can reverse aging. The price of mango has since sky rocketed. ..."
// });

// blog0.save(function(err, entry){
//     if(err) {
//         console.log("Error adding new entry: ");
//         console.log(err);
//     } else {
//         console.log("New entry added: ");
//         console.log(food);
//     }
// })


/** Express setup START **/
const app = express();
app.use(express.static("public")); // Tell express where to look for e.g. CSS files.
// Enable x-www-form-urlencoded in body-parser. Tell express to use body-parser.
app.use(bodyParser.urlencoded({extended: true})); 
/** Express setup END **/

app.get("/", function (exp_request, exp_response) {
    console.log("GET @ /.");
    exp_response.redirect("/blogs");
});

app.get("/blogs", function (exp_request, exp_response) {
    console.log("GET @ /blogs.");
    Blog.find({}, function(err, entries){
        if(err) {
            console.log("Error getting all entries: ");
            console.log(err);
            exp_response.send("Error getting entries.");
        } else {
            console.log(entries.length + " entries found: ");
            console.log(entries);
            exp_response.render("index.ejs", {entries: entries});
        }
    });
});

// Tell express to start listening for HTTP requests.
const PORT = 3000;
const IP = "127.0.0.1";
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});