/*
npm6 has the following notes:
    It is not recommended to install packages globally. But if you do so please
    be aware that they won't get cleaned up when you deactivate or uninstall
    npm6. Globally installed packages will remain in
    /opt/local/lib/node_modules/ until you manually delete them.
*/
console.log("This is indeed a panflute epidemic.");

var express = require("express");

var app = express();
app.use(express.static("public"));
//app.set("view engine", "ejs");
console.log("A pandemic!");

app.get("/", function(request, response){
  response.render("index.ejs");
});

app.get("/c3po/:robotName", function(request, response){
  var robotName = request.params.robotName;
  response.render("other.ejs", {"robotName": robotName});
});


app.get("*", function(request, response){
  response.render("default.ejs")
});

app.listen(process.env.PORT, process.env.IP, function(){
    console.log("So this is NodeJS?! Ostensibly, I'm not impressed. " + process.env.IP + " " + process.env.PORT);
});