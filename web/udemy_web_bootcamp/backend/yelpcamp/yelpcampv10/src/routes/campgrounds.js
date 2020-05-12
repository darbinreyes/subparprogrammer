// @flow
// Express is our HTTP server.
const express = require("express");
// This is how we can export our routes into app.js.
const router = express.Router();

const Nutrition = require("../models/nutrition");
const Comment = require("../models/comment");

// Middleware for the preventing access to a page unless a user is logged in.
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

// Add a GET request handler for /campgrounds.
router.get("/", function (exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);
  // Display the nutritions array obtained from the DB.
  Nutrition.find({}, function(err, nutritions) {
    if(err) {
      console.log("DB.find() failed: ");
      console.log(err);
    } else {
      console.log("DB.find() successful. Found " + nutritions.length + " entries.");
      exp_response.render("campgrounds/index.ejs", {nutritions: nutritions});
    }
  });
});

router.post("/", isLoggedIn, function (exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);
  // Get form data specifying what will be added.
  // Add new entry to DB.
  // redirect to /campgrounds.
  var entryName = exp_request.body.name;
  var entryImage = exp_request.body.image;
  var entryEnergy = exp_request.body.energy;
  var entryDescription = exp_request.body.description;
  var author = {id: exp_request.user._id, username: exp_request.user.username}

  var newEntry = new Nutrition({
    name: entryName,
    image: entryImage,
    energy: entryEnergy,
    description: entryDescription,
    author: author
  });

  newEntry.save(function(err, entry) {
    if(err) {
      console.log("Failed to add new entry: ");
      console.log(err);
    } else {
      console.log("New entry added successfully: ");
    }
    // Redirect upon completion of DB.save() otherwise the new entry may not
    // be visible if we redirect before the save completes.
    exp_response.redirect("/campgrounds");
  });

});

router.get("/new", isLoggedIn, function (exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);
  // Show the form for adding a new entry to the DB.
  exp_response.render("campgrounds/new.ejs");
});

router.get("/:id", function(exp_request, exp_response) {
  // Example valid ID: 5e878925d90bb0b95ec6bf14, string, 24 chars.
  console.log(exp_request.method + " @ " + exp_request.originalUrl);

  /*
    TODO/FYI: App crashes/hits and error when ID argument below is invalid
    per above.
  */

  /*
    Show the details of the DB entry with given ID. Recall the populate()
    fetches data for a DB association that is referenced instead of
    embedded.
  */
  Nutrition.findById(exp_request.params.id).populate("comments").exec(function(err, entry) {
    if(err) {
      console.log("findById() failed: ");
      console.log(err);
    } else {
      console.log("findById() successful. Entry: ");
      exp_response.render("campgrounds/show.ejs", {entry: entry});
    }
  });
});

// Edit route - GET the edit form
router.get("/:id/edit", checkCampgroundOwnership, function(exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);
  /*
    Get the details of the DB entry with given ID. So we can prefill the edit
    form.
  */
  Nutrition.findById(exp_request.params.id, function(err, entry) {
    if(err) {
      console.log("findById() failed: ");
      console.log(err);
      exp_response.send(".findById() error. Sorry.");
    } else {
      console.log("findById() successful. Entry: ");
      exp_response.render("campgrounds/edit.ejs", {entry: entry});
    }
  });

});

// Update route - PUT to execute and save an edit
router.put("/:id", checkCampgroundOwnership, function(exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);

  // Save the edited/updated/modified DB entry.
  exp_request.body.entry.name = exp_request.sanitize(exp_request.body.entry.name);
  exp_request.body.entry.image = exp_request.sanitize(exp_request.body.entry.image);
  exp_request.body.entry.description = exp_request.sanitize(exp_request.body.entry.description);
  exp_request.body.entry.energy = exp_request.sanitize(exp_request.body.entry.energy);
  // Update the DB entry and redirect to its show page.
  Nutrition.findByIdAndUpdate(exp_request.params.id, exp_request.body.entry, function(err, updated_entry) {
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

// Delete the DB entry specified by id.
router.delete("/:id", checkCampgroundOwnership, function(exp_request, exp_response) {
  console.log(exp_request.method + " @ " + exp_request.originalUrl);

  // Delete the DB entry.
  Nutrition.findByIdAndRemove(exp_request.params.id, function(err, removed_entry) {
    if(err) {
      console.log(".findByIdAndRemove() error: ");
      console.log(err);
      exp_response.send(".findByIdAndRemove() error. Sorry.");
    } else {
      console.log("Removed entry: ");
      /*
      Delete every comment associated with this DB entry. The guy didn't
      implement this. I did.
      */
      removed_entry.comments.forEach(function(currentValue, index, array) {
        Comment.findByIdAndRemove(currentValue, function(err, removed_comment) {
            if(err) {
              console.log("comment .findByIdAndRemove() error: ");
              console.log(err);
            } else {
              console.log("Associated comment deleted.");
            }
        });
      }); // forEach
      exp_response.redirect("/campgrounds");
    }
  });
});

module.exports = router;
