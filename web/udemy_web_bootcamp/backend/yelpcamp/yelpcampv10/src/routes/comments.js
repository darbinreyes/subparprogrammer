// @flow

// Express is our HTTP server.
const express = require("express");
// This is how we can export our routes into app.js the mergeParams argument is
// required here because in app.js, we have a route param in the app.use()
// prefix.
const router = express.Router({mergeParams: true});

const Nutrition = require("../models/nutrition");
const Comment = require("../models/comment");

// Middleware for the preventing access to "/campgrounds/:id/comments/new"
// unless a user is logged in. Also, see below post @ /login.
function isLoggedIn(req, resp, next){ // next = next thing that needs to be called
  console.log("isLoggedIn() middleware.");
  if(req.isAuthenticated()) { // If logged in successfully. This is a passport method.
    console.log(".isAuthenticated().");
    return next(); // "move on to the next middleware"
  }
  // else, login failed.
  console.log("NOT .isAuthenticated().");
  resp.redirect("/login");
}

function checkCommentOwnership(req, resp, next) {
  console.log("checkCommentOwnership() middleware.");
  // if user is logged in and user is the owner of the comment then move on
  // to the next middleware. Otherwise redirect them to where they came from.
  if(req.isAuthenticated()) {
    // Fetch the DB entry, the author is contained in it.
    Comment.findById(req.params.cid, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
            resp.send(".findById() error. Sorry.");
        } else {
            console.log("findById() successful. Entry: ");
            // Test ownership.
            if(req.user._id.equals(entry.author.id)) {
              next(); // Move on to next middleware
            } else {
              resp.send("You are not the owner. The owner is " + entry.author.username + " you are " + req.user.username + ".");
            }
        }
    });
  } else {
    resp.send("You must be logged in, sorry."); // alternative: resp.redirect("back")
  }
}


// The use of isLoggedIn() here is "middleware" that prevents access to the new
// comment form unless a user is logged in. It redirects to the /login page if
// the user is not logged in.
router.get("/new", isLoggedIn, function(exp_request, exp_response){
    // Form for adding a comment.
    console.log(exp_request.method + " @ " + exp_request.originalUrl);
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            exp_response.render("comments/new.ejs", {entry: entry});
        }
    });
});

// The use of isLoggedIn() here is "middleware" that prevents a direct POST
// (e.g. using POSTman or curl) to /campgrounds/:id/comments unless the user is
// logged in. It redirects to the /login page if the user is not logged in.
router.post("/", isLoggedIn, function(exp_request, exp_response){
    console.log("POST @ /camgrounds/" + exp_request.params.id + "/comments");
    // Add a new comment to the DB entry with the specified ID.
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");

            Comment.create(exp_request.body.comment, function(err, created_comment){
                if(err){
                    console.log("create() error: ");
                    console.log(err);
                } else {
                    console.log("create() successful: ");
                    //console.log(exp_request.user);
                    //console.log(created_comment);
                    created_comment.author.id = exp_request.user._id;
                    created_comment.author.username = exp_request.user.username;
                    //console.log(created_comment);
                    // YOU CREATED A NEW COMMENT BUT SINCE YOU MODIFIED IT BY
                    // ADDING id and username you must save it! DONT FORGET TO
                    // SAVE THE COMMENT AFTER
                    // He doesn't use callback here.
                    created_comment.save(); // SAVE IT!
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

// Edit comment route - GET the edit form
router.get("/:cid/edit", checkCommentOwnership, function(exp_request, exp_response) {
    console.log(exp_request.method + " @ " + exp_request.originalUrl);


    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            //exp_response.render("comments/edit.ejs", {entry: entry});
            // Get the details of the DB entry with given ID. So we can prefill the edit
            // form.
            Comment.findById(exp_request.params.cid, function(err, comment_entry) {
                if(err) {
                    console.log("findById() failed: ");
                    console.log(err);
                    exp_response.send(".findById() error. Sorry.");
                } else {
                    console.log("findById() successful. Entry: ");
                    exp_response.render("comments/edit.ejs", {entry: entry, comment_entry: comment_entry});
                }
            });
        }
    });


});

// Update comment route - PUT to execute and save an edit
router.put("/:cid", checkCommentOwnership, function(exp_request, exp_response) {
    console.log(exp_request.method + " @ " + exp_request.originalUrl);

    // Save the edited/updated/modified DB comment entry.
    exp_request.body.comment.text = exp_request.sanitize(exp_request.body.comment.text);

    // Update the comment DB entry and redirect to its show page.
    Comment.findByIdAndUpdate(exp_request.params.cid, exp_request.body.comment, function(err, updated_comment_entry){
        if(err) {
            console.log(".findByIdAndUpdate() error: ");
            console.log(err);
            exp_response.send(".findByIdAndUpdate() error. Sorry.");
        } else {
            console.log("Updated entry: ");
            exp_response.redirect("/campgrounds/" + exp_request.params.id);
        }
    });
});

router.delete("/:cid", checkCommentOwnership, function(exp_request, exp_response) {
    console.log(exp_request.method + " @ " + exp_request.originalUrl);

    // Delete the specified comment. In addition to deleting the DB entry
    // corresponding to a comment we probably need to remove the association in
    // the DB.comments array.
    Nutrition.findById(exp_request.params.id, function(err, entry){
        if(err) {
            console.log(".findById() error: ");
            console.log(err);
            exp_response.send(".findById() error. Sorry.");
        } else {
            console.log("found entry: ");
            // Delete from entry.comments the comment association for the
            // comment being deleted.
            entry.comments.forEach(function(currentValue, index, array) {
                if(currentValue.equals(exp_request.params.cid)) {
                    console.log("Comment id match");
                    array.splice(index, 1); // Remove from comments array.
                    entry.save(); // Save updated DB entry.
                    // Delete the comment itself from the DB.
                    Comment.findByIdAndRemove(currentValue, function(err, removed_comment){
                        if(err) {
                            console.log("comment .findByIdAndRemove() error: ");
                            console.log(err);
                            exp_response.send("comment .findByIdAndRemove() error.");
                        } else {
                            console.log("Associated comment deleted.");
                            exp_response.redirect("/campgrounds/" + exp_request.params.id);
                        }
                    });
                    return;
                }
            }); // forEach
        }
    });
});

module.exports = router;