console.log("Get me a Ferrari cake!");

var express = require("express");

var app = express();

console.log("Not an Acura cake!");

app.get("/", function(request, response){
   response.send("home"); 
});

app.get("/suck", function(request, response){
  response.send("<h1>My Balls Kyle! And Stan.</h1>"); 
});

app.get("/myballs", function(request, response){
  response.send("Are extra vinegary."); 
});

app.get("/sp/:spName", function(request, response){
  response.send(request.params.spName + " is a character in South Park"); 
});

app.get("/speak/:spcName", function(request, response){
  var spcName = request.params.spcName;
  
  if(spcName === "cartman") {
    response.send(spcName + ": " + "Suck my balls."); 
  } else if(spcName === "kyle"){
    response.send(spcName + ": " + "You know, I learned something today."); 
  } else {
    response.send(spcName + ": " + "Not handled bitch."); 
  }
});

app.get("/repeat/cartman/:repeatCount", function(request, response){
  var rCount = Number(request.params.repeatCount);
  if(isNaN(rCount) || rCount <= 0) {
      response.send("Screw you guys I'm going home.");
      return;
  }
  var mainstr = "Suck my balls. "
  var tempstr = ""
  for (var i = 0; i < rCount; i++) {
    tempstr += mainstr;
  }
  response.send(tempstr); 
});

app.get("*", function(request, response){
   response.send("HAY relax guy."); 
});

app.listen(process.env.PORT, process.env.IP, function(){
    console.log("So this is NodeJS?! " + process.env.IP + " " + process.env.PORT);
});