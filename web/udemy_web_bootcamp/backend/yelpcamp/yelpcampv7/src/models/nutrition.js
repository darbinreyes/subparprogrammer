// @flow
// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const nutritionSchema = mongoose.Schema({
    name: String,
    image: String,
    energy: Number,
    description: String,
    comments: [{type: mongoose.Schema.Types.ObjectId, ref: "Comment"}]
});

// "nutritions" will show up in "mongoose shell>>> use yelpnutritionv3; show collections"
// "mongoose shell>>> db.nutritions.find()" will display DB entries.
// Get an instance of the DB for the given schema.
module.exports = mongoose.model("Nutrition", nutritionSchema);