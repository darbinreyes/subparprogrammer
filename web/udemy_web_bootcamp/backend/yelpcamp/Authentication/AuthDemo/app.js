// Express is our HTTP server.
const express = require("express");
// Mongoose is our DB API.
const mongoose = require("mongoose");

// We need body-parser for easy access to form data provided in the body of an POST
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser");


/** Authentication related requires() START **/
const passport = require("passport"); // Authentication API
const LocalStrategy = require("passport-local"); // "local" authentication strategy.
const passportLocalMongoose = require("passport-local-mongoose"); // authentication related to mongoose.
const expressSession = require("express-session"); // Used by express for client session API (client state).
/** Authentication related require() END **/


/** Mongoose setup START **/
// "auth_demo_app" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/auth_demo_app", {useNewUrlParser: true, useUnifiedTopology: true});
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
// "Two more lines we need to get setup and then we can start working on the routes" // Code along pt.2.
passport.serializeUser(User.serializeUser()); // User.serializeUser() comes from ./models/user.js->UserSchema.plugin(passportLocalMongoose);
passport.deserializeUser(User.deserializeUser());
/** passport setup END **/


// Route handlers
app.get("/", function (exp_request, exp_response) {
  console.log("GET @ /.");
  exp_response.render("home.ejs");
});

app.get("/secret", function (exp_request, exp_response) {
  console.log("GET @ /secret.");
  exp_response.render("secret.ejs");
});

app.get("/register", function(exp_request, exp_response){
  console.log("GET @ /register.");
  exp_response.render("register.ejs");
});

app.post("/register", function(exp_request, exp_response){
  console.log("POST @ /register.");
  console.log("exp_request.body = " + exp_request.body.username + "/" + exp_request.body.password);
  /*
    Register a new user. Passport does all the work behind the scenes to ensure
    passwords are not stored in the DB in plain text.
  */
  /*
    !!! - Looks like the password is POST'ed in plain text unless the connection
    is over HTTPS. Assuming with HTTPS the password is in the body and the body
    is encrypted on route to the server. - CORRECT, NOT encrypted - see evernote.
  */
  User.register(
    new User({username: exp_request.body.username}),
    exp_request.body.password,
    function(err, registeredUser){
      if(err) {
        console.log("User.register() error: ");
        console.log(err);
        //exp_response.send(".register() failed, sorry.");
        // NOTE the use of "return" here, this is new and is probably important.
        // TODO: Does it work without a return here?
        return exp_response.render("/register");
      } else {
        console.log("User.register() successful: ");
        console.log(registeredUser);
        // "At some point passport.authenticate() calls User.serializeUser()."
        // FYI: "local" strategy can be swapped with "twitter". - Code ALong pt.3.
        // "This actually logs in the user"
        /*
          req and resp are nested exp_request and exp_response ???
          ANS: no, exp_request and exp_response are the same as above, we are
          passing them as arguments to passport.authenticate("local")();
        */
        passport.authenticate("local")(exp_request, exp_response, function(){
           exp_response.redirect("/secret");
        });

      }
    });

});

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Hay relax guy! Kraft dinner. Look over there.");
});