console.log("Babu Frick is my name.");

const express = require("express"); // express lets us create an HTTP server.
const app = express();

// We need body-parser for easy access to form data provided in the body of an POST 
// request that is formatted in x-www-form-urlencoded
const bodyParser = require("body-parser"); 

// Enable x-www-form-urlencoded in body-parser. Tell express to use body-parser.
app.use(bodyParser.urlencoded({extended: true})); 

// We need "request" to make HTTP requests to the movie API.
const requestfunc = require("request"); // BEWARE of var name collisions for common var names like "request".

// We use "querystring" to add easily add "Query Params" to our URLs e.g. to 
// add the "apikey" query param.
const querystring = require("querystring");

var searchMade = false;
var searchText = "";
var searchResults = [];
// Add the "/" route GET handler.
app.get("/", function(request, response){
    console.log("GET @ / bro. " + request.query.str)
    request.query.str
    if(searchMade === true) {
        // Display search results only if we got here via the /dosearch redirect.
        searchMade = false;
    } else {
        // Clear old search results.
        searchText = "";
        searchResults = [];
    }
    response.render("index.ejs", {searchResults: searchResults, searchText: searchText});
});

// Add the "/dosearch" route POST handler.
app.post("/dosearch", function(request, response){
    console.log("POST @ /dosearch bro.")
    searchMade = true; // Reset the search state.
    const qstr = querystring.stringify({s: request.body.thesearchterm, apikey: "thewdb"});
    const urlstr= "http://www.omdbapi.com/?"+ qstr;
    console.log("The search text was: " + request.body.thesearchterm);
    console.log("Movie API request = " + urlstr);
    
    searchText = request.body.thesearchterm; // Save the search text so we can echo it.
    // Ask the movie API for the search results.
    requestfunc(urlstr, function(error, rqresponse, body){ // BEWARE of var name collisions like rqresponse vs. response!
        console.error('API response error:', error); // Print the error if one occurred
        console.log('API response statusCode:', rqresponse && rqresponse.statusCode); // Print the response status code if a response was received
        parsedBody = JSON.parse(body);

        if(parsedBody.Response === "False") {
            searchResults = [];
        } else{
            searchResults = parsedBody.Search;
        }
        console.log("Redirecting to /.")
        response.redirect("/"); // Redirecting here ensures the search results have arrived before we redirect and try to show the results.
    });
    //response.send("HAY relax friend. Your searched for: " + request.body.thesearchterm);
    
});

var IP = "127.0.0.1";
var PORT = 3000;
app.listen(PORT, IP, function(){
    console.log("Now listen!... End of Proof.");
});
