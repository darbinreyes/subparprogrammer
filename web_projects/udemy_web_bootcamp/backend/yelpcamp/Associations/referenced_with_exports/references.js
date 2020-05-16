// Mongoose is our DB API.
const mongoose = require("mongoose");

/** Mongoose setup START **/
// "blog_demo2" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/blog_demo2", {useNewUrlParser: true, useUnifiedTopology: true});
const Blog = require("./models/blog.js");
const User = require("./models/user.js");
/** Mongoose setup END **/
console.log("You know I never turn down craft dinner Phillip.");

// create a new user.

/*
User.create(
  {
    name: "Terrance",
    email: "terrance@gmail.com"
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

// Create a new post and add it to an existing user.
/*
Blog.create(
  {
    title: "The Canada Government",
    content: "Wants more money. From where? The internet."
  },
  function(err, created_entry) {
    if(err) {
        console.log(".create() error: ");
        console.log(err);
    } else {
        console.log(".create() successful: ");
        console.log(created_entry);
        User.findOne({name: "Terrance"}, function(err, found_entry){
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

// find an existing user.

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

// find an existing user and explicitly print out all blog posts.

User.findOne({name: "Terrance"}).populate("posts").exec(function(err, populated_user){
  if(err) {
      console.log(".exec() error: ");
      console.log(err);
  } else {
      console.log(".exec() successful: ");
      console.log(populated_user);
  }
});