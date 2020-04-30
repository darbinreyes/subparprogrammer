// Express is our HTTP server.
const express = require("express");
// We need body-parser for easy access to form data provided in the body of an POST
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser");
// Mongoose is our DB API.
const mongoose = require("mongoose");

/** Authentication related requires() START **/
const passport = require("passport"); // Authentication API
const LocalStrategy = require("passport-local"); // "local" authentication strategy.
//const passportLocalMongoose = require("passport-local-mongoose"); // authentication related to mongoose.
const expressSession = require("express-session"); // Used by express for client session API (client state).
/** Authentication related require() END **/


/** Mongoose setup START **/
// "yelpnutritionv6" will appear in "mongoose shell>>> show dbs" list.
mongoose.connect("mongodb://localhost/yelpnutritionv6", {useNewUrlParser: true, useUnifiedTopology: true});

const Nutrition = require("./models/nutrition");
const Comment = require("./models/comment");
const seedDB = require("./seedDB");
seedDB();
const User = require("./models/user");
/** Mongoose setup END **/

/** Express setup START **/
const app = express();

app.use(express.static("public")); // Tell express where to look for e.g. CSS files and images.

app.use(expressSession( // Tell express to use express-session
{
secret: "Cartman's mom is a dirty whore.", // Configure express-session. How to hash passwords.
resave: false,
saveUninitialized: false
}));
app.use(passport.initialize()); // Tell express to use passport step 1
app.use(passport.session()); // Tell express to use passport step 2

// Enable x-www-form-urlencoded in body-parser. Tell express to use body-parser.
app.use(bodyParser.urlencoded({extended: true}));
/** Express setup END **/

/** passport setup START **/
passport.use(
new LocalStrategy(User.authenticate())
);// This is a line added in as part of the POST @ /login to implement the user login function. See code along pt. 4. Tell passport to "for the local strategy use that method for the User.authenticate()"
// "Two more lines we need to get setup and then we can start working on the routes" // Code along pt.2.
passport.serializeUser(User.serializeUser()); // User.serializeUser() comes from ./models/user.js->UserSchema.plugin(passportLocalMongoose);
passport.deserializeUser(User.deserializeUser());
/** passport setup END **/

// "our own little middleware" - this is makes it so that the object describing a user is passed in to all .ejs files.
// This is how we can implement hiding/showing of the login/sign-up/logout links in the navbar based on whether or not the user is logger in. It also allows us to display the name of the currently logged in user in the navbar.
// This is really express setup but I'm pretty sure this line must occur after passport setup.
app.use(function(req, resp, next){
  resp.locals.currentUser = req.user;
  next();
});


// Add a GET request handler for /.
app.get("/", function (exp_request, exp_response) {
    console.log("GET @ /.");
    exp_response.render("landing.ejs");
});

// This is our fake database.
// nutritions = [
// {name: "Mango", image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg"},
// {name: "Lime", image: "https://upload.wikimedia.org/wikipedia/commons/6/68/Lime-Whole-Split.jpg"},
// {name: "Strawberry", image: "https://upload.wikimedia.org/wikipedia/commons/e/e1/Strawberries.jpg"},
// {name: "Avocado", image: "https://upload.wikimedia.org/wikipedia/commons/c/c0/Avocado-board.jpg"},
// {name: "Green Leaf Lettuce", image: "https://upload.wikimedia.org/wikipedia/commons/8/85/HK_food_%E8%94%AC%E8%8F%9C_vegetable_Lettuce_%E7%94%9F%E8%8F%9C_Lactuca_Sativa_green_leaves_with_fresh_clear_water_January_2019_SSG_02.jpg"},
// {name: "Tomato", image: "https://upload.wikimedia.org/wikipedia/commons/b/b7/Tomato-top.png"},
// {name: "Mango", image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg"},
// {name: "Lime", image: "https://upload.wikimedia.org/wikipedia/commons/6/68/Lime-Whole-Split.jpg"},
// {name: "Strawberry", image: "https://upload.wikimedia.org/wikipedia/commons/e/e1/Strawberries.jpg"},
// {name: "Avocado", image: "https://upload.wikimedia.org/wikipedia/commons/c/c0/Avocado-board.jpg"},
// {name: "Green Leaf Lettuce", image: "https://upload.wikimedia.org/wikipedia/commons/8/85/HK_food_%E8%94%AC%E8%8F%9C_vegetable_Lettuce_%E7%94%9F%E8%8F%9C_Lactuca_Sativa_green_leaves_with_fresh_clear_water_January_2019_SSG_02.jpg"},
// {name: "Tomato", image: "https://upload.wikimedia.org/wikipedia/commons/b/b7/Tomato-top.png"}
// ];

