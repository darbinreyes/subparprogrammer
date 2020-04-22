// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const UserSchema = mongoose.Schema({
    username: String,
    password: String
});

// "users" will show up in "mongoose shell>>> use auth_demo_app; show collections"
// "mongoose shell>>> db.users.find()" will display DB entries.
// Get an instance of the DB for the given schema.
module.exports = mongoose.model("User", UserSchema);