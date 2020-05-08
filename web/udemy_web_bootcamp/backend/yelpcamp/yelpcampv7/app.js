// Express is our HTTP server.
const express = require("express");
// We need body-parser for easy access to form data provided in the body of an POST
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser");
// Mongoose is our DB API.
const mongoose = require("mongoose");

/** Authentication related requires() START **/
const passport = require("passport"); // Authentication API
const LocalStrategy = require("passport-local"); // "local" authentication strategy.
//const passportLocalMongoose = require("passport-local-mongoose"); // authentication related to mongoose.
const expressSession = require("express-session"); // Used by express for client session API (client state).
/** Authentication related require() END **/


/** Mongoose setup START **/
// "yelpnutritionv7" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/yelpnutritionv7", {useNewUrlParser: true, useUnifiedTopology: true});

const seedDB = require("./seedDB");
seedDB();
const User = require("./models/user");
/** Mongoose setup END **/

/** Express setup START **/
const app = express();

app.use(express.static("public")); // Tell express where to look for e.g. CSS files and images.

app.use(expressSession( // Tell express to use express-session
{
secret: "Cartman's mom is a dirty whore.", // Configure express-session. How to hash passwords.
resave: false,
saveUninitialized: false
}));
app.use(passport.initialize()); // Tell express to use passport step 1
app.use(passport.session()); // Tell express to use passport step 2

// Enable x-www-form-urlencoded in body-parser. Tell express to use body-parser.
app.use(bodyParser.urlencoded({extended: true}));
/** Express setup END **/

/** passport setup START **/
passport.use(
new LocalStrategy(User.authenticate())
);// This is a line added in as part of the POST @ /login to implement the user login function. See code along pt. 4. Tell passport to "for the local strategy use that method for the User.authenticate()"
// "Two more lines we need to get setup and then we can start working on the routes" // Code along pt.2.
passport.serializeUser(User.serializeUser()); // User.serializeUser() comes from ./models/user.js->UserSchema.plugin(passportLocalMongoose);
passport.deserializeUser(User.deserializeUser());
/** passport setup END **/

// "our own little middleware" - this is makes it so that the object describing a user is passed in to all .ejs files.
// This is how we can implement hiding/showing of the login/sign-up/logout links in the navbar based on whether or not the user is logger in. It also allows us to display the name of the currently logged in user in the navbar.
// This is really express setup but I'm pretty sure this line must occur after passport setup.
app.use(function(req, resp, next){
  resp.locals.currentUser = req.user;
  next();
});

commentRoutes = require("./routes/comments");
campgroundRoutes = require("./routes/campgrounds");
indexRoutes = require("./routes/index");

app.use("/campgrounds/:id/comments", commentRoutes);
app.use("/campgrounds", campgroundRoutes);
app.use("/", indexRoutes);

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});