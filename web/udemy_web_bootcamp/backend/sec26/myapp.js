/*
npm6 has the following notes:
    It is not recommended to install packages globally. But if you do so please
    be aware that they won't get cleaned up when you deactivate or uninstall
    npm6. Globally installed packages will remain in
    /opt/local/lib/node_modules/ until you manually delete them.

 mongodb has the following notes:
    A startup item has been generated that will aid in starting mongodb with
    launchd. It is disabled by default. Execute the following command to start
    it, and to cause it to launch at startup:
    
        sudo port load mongodb
  python37 has the following notes:
    To make this the default Python or Python 3 (i.e., the version run by the
    'python' or 'python3' commands), run one or both of:
    
        sudo port select --set python python37
        sudo port select --set python3 python37

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
var myPORT = 3000
var myIP = "127.0.0.1"
app.listen(myPORT, myIP, function(){
    console.log("Go on without me, the prices are too low. " + myIP + " " + myPORT);
});