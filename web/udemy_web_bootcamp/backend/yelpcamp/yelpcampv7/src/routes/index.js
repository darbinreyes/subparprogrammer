// Express is our HTTP server.
const express = require("express");
const router = express.Router(); // This is how we can export our routes into app.js

const User = require("../models/user");

const passport = require("passport"); // Authentication API

// Add a GET request handler for /.
router.get("/", function (exp_request, exp_response) {
    console.log("GET @ /.");
    exp_response.render("landing.ejs");
});

// Auth. Routes.

router.get("/register", function(exp_request, exp_response) {
  console.log("GET @ /register.");
  exp_response.render("register.ejs");
});

router.post("/register", function(exp_request, exp_response){
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
        // NOTE the use of "return" here, this is new and is important.
        return exp_response.redirect("/register");
      }
      // This is the "middleware" pattern ostensibly.
      console.log("User.register() successful: ");
      //console.log(registeredUser);
      // "At some point passport.authenticate() calls User.serializeUser()."
      // FYI: "local" strategy can be swapped with e.g. "twitter". - Code ALong pt.3.
      // "This actually logs in the user"
      /*
        FYI: exp_request and exp_response are the same as above, we are
        passing them as arguments to passport.authenticate("local")();
      */
      passport.authenticate("local")(exp_request, exp_response, function(){
         // Login the user and take user to /secret page upon successful registration
         exp_response.redirect("/campgrounds");
      });
    });

});

router.get("/login", function(exp_request, exp_response){
  console.log("GET @ /login.");
  exp_response.render("login.ejs");
});

// The call to passport.authenticate() here is called "middleware".
// Middleware = code that runs  before our final route callback. Can be "stacked up".
router.post("/login",
  passport.authenticate("local", {successRedirect: "/campgrounds", failureRedirect: "/login"}),
  function(exp_request, exp_response){

  console.log("POST @ /login.");
  exp_response.send("Nothing like a nice Kraft Dinner.");
});

router.get("/logout", function(exp_request, exp_response){
  console.log("GET @ /logout.");
  exp_request.logout(); // This method is from passport, it destroys the user's session. // Logs out the user. // How does this function know which user to log out? ANS: The user info is inside exp_request.
  //exp_response.send("I logged you out guy.");
  exp_response.redirect("/campgrounds");
});

module.exports = router;