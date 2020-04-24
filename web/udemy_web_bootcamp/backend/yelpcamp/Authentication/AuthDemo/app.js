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
passport.use(
new LocalStrategy(User.authenticate())
);// This is a line added in as part of the POST @ /login to implement the user login function. See code along pt. 4. Tell passport to "for the local strategy use that method for the User.authenticate()"
// "Two more lines we need to get setup and then we can start working on the routes" // Code along pt.2.
passport.serializeUser(User.serializeUser()); // User.serializeUser() comes from ./models/user.js->UserSchema.plugin(passportLocalMongoose);
passport.deserializeUser(User.deserializeUser());
/** passport setup END **/


// Route handlers
app.get("/", function (exp_request, exp_response) {
  console.log("GET @ /.");
  exp_response.render("home.ejs");
});

// Middleware (see below post@/login) for the preventing access to /secret unless the user is logged in.

function isLoggedIn(req, resp, next){  // next = next thing that needs to be called
  console.log("isLoggedIn() middleware.");
  if(req.isAuthenticated()) { // if logged in successfully // This is a passport method.
    console.log(".isAuthenticated().");
    return next(); // "move on to the next middleware"
  }
  // else, login failed.
  console.log("NOT .isAuthenticated().");
  resp.redirect("/login");
}

app.get("/secret", isLoggedIn, function (exp_request, exp_response) { // The function isLoggedIn is called "middleware".
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
        // This should be a redirect? or render("register.ejs");
        //return exp_response.render("/register"); // FYI this hangs upon error, e.g. if a you try registering the same username 2x: "UserExistsError".
        return exp_response.redirect("/register"); // FYI this fixes the hang, I think that was my typo. Oops.
        //return exp_response.render("register.ejs"); // FYI this works too, the guy uses this but I prefer redirect because you see a page-reload+console.log(GET @ /register).
      }
      //else { // Not needed due to return statement above. This is the "middleware" pattern ostensibly.
      console.log("User.register() successful: ");
      console.log(registeredUser);
      // "At some point passport.authenticate() calls User.serializeUser()."
      // FYI: "local" strategy can be swapped with e.g. "twitter". - Code ALong pt.3.
      // "This actually logs in the user"
      /*
        req and resp are nested exp_request and exp_response ???
        ANS: no, exp_request and exp_response are the same as above, we are
        passing them as arguments to passport.authenticate("local")();
      */
      passport.authenticate("local")(exp_request, exp_response, function(){
         // Login the user and take user to /secret page upon successful registration
         exp_response.redirect("/secret");
      });
      //} // else
    });

});

app.get("/login", function(exp_request, exp_response){
  console.log("GET @ /login.");
  exp_response.render("login.ejs");
});

// The call to passport.authenticate() here is called "middleware".
// Middleware = code that runs  before our final route callback. Can be "stacked up".
app.post("/login",
  passport.authenticate("local", {successRedirect: "/secret", failureRedirect: "/login"}),
  function(exp_request, exp_response){

  console.log("POST @ /login.");
  exp_response.send("Nothing like a nice Kraft Dinner.");
});

app.get("/logout", function(exp_request, exp_response){
  console.log("GET @ /logout.");
  exp_request.logout(); // This method is from passport, it destroys the user's session. // Logs out the user. // How does this function know which user to log out? ANS: The user info is inside exp_request.
  exp_response.send("I logged you out guy.");
});

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Hay relax guy! Kraft dinner. Look over there.");
});