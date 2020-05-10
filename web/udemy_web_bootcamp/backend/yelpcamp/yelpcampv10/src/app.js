// @flow

/**
// Example of "flow code".
function foo(x: ?number): string {
  if (x) {
    return x;
  }
  return "default string";
}
**/

// Express is our HTTP server.
const express = require("express");

/* We need body-parser for easy access to form data provided in the body of a
POST request that is formatted in x-www-form-urlencoded */
const bodyParser = require("body-parser");

// Mongoose is our DB API based on the mongo DB.
const mongoose = require("mongoose");

// method-override allows us to work-around the fact that HTML forms only
// support method=POST or GET.
const methodOverride = require('method-override');
// We use express-sanitizer to remove e.g. script tags from user text inputs.
const expressSanitizer = require("express-sanitizer");

/************* Authentication related requires() START **/
// Our main authentication package.
const passport = require("passport");
// Passport's "local" authentication "strategy".
const LocalStrategy = require("passport-local");

/* Used by express for client session API (client state). Keeps track of when a
user is currently logged in. */
const expressSession = require("express-session");
/************* Authentication related requires() END **/



/************* Mongoose setup START **/
// "yelpnutritionv10" will appear in "mongo shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/yelpnutritionv10", {useNewUrlParser: true, useUnifiedTopology: true});

/* Deletes everything in the DB, except for users, then adds some initial DB
entries. */
const seedDB = require("./seedDB");
seedDB();

const User = require("./models/user"); // mongoose model for Users.
/************* Mongoose setup END **/



/************* Express setup START **/
const app = express();
/* Tell express where to look for e.g. CSS files and images. */
app.use(express.static("public"));

app.use(expressSession( // Tell express to use express-session
{ // Configure express-session. Tell it how to hash passwords.
  secret: "Cartman's mom is a dirty whore.",
  resave: false,
  saveUninitialized: false
  }));

app.use(passport.initialize()); // Tell express to use passport step 1
app.use(passport.session()); // Tell express to use passport step 2

/* Enable x-www-form-urlencoded in body-parser. Tell express to use
body-parser. */
app.use(bodyParser.urlencoded({extended: true}));

// Tell Express to use the method-override package. This configuration of
// method-override looks for a POST request with a URL query parameter
// _method=PUT and turns that POST into a PUT request within Express.
app.use(methodOverride('_method'));
// IMPORTANT: express-sanitizer app.use() should go AFTER body-parser above.
app.use(expressSanitizer());
/************* Express setup END **/

/************* passport setup START **/

/* This is a line added in as part of the POST @ /login to implement the user
login function. See secret page code along pt. 4. Tell passport to "for the local strategy
use that method for the User.authenticate()" */
passport.use(
  new LocalStrategy(User.authenticate())
  );

/* "Two more lines we need to get setup and then we can start working on the
routes". Secret page code along pt.2. User.serializeUser() comes from
./models/user.js->UserSchema.plugin(passportLocalMongoose); */
passport.serializeUser(User.serializeUser());
passport.deserializeUser(User.deserializeUser());
/************* passport setup END **/

/*
"our own little middleware" - this is makes it so that the object describing
a user is passed in to all .ejs files. This is how we can implement
hiding/showing of the login/sign-up/logout links in the navbar based on whether
or not the user is logger in. It also allows us to display the name of the
currently logged in user in the navbar. This is really express setup but I'm
pretty sure this line must occur after passport setup. Without this we would
have to pass req.user to exp_response.render() almost every time it is called in
a route.*/
app.use(function(req, resp, next){
  resp.locals.currentUser = req.user; // See "currentUser" in header.ejs.
  next();
});

/* require the routes. */
var commentRoutes = require("./routes/comments");
var campgroundRoutes = require("./routes/campgrounds");
var indexRoutes = require("./routes/index");

/* Instead of "app.use(commentRoutes);"" we can tell express to prefix the
routes with the string provided in the first argument. This way we avoid errors
caused by a mistyped route path string. Note that if a route parameter like
":id" occurs in this prefix you must use "express.Router({mergeParams: true});".
See routes/comments.js. */
app.use("/campgrounds/:id/comments", commentRoutes);
app.use("/campgrounds", campgroundRoutes);
app.use("/", indexRoutes);

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});