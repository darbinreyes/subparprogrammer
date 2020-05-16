// Mongoose is our DB API.
const mongoose = require("mongoose");

/** Mongoose setup START **/
// "blog_demo2" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/blog_demo2", {useNewUrlParser: true, useUnifiedTopology: true});
// Define schema for the data to be added to the DB.
const blogSchema = mongoose.Schema({
    title: String,
    content: String
});

// "blogs" will show up in "mongoose shell>>> use blog_demo2; show collections"
// "mongoose shell>>> db.blogs.find()" will display all DB entries.
// Get an instance of the DB for the given schema.
const Blog = mongoose.model("Blog", blogSchema);

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
/** Mongoose setup END **/
console.log("Don't worry aboot that, look over here!");

/*
User.create(
  {
    name: "Joe Exotic",
    email: "joe.e@gmail.com"
  },
  function(err, created_entry) {
    if(err) {
        console.log(".create() error: ");
        console.log(err);
    } else {
        console.log(".create() successful: ");
        console.log(created_entry);
    }
});
*/

// Create a new POST entry in DB.
// On success, findOne user
// .push new post to found user
// .save updated user

/*
Blog.create(
  {
    title: "The USDA Has No Idea How To Care For Exotic Animals",
    content: "Take a look at this video of the USDA inspecting the GW Zoo for 7 hours."
  },
  function(err, created_entry) {
    if(err) {
        console.log(".create() error: ");
        console.log(err);
    } else {
        console.log(".create() successful: ");
        console.log(created_entry);
        User.findOne({name: "Joe Exotic"}, function(err, found_entry){
          if(err) {
              console.log(".findOne() error: ");
              console.log(err);
          } else {
              console.log(".findOne() successful: ");
              console.log(found_entry);
              console.log(".pushing() post.");
              found_entry.posts.push(created_entry);
              found_entry.save(function(err, saved_entry){
                if(err) {
                    console.log(".save() error: ");
                    console.log(err);
                } else {
                    console.log(".save() successful: ");
                    console.log(saved_entry);
                }
              });
          }
        });
    }
});
*/

/*
User.findOne({name: "Joe Exotic"}, function(err, found_entry){
  if(err) {
      console.log(".findOne() error: ");
      console.log(err);
  } else {
      console.log(".findOne() successful: ");
      console.log(found_entry);
  }
});
*/

User.findOne({name: "Joe Exotic"}).populate("posts").exec(function(err, populated_user){
  if(err) {
      console.log(".exec() error: ");
      console.log(err);
  } else {
      console.log(".exec() successful: ");
      console.log(populated_user);
  }
});