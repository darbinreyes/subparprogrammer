// Express is our HTTP server.
const express = require("express");
const router = express.Router({mergeParams: true}); // This is how we can export our routes into app.js

const Nutrition = require("../models/nutrition");
const Comment = require("../models/comment");

// Middleware (see below post@/login) for the preventing access to /campgrounds/:id/comments/new unless the user is logged in.

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

//
// ==================== Comment Routes ======================
//
// The use of isLoggedIn here is "middleware" that prevents access to the new comment form unless the user is logged in. It redirects to the /login page if the user is not logged in.
router.get("/new", isLoggedIn, function(exp_request, exp_response){
    // Form for adding a comment.
    console.log("GET @ /camgrounds/" + exp_request.params.id + "/comments/new");
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
           // console.log(entry);
            exp_response.render("comments/new.ejs", {entry: entry});
        }
    });
});

// The use of isLoggedIn here is "middleware" that prevents a direct POST(e.g. using POSTman or curl) to /campgrounds/:id/comments unless the user is logged in. It redirects to the /login page if the user is not logged in.
router.post("/", isLoggedIn, function(exp_request, exp_response){
    console.log("POST @ /camgrounds/" + exp_request.params.id + "/comments");
    // Add a new comment to the DB entry with the specified ID.
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            //console.log(entry);
            Comment.create(exp_request.body.comment, function(err, created_comment){
                if(err){
                    console.log("create() error: ");
                    console.log(err);
                } else {
                    console.log("create() successful: ");
                    //console.log(created_comment);
                    console.log("pushing() comment: ");
                    entry.comments.push(created_comment);
                    entry.save(function(err, saved_entry){
                        if(err) {
                            console.log("save() error: ");
                            console.log(err);
                        } else {
                            console.log("save() successful: ");
                            exp_response.redirect("/campgrounds/" + exp_request.params.id);
                        }
                    });
                }
            });
        }
    });
});

module.exports = router;