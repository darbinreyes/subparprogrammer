// @flow
// Mongoose is our DB API
const mongoose = require("mongoose");

/*
  Package for implementing authentication involving mongoDB/mongoose e.g.
  storing users+passwords in the DB.
*/
const passportLocalMongoose = require("passport-local-mongoose");

// Define schema for data to be added to the DB.
const UserSchema = mongoose.Schema({
  username: String,
  password: String
});

// Add passport-local-mongoose methods to UserSchema.
UserSchema.plugin(passportLocalMongoose);

/*
  "users" will show up in
  "mongo shell>>> use yelpnutritionv12; show collections"
  "mongo shell>>> db.users.find()" will display all DB entries.
  export the DB model.
*/
module.exports = mongoose.model("User", UserSchema);