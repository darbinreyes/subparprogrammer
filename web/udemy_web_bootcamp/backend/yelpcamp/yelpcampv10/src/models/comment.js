// @flow
// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const commentSchema = mongoose.Schema({
    text: String,
    author: {
      id: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "User"
      },
      username: String
    }
});

// "comments" will show up in "mongo shell>>> use yelpnutritionv9; show collections"
// "mongo shell>>> db.comments.find()" will display DB entries.
// export the DB model
module.exports = mongoose.model("Comment", commentSchema);