// Add a GET request handler for /.
app.get("/campgrounds", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds.");
    // Display the nutritions array obtained from the DB.
    Nutrition.find({}, function(err, nutritions){
        if(err) {
            console.log("DB.find() failed: ");
            console.log(err);
        } else {
            console.log("DB.find() successful. Found " + nutritions.length + " entries.");
            //console.log(nutritions);
            exp_response.render("campgrounds/index.ejs", {nutritions: nutritions});
        }
    });
});

app.post("/campgrounds", function (exp_request, exp_response){
    console.log("POST @ /campgrounds.");
    // Get form data specifying what will be added.
    // Add new entry to DB.
    // redirect to /campgrounds.
    var entryName = exp_request.body.name;
    var entryImage = exp_request.body.image;
    var entryEnergy = exp_request.body.energy;
    var entryDescription = exp_request.body.description;

    newEntry = new Nutrition({
        name: entryName,
        image: entryImage,
        energy: entryEnergy,
        description: entryDescription
    });

    newEntry.save(function(err, entry){
        if(err) {
            console.log("Failed to add new entry: ");
            console.log(err);
        } else {
            console.log("New entry added successfully: ");
            //console.log(entry);
        }
        exp_response.redirect("/campgrounds"); // Redirect upon completion of DB.save() otherwise the new entry may not be visible if we redirect before the save completes.
    });

});

app.get("/campgrounds/new", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds/new.");
    // Show the form for adding a new entry to the DB.
    exp_response.render("campgrounds/new.ejs");
});

app.get("/campgrounds/:id", function(exp_request, exp_response){
    // Example valid ID: 5e878925d90bb0b95ec6bf14, string, 24 chars.
    console.log("GET @ /camgrounds/" + exp_request.params.id);

    // TODO/FYI: App errors our when ID argument below is invalid.

    // Show the details of the DB entry with given ID.
    //Nutrition.findById(exp_request.params.id, function(err, entry){
    Nutrition.findById(exp_request.params.id).populate("comments").exec(function(err, entry){
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            //console.log(entry);
            exp_response.render("campgrounds/show.ejs", {entry: entry});
        }
    });
});

//
// ==================== Comment Routes ======================
//
// The use of isLoggedIn here is "middleware" that prevents access to the new comment form unless the user is logged in. It redirects to the /login page if the user is not logged in.
app.get("/campgrounds/:id/comments/new", isLoggedIn, function(exp_request, exp_response){
    // Form for adding a comment.
    console.log("GET @ /camgrounds/" + exp_request.params.id + "/comments/new");
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
           // console.log(entry);
            exp_response.render("comments/new.ejs", {entry: entry});
        }
    });
});

