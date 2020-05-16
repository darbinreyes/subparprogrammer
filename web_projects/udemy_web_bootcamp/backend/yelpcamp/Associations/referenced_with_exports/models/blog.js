// Mongoose is our DB API.
const mongoose = require("mongoose");

// Define schema for the data to be added to the DB.
const blogSchema = mongoose.Schema({
    title: String,
    content: String
});

// "blogs" will show up in "mongoose shell>>> use blog_demo2; show collections"
// "mongoose shell>>> db.blogs.find()" will display all DB entries.
// Get an instance of the DB for the given schema.
const Blog = mongoose.model("Blog", blogSchema);

module.exports = Blog;