// https://github.com/request/request
// this node package is now deprecated.
// npm WARN deprecated request@2.88.2: request has been deprecated, see https://github.com/request/request/issues/3142

// var lc = require("locus");
require("locus"); // ostensibly we don't need to use the return value from this call, it automatically introduces "locus" as a name in the current scope.

const request = require('request');

// request('http://www.google.com', function (error, response, body) {
//   console.error('error:', error); // Print the error if one occurred
//   console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
//   //console.log('body:', body); // Print the HTML for the Google homepage.
// });

request('https://samples.openweathermap.org/data/2.5/weather?q=London,uk&appid=b6907d289e10d714a6e88b30761fae22', function (error, response, body) {
  console.error('error:', error); // Print the error if one occurred
  console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
  console.log('body:', body); // Print the HTML for the Google homepage.
  parsedBody = JSON.parse(body);
  console.log('parsedBody:', parsedBody);
  console.log('parsedBody.name', parsedBody.name);
});

var cacastr = "MrHanky"
//eval(locus);
console.log("Here we fucking go.");