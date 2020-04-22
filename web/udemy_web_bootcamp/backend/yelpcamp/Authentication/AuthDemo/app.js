// Express is our HTTP server.
const express = require("express");
// Mongoose is our DB API.
const mongoose = require("mongoose");
const passport = require("passport");
const bodyParser = require("body-parser");
const LocalStrategy = require("passport-local");
const passportLocalMongoose = require("passport-local-mongoose");

/** Mongoose setup START **/
// "auth_demo_app" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/auth_demo_app", {useNewUrlParser: true, useUnifiedTopology: true});

//const Nutrition = require("./models/nutrition");

/** Mongoose setup END **/

/** Express setup START **/
const app = express();
app.use(express.static("public")); // Tell express where to look for CSS files.

/** Express setup END **/

// Add a GET request handler for /.
app.get("/", function (exp_request, exp_response) {
    console.log("GET @ /.");
    exp_response.render("home.ejs");
});

app.get("/secret", function (exp_request, exp_response) {
    console.log("GET @ /secret.");
    exp_response.render("secret.ejs");
});

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Hay relax guy! Kraft dinner. Look over there.");
});