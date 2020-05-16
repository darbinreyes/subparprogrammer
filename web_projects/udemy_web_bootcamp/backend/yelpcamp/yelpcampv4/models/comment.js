// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const commentSchema = mongoose.Schema({
    text: String,
    author: String
});

// "comments" will show up in "mongoose shell>>> use yelpnutritionv3; show collections"
// "mongoose shell>>> db.comments.find()" will display DB entries.
// Get an instance of the DB for the given schema.
module.exports = mongoose.model("Comment", commentSchema);