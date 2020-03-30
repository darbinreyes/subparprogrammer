// Express is our HTTP server.
const express = require("express");
const app = express();

app.use(express.static("public")); // Tell express where to look for CSS files.

// We need body-parser for easy access to form data provided in the body of an POST 
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser"); 

// Enable x-www-form-urlencoded in body-parser. Tell express to use body-parser.
app.use(bodyParser.urlencoded({extended: true})); 

// Add a GET request handler for /.
app.get("/", function (exp_request, exp_response) {
    console.log("GET @ /.");
    exp_response.render("landing.ejs");
});

// This is our fake database.
nutritions = [{name: "Mango", image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg"},
{name: "Lime", image: "https://upload.wikimedia.org/wikipedia/commons/6/68/Lime-Whole-Split.jpg"},
{name: "Strawberry", image: "https://upload.wikimedia.org/wikipedia/commons/e/e1/Strawberries.jpg"}
];

// Add a GET request handler for /.
app.get("/campgrounds", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds.");
    exp_response.render("campgrounds.ejs", {nutritions: nutritions});
});

app.post("/campgrounds", function (exp_request, exp_response){
    console.log("POST @ /campgrounds.");
    // get form data
    // redirect to /campgrounds.
    var newName = exp_request.body.name;
    var newImage = exp_request.body.image;
    nutritions.push({name: newName, image: newImage});
    exp_response.redirect("/campgrounds");
});

app.get("/campgrounds/new", function (exp_request, exp_response) {
    console.log("GET @ /campgrounds/new.");
    exp_response.render("new.ejs");
});

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});