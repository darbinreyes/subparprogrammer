// @flow
// Express is our HTTP server.
const express = require("express");
// This is how we can export our routes into app.js
const router = express.Router();

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

      /* "At some point passport.authenticate() calls User.serializeUser()."
        FYI: "local" strategy can be swapped with e.g. "twitter". Secret page
        code along pt.3. "This actually logs in the user" */

      /*
        FYI: exp_request and exp_response are the same as above, we are
        passing them as arguments to passport.authenticate("local")();
      */
      passport.authenticate("local")(exp_request, exp_response, function(){
         /* Successfully registered. Login the user and redirect
         them to a page that is appropriate after registration. */
         exp_response.redirect("/campgrounds");
      });
    });

});

router.get("/login", function(exp_request, exp_response){
  console.log("GET @ /login.");
  exp_response.render("login.ejs"); // Show login form.
});

/* The call to passport.authenticate() here is called "middleware".
Middleware = "code that runs  before our final route callback". Middleware can be
"stacked up". */
router.post("/login", // This route logs in a user and establishes a session.
  passport.authenticate("local", {successRedirect: "/campgrounds", failureRedirect: "/login"}),
  function(exp_request, exp_response){

  console.log("POST @ /login.");
  exp_response.send("Theres nothing like a nice Kraft Dinner after a hard day's work.");
});

router.get("/logout", function(exp_request, exp_response){
  console.log("GET @ /logout.");
  /* This method is from passport, it destroys the user's session. // Logs out
  the user. // How does this function know which user to log out? ANS: The user
  info is inside exp_request. */
  exp_request.logout();
  exp_response.redirect("/campgrounds");
});

module.exports = router;