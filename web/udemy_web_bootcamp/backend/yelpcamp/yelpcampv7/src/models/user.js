// Mongoose is our DB API
const mongoose = require("mongoose");
const passportLocalMongoose = require("passport-local-mongoose");

// Define schema for data to be added to the DB.
const UserSchema = mongoose.Schema({
  username: String,
  password: String
});

UserSchema.plugin(passportLocalMongoose); // Add passport-local-mongoose methods to UserSchema.

// "users" will show up in "mongoose shell>>> use yelpnutritionv6; show collections"
// "mongoose shell>>> db.users.find()" will display all DB entries.
// export the DB model.
module.exports = mongoose.model("User", UserSchema);