// The use of isLoggedIn here is "middleware" that prevents a direct POST(e.g. using POSTman or curl) to /campgrounds/:id/comments unless the user is logged in. It redirects to the /login page if the user is not logged in.
app.post("/campgrounds/:id/comments", isLoggedIn, function(exp_request, exp_response){
    console.log("POST @ /camgrounds/" + exp_request.params.id + "/comments");
    // Add a new comment to the DB entry with the specified ID.
    Nutrition.findById(exp_request.params.id, function(err, entry) {
        if(err) {
            console.log("findById() failed: ");
            console.log(err);
        } else {
            console.log("findById() successful. Entry: ");
            //console.log(entry);
            Comment.create(exp_request.body.comment, function(err, created_comment){
                if(err){
                    console.log("create() error: ");
                    console.log(err);
                } else {
                    console.log("create() successful: ");
                    //console.log(created_comment);
                    console.log("pushing() comment: ");
                    entry.comments.push(created_comment);
                    entry.save(function(err, saved_entry){
                        if(err) {
                            console.log("save() error: ");
                            console.log(err);
                        } else {
                            console.log("save() successful: ");
                            exp_response.redirect("/campgrounds/" + exp_request.params.id);
                        }
                    });
                }
            });
        }
    });
});

// Auth. Routes.

app.get("/register", function(exp_request, exp_response) {
  console.log("GET @ /register.");
  exp_response.render("register.ejs");
});

app.post("/register", function(exp_request, exp_response){
  console.log("POST @ /register.");
  console.log("exp_request.body = " + exp_request.body.username + "/" + exp_request.body.password);
  /*
    Register a new user. Passport does all the work behind the scenes to ensure
    passwords are not stored in the DB in plain text.
  */
  /*
    !!! - Looks like the password is POST'ed in plain text unless the connection
    is over HTTPS. Assuming with HTTPS the password is in the body and the body
    is encrypted on route to the server. - CORRECT, NOT encrypted - see evernote.
  */
  User.register(
    new User({username: exp_request.body.username}),
    exp_request.body.password,
    function(err, registeredUser){
      if(err) {
        console.log("User.register() error: ");
        console.log(err);
        // NOTE the use of "return" here, this is new and is important.
        return exp_response.redirect("/register");
      }
      // This is the "middleware" pattern ostensibly.
      console.log("User.register() successful: ");
      //console.log(registeredUser);
      // "At some point passport.authenticate() calls User.serializeUser()."
      // FYI: "local" strategy can be swapped with e.g. "twitter". - Code ALong pt.3.
      // "This actually logs in the user"
      /*
        FYI: exp_request and exp_response are the same as above, we are
        passing them as arguments to passport.authenticate("local")();
      */
      passport.authenticate("local")(exp_request, exp_response, function(){
         // Login the user and take user to /secret page upon successful registration
         exp_response.redirect("/campgrounds");
      });
    });

});

app.get("/login", function(exp_request, exp_response){
  console.log("GET @ /login.");
  exp_response.render("login.ejs");
});

// The call to passport.authenticate() here is called "middleware".
// Middleware = code that runs  before our final route callback. Can be "stacked up".
app.post("/login",
  passport.authenticate("local", {successRedirect: "/campgrounds", failureRedirect: "/login"}),
  function(exp_request, exp_response){

  console.log("POST @ /login.");
  exp_response.send("Nothing like a nice Kraft Dinner.");
});

app.get("/logout", function(exp_request, exp_response){
  console.log("GET @ /logout.");
  exp_request.logout(); // This method is from passport, it destroys the user's session. // Logs out the user. // How does this function know which user to log out? ANS: The user info is inside exp_request.
  //exp_response.send("I logged you out guy.");
  exp_response.redirect("/campgrounds");
});

// Middleware (see below post@/login) for the preventing access to /campgrounds/:id/comments/new unless the user is logged in.

function isLoggedIn(req, resp, next){  // next = next thing that needs to be called
  console.log("isLoggedIn() middleware.");
  if(req.isAuthenticated()) { // if logged in successfully // This is a passport method.
    console.log(".isAuthenticated().");
    return next(); // "move on to the next middleware"
  }
  // else, login failed.
  console.log("NOT .isAuthenticated().");
  resp.redirect("/login");
}

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});