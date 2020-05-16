// @flow
// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const nutritionSchema = mongoose.Schema({
    name: String,
    image: String,
    energy: Number,
    description: String,
    // User association by reference.
    author: {
      id: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "User"
      },
      username: String
    },
    // Comment association by reference
    comments: [{type: mongoose.Schema.Types.ObjectId, ref: "Comment"}]
});

/*
  "nutritions" will show up in
  "mongo shell>>> use yelpnutritionv12; show collections"
  "mongo shell>>> db.nutritions.find()" will display DB entries.
  export the DB model
*/
module.exports = mongoose.model("Nutrition", nutritionSchema);