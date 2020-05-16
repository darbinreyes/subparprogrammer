// @flow
// Express is our HTTP server.
const express = require("express");
// This is how we can export our routes into app.js
const router = express.Router();

const Nutrition = require("../models/nutrition");

// Add a GET request handler for /campgrounds.
router.get("/", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds.");
    // Display the nutritions array obtained from the DB.
    Nutrition.find({}, function(err, nutritions){
        if(err) {
            console.log("DB.find() failed: ");
            console.log(err);
        } else {
            console.log("DB.find() successful. Found " + nutritions.length + " entries.");

            exp_response.render("campgrounds/index.ejs", {nutritions: nutritions});
        }
    });
});

router.post("/", function (exp_request, exp_response){
    console.log("POST @ /campgrounds.");
    // Get form data specifying what will be added.
    // Add new entry to DB.
    // redirect to /campgrounds.
    var entryName = exp_request.body.name;
    var entryImage = exp_request.body.image;
    var entryEnergy = exp_request.body.energy;
    var entryDescription = exp_request.body.description;

    var newEntry = new Nutrition({
        name: entryName,
        image: entryImage,
        energy: entryEnergy,
        description: entryDescription
    });

    newEntry.save(function(err, entry){
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

router.get("/new", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds/new.");
    // Show the form for adding a new entry to the DB.
    exp_response.render("campgrounds/new.ejs");
});

router.get("/:id", function(exp_request, exp_response){
    // Example valid ID: 5e878925d90bb0b95ec6bf14, string, 24 chars.
    console.log("GET @ /camgrounds/" + exp_request.params.id);

    // TODO/FYI: App crashes/hits and error when ID argument below is invalid
    // per above.

    // Show the details of the DB entry with given ID. Recall the populate()
    // fetches data for a DB association that is referenced instead of
    // embedded.
    Nutrition.findById(exp_request.params.id).populate("comments").exec(function(err, entry){
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            exp_response.render("campgrounds/show.ejs", {entry: entry});
        }
    });
});

module.exports = router;
