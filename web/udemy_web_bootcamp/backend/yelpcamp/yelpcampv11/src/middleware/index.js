// @

/*
  Not sure why but flow is forcing me to add type annotations here.
  So I removed the flow flag above.
*/
const Nutrition = require("../models/nutrition");
const Comment = require("../models/comment");

var middlewareObj = {};

// Middleware for the preventing access to a page unless a user is logged in.
function isLoggedIn(req, resp, next) { // next = next thing that needs to be called
  console.log("isLoggedIn() middleware.");
  if(req.isAuthenticated()) { // If logged in successfully. This is a passport method.
    console.log(".isAuthenticated().");
    return next(); // "move on to the next middleware"
  }
  // else, login failed.
  console.log("NOT .isAuthenticated().");
  req.flash("error", "You must be logged in to do that brah.");
  resp.redirect("/login");
}

function checkCampgroundOwnership(req, resp, next) {
  console.log("checkCampgroundOwnership() middleware.");
  /*
    If user is logged in and user is the owner of the campground then move on
    to the next middleware. Otherwise redirect them to where they came from.
  */
  if(req.isAuthenticated()) {
    // Fetch the DB entry, the author is contained in it.
    Nutrition.findById(req.params.id, function(err, entry) {
      if(err) {
        console.log("findById() failed: ");
        console.log(err);
        // resp.send(".findById() error. Sorry.");
        req.flash("error", "findById() error. Sorry.");
        req.redirect("back");
      } else {
        console.log("findById() successful. Entry: ");
        // Test ownership.
        if(req.user._id.equals(entry.author.id)) {
          next(); // Move on to next middleware
        } else {
          //resp.send("You are not the owner. The owner is " + entry.author.username + " you are " + req.user.username + ".");
          req.flash("error", "You are not the owner. The owner is " + entry.author.username + " you are " + req.user.username + ".");
          resp.redirect("/campgrounds/" + req.params.id);
        }
      }
    });
  } else {
    //resp.send("You must be logged in, sorry."); // alternative: resp.redirect("back")
    req.flash("error", "You must be logged in to do that brah.");
    resp.redirect("/login");
  }
}


/*
  Middleware for the preventing access to "/campgrounds/:id/comments/new"
  unless a user is logged in. Also, see below post @ /login.
*/
// function isLoggedIn(req, resp, next){ // next = next thing that needs to be called.
//   console.log("isLoggedIn() middleware.");

//   if(req.isAuthenticated()) { // If logged in successfully. This is a passport method.
//     console.log(".isAuthenticated().");
//     return next(); // "move on to the next middleware"
//   }
//   // else, login failed.
//   console.log("NOT .isAuthenticated().");
//   resp.redirect("/login");
// }

function checkCommentOwnership(req, resp, next) {
  console.log("checkCommentOwnership() middleware.");
  /*
    If user is logged in and user is the owner of the comment then move on
    to the next middleware. Otherwise redirect them to where they came from.
  */
  if(req.isAuthenticated()) {
    // Fetch the DB entry, the author is contained in it.
    Comment.findById(req.params.cid, function(err, entry) {
      if(err) {
        console.log("findById() failed: ");
        console.log(err);
        //resp.send(".findById() error. Sorry.");
        req.flash("error", "findById() error. Sorry.");
        req.redirect("back");
      } else {
        console.log("findById() successful. Entry: ");
        // Test ownership.
        if(req.user._id.equals(entry.author.id)) {
          next(); // Move on to next middleware
        } else {
          //resp.send("You are not the owner. The owner is " + entry.author.username + " you are " + req.user.username + ".");
          req.flash("error", "You are not the owner. The owner is " + entry.author.username + " you are " + req.user.username + ".");
          resp.redirect("/campgrounds/" + req.params.id);
        }
      }
    });
  } else {
    //resp.send("You must be logged in, sorry."); // alternative: resp.redirect("back")
    req.flash("error", "You must be logged in to do that brah.");
    resp.redirect("/login");
  }
}

middlewareObj.isLoggedIn = isLoggedIn;
middlewareObj.checkCampgroundOwnership = checkCampgroundOwnership;
middlewareObj.checkCommentOwnership = checkCommentOwnership;

module.exports = middlewareObj;
