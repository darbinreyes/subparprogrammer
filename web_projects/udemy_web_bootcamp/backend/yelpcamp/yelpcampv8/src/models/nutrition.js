// @flow
// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const nutritionSchema = mongoose.Schema({
    name: String,
    image: String,
    energy: Number,
    description: String,
    // Comment association by reference
    comments: [{type: mongoose.Schema.Types.ObjectId, ref: "Comment"}]
});

// "nutritions" will show up in "mongo shell>>> use yelpnutritionv8; show collections"
// "mongo shell>>> db.nutritions.find()" will display DB entries.
// export the DB model
module.exports = mongoose.model("Nutrition", nutritionSchema);