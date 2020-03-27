// Express is our HTTP server.
const express = require("express");
const app = express();

// Add a GET request handler for /.
app.get("/", function (exp_request, exp_response) {
    console.log("GET @ /.");
    exp_response.send("My name is Babu Frick.");
});

const PORT = 3000;
const IP = "127.0.0.1";

// Tell express to start listening for HTTP requests.
app.listen(PORT, IP, function(){
    console.log("Server is listening! Droid remember go blank. ... blank blank!");
});