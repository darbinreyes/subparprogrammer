// @flow

// Express is our HTTP server.
const express = require("express");
/*
  This is how we can export our routes into app.js the mergeParams argument is
  required here because in app.js, we have a route param in the app.use()
  prefix.
*/
const router = express.Router({mergeParams: true});

const Nutrition = require("../models/nutrition");
const Comment = require("../models/comment");
const middleware = require("../middleware");

/*
  The use of isLoggedIn() here is "middleware" that prevents access to the new
  comment form unless a user is logged in. It redirects to the /login page if
  the user is not logged in.
*/
router.get("/new", middleware.isLoggedIn, function(exp_request, exp_response) {
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

/*
  The use of isLoggedIn() here is "middleware" that prevents a direct POST
  (e.g. using POSTman or curl) to /campgrounds/:id/comments unless the user is
  logged in. It redirects to the /login page if the user is not logged in.
*/
router.post("/", middleware.isLoggedIn, function(exp_request, exp_response) {
    console.log(exp_request.method + " @ " + exp_request.originalUrl);
    // Add a new comment to the DB entry with the specified ID.
    Nutrition.findById(exp_request.params.id, function(err, entry) {
      if(err) {
        console.log("findById() failed: ");
        console.log(err);
      } else {
        console.log("findById() successful. Entry: ");

        Comment.create(exp_request.body.comment, function(err, created_comment) {
            if(err){
              console.log("create() error: ");
              console.log(err);
            } else {
              console.log("create() successful: ");
              created_comment.author.id = exp_request.user._id;
              created_comment.author.username = exp_request.user.username;
              /*
                YOU CREATED A NEW COMMENT BUT SINCE YOU MODIFIED IT BY ADDING id
                and username you must save it! DONT FORGET TO SAVE THE COMMENT
                AFTERWARDs. He doesn't use callback here, I do.
              */
              created_comment.save(); // SAVE IT!
              console.log("pushing() comment: ");
              entry.comments.push(created_comment);
              entry.save(function(err, saved_entry) {
                if(err) {
                  console.log("save() error: ");
                  console.log(err);
                } else {
                  console.log("save() successful: ");
                  exp_request.flash("success", "Successfully posted comment.");
                  exp_response.redirect("/campgrounds/" + exp_request.params.id);
                }
              });
            }
        });
      }
    });
});

// Edit comment route - GET the edit form
router.get("/:cid/edit", middleware.checkCommentOwnership, function(exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);

  Nutrition.findById(exp_request.params.id, function(err, entry) {
    if(err) {
      console.log("findById() failed: ");
      console.log(err);
    } else {
      console.log("findById() successful. Entry: ");
      /*
        Get the details of the DB entry with given ID. So we can prefill the
        edit form.
      */
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
router.put("/:cid", middleware.checkCommentOwnership, function(exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);

  // Save the edited/updated/modified DB comment entry.
  exp_request.body.comment.text = exp_request.sanitize(exp_request.body.comment.text);

  // Update the comment DB entry and redirect to its show page.
  Comment.findByIdAndUpdate(exp_request.params.cid, exp_request.body.comment, function(err, updated_comment_entry) {
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

// router.delete("/:cid", checkCommentOwnership, function(exp_request, exp_response) {
//   console.log(exp_request.method + " @ " + exp_request.originalUrl);

//   /*
//     Delete the specified comment. In addition to deleting the DB entry
//     corresponding to a comment we probably need to remove the association in
//     the DB comments array.
//   */
//   Nutrition.findById(exp_request.params.id, function(err, entry) {
//     if(err) {
//       console.log(".findById() error: ");
//       console.log(err);
//       exp_response.send(".findById() error. Sorry.");
//     } else {
//       console.log("found entry: ");
//       /*
//         Delete from entry.comments the comment association for the
//         comment being deleted.
//       */
//       entry.comments.forEach(function(currentValue, index, array) {
//         if(currentValue.equals(exp_request.params.cid)) {
//           console.log("Comment id match");
//           /*
//             Remove from comments array. FYI: It works without this but
//             I'm not sure why. The guy doesn't do this.
//           */
//           array.splice(index, 1);
//           entry.save(); // Save updated DB entry.
//           // Delete the comment itself from the DB.
//           Comment.findByIdAndRemove(currentValue, function(err, removed_comment) {
//             if(err) {
//               console.log("comment .findByIdAndRemove() error: ");
//               console.log(err);
//               exp_response.send("comment .findByIdAndRemove() error.");
//             } else {
//               console.log("Associated comment deleted.");
//               exp_response.redirect("/campgrounds/" + exp_request.params.id);
//             }
//           });
//           return;
//         }
//       }); // forEach
//     }
//   });
// });

/*
  This is a simplified implementation of delete comment above. Apparently
  mongoose is smart enough to delete associations by reference upon deleting the
  comment from the DB.
*/
router.delete("/:cid", middleware.checkCommentOwnership, function(exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);

  /*
    Delete the comment with DB id = cid.
  */
  Comment.findByIdAndRemove(exp_request.params.cid, function(err, removed_comment) {
    if(err) {
      console.log("comment .findByIdAndRemove() error: ");
      console.log(err);
      exp_response.send("comment .findByIdAndRemove() error.");
    } else {
      console.log("Associated comment deleted.");
      exp_request.flash("success", "Comment deleted.");
      exp_response.redirect("/campgrounds/" + exp_request.params.id);
    }
  });
});

module.exports = router;