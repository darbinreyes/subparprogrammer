// Express is our HTTP server.
const express = require("express");
// We need body-parser for easy access to form data provided in the body of an POST 
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser");
// Mongoose is our DB API.
const mongoose = require("mongoose");
// method-override allows us to work-around the fact that HTML forms only support
// method=POST or GET.
const methodOverride = require('method-override');
// We use express-sanitizer to remove e.g. script tags from user text inputs.
const expressSanitizer = require("express-sanitizer");

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

/** Express setup START **/
const app = express();
app.use(express.static("public")); // Tell express where to look for e.g. CSS files.
// Enable x-www-form-urlencoded in body-parser. Tell express to use body-parser.
app.use(bodyParser.urlencoded({extended: true}));
// IMPORTANT: express-sanitizer app.use() should go AFTER body-parser above.
app.use(expressSanitizer());
// Tell Express to use the method-override package. This configuration of
// method-override looks for a POST request with a URL query parameter
// _method=PUT and turns that POST into a PUT request within Express.
app.use(methodOverride('_method'));
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

app.post("/blogs", function(exp_request, exp_response) {
    console.log("POST @ /blogs.");
    console.log("exp_request.body.blog: ");
    console.log(exp_request.body.blog);
    // Sanitize the blog.thetext field.
    exp_request.body.blog.thetext = exp_request.sanitize(exp_request.body.blog.thetext);
    // Add a new DB entry.
    Blog.create(exp_request.body.blog, function(err, new_entry){
        if(err) {
            console.log(".create() error: ");
            console.log(err);
            exp_response.send(".create() error. Sorry.");
        } else {
            console.log("New entry created: ");
            console.log(new_entry);
            exp_response.redirect("/blogs");
        }
    });
});

app.get("/blogs/new", function(exp_request, exp_response){
    console.log("GET @ /blogs/new.");
    exp_response.render("new.ejs");
});

app.get("/blogs/:id", function(exp_request, exp_response){
    console.log("GET @ /blogs/" + exp_request.params.id + ".");
    Blog.findById(exp_request.params.id, function(err, found_entry){
        if(err) {
            console.log(".findById() error: ");
            console.log(err);
            exp_response.send(".findById() error. Sorry.");
        } else {
            console.log("Entry found: ");
            console.log(found_entry);
            exp_response.render("show.ejs", {blog: found_entry});
        }
    });
    
});

app.put("/blogs/:id", function(exp_request, exp_response){
    console.log("PUT @ /blogs/" + exp_request.params.id + ".");
    console.log("request.body.blog: ");
    console.log(exp_request.body.blog);
    // Sanitize the blog.thetext field.
    exp_request.body.blog.thetext = exp_request.sanitize(exp_request.body.blog.thetext);
    // Update the DB entry and redirect to its show page.
    Blog.findByIdAndUpdate(exp_request.params.id, exp_request.body.blog, function(err, updated_entry){
        if(err) {
            console.log(".findByIdAndUpdate() error: ");
            console.log(err);
            exp_response.send(".findByIdAndUpdate() error. Sorry.");
        } else {
            console.log("Updated entry: ");
            console.log(updated_entry);
            exp_response.redirect("/blogs/" + exp_request.params.id);
        }
    });
});

app.delete("/blogs/:id", function(exp_request, exp_response){
    console.log("DELETE @ /blogs/" + exp_request.params.id + ".");
    // Remove the specified DB entry.
    Blog.findByIdAndRemove(exp_request.params.id, function(err, removed_entry){
        if(err) {
            console.log(".findByIdAndRemove() error: ");
            console.log(err);
            exp_response.send(".findByIdAndRemove() error. Sorry.");
        } else {
            console.log("Removed entry: ");
            console.log(removed_entry);
            exp_response.redirect("/blogs");
        }
    });
});

app.get("/blogs/:id/edit", function(exp_request, exp_response){
    console.log("GET @ /blogs/" + exp_request.params.id + "/edit"+ ".");
    // Get the existing blog data so we can pre-fill the edit form with it.
    Blog.findById(exp_request.params.id, function(err, found_entry){
        if(err) {
            console.log(".findById() error: ");
            console.log(err);
            exp_response.send(".findById() error. Sorry.");
        } else {
            console.log("Entry found: ");
            console.log(found_entry);
            exp_response.render("edit.ejs", {blog: found_entry});
        }
    });
});

// Tell express to start listening for HTTP requests.
const PORT = 3000;
const IP = "127.0.0.1";
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});