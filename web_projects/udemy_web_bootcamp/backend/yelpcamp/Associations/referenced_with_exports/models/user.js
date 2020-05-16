// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const userSchema = mongoose.Schema({
    name: String,
    email: String,
    posts: [{type: mongoose.Schema.Types.ObjectId, ref: "Blog"}] // IMPORTANT! The value of ref here should === value of first argument to .model() above otherwise, below, .populate("posts").exec() will error out.
});

// "users" will show up in "mongoose shell>>> use blog_demo2; show collections"
// "mongoose shell>>> db.users.find()" will display all DB entries.
// Get an instance of the DB for the given schema.
const User = mongoose.model("User", userSchema);

module.exports = User;