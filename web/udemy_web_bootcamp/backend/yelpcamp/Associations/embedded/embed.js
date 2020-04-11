// Mongoose is our DB API.
const mongoose = require("mongoose");

/** Mongoose setup START **/
// "blog_demo" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/blog_demo", {useNewUrlParser: true, useUnifiedTopology: true});
// Define schema for the data to be added to the DB.
const blogSchema = mongoose.Schema({
    title: String,
    content: String
});

// "blogs" will show up in "mongoose shell>>> use blog_demo; show collections"
// "mongoose shell>>> db.blogs.find()" will display all DB entries.
// Get an instance of the DB for the given schema.
const Blog = mongoose.model("Blog", blogSchema);

// Define schema for the data to be added to the DB.
const userSchema = mongoose.Schema({
    name: String,
    email: String,
    posts: [blogSchema]
});

// "users" will show up in "mongoose shell>>> use blog_demo; show collections"
// "mongoose shell>>> db.users.find()" will display all DB entries.
// Get an instance of the DB for the given schema.
const User = mongoose.model("User", userSchema);
/** Mongoose setup END **/
console.log("Hay, relax guy!");

/*
User.create(
  {
    name: "Joe Exotic 2",
    email: "joe.e.2@gmail.com",
    posts: [{title: "Fuck Carole Baskin", content: "She is a cunt."}]
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


/*
Blog.create({title: "Please Donate To Big Cat Rescue!", content: "Hi, my name is Carole Baskin. Please give me your money so I can \"save cats\"."}, function(err, created_entry){
    if(err) {
        console.log(".create() error: ");
        console.log(err);
    } else {
        console.log(".create() successful: ");
        console.log(created_entry);
    }
});
*/

/*
User.create(
  {
    name: "Joe Exotic 3",
    email: "joe.e.3@gmail.com"
  },
  function(err, created_entry) {
    if(err) {
        console.log(".create() error: ");
        console.log(err);
    } else {
        console.log(".create() successful: ");
        console.log(created_entry);
        console.log(".pushing() post: ");
        newPost = {title: "Carole Baskin Is A Thief", content: "She steals your donation for personal gain."};
        created_entry.posts.push(newPost);
        created_entry.save(function(err, saved_entry){
              if(err) {
                  console.log(".save() error: ");
                  console.log(err);
              } else {
                  console.log(".save() OK: ");
                  console.log(saved_entry);
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
        console.log(".findOne() OK: ");
        console.log(found_entry);
        console.log(".pushing() post: ");
        newPost = {title: "Carole Baskin Is A Whore", content: "And she killed her husband."};
        found_entry.posts.push(newPost);
        found_entry.save(function(err, saved_entry){
              if(err) {
                  console.log(".save() error: ");
                  console.log(err);
              } else {
                  console.log(".save() OK: ");
                  console.log(saved_entry);
              }
          });
    }
});
*/