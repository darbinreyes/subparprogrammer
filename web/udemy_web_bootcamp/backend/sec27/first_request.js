// https://github.com/request/request
// this node package is now deprecated.
// npm WARN deprecated request@2.88.2: request has been deprecated, see https://github.com/request/request/issues/3142


const request = require('request');

request('http://www.google.com', function (error, response, body) {
  console.error('error:', error); // Print the error if one occurred
  console.log('statusCode:', response && response.statusCode); // Print the response status code if a response was received
  //console.log('body:', body); // Print the HTML for the Google homepage.
});