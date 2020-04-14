// Mongoose is our DB API.
const mongoose = require("mongoose");

// Initial DB entries
 data = [
 {name: "Mango", image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg", energy: 100, description: "This is the description 0."},
 {name: "Lime", image: "https://upload.wikimedia.org/wikipedia/commons/6/68/Lime-Whole-Split.jpg", energy: 76, description: "This is the description 1."},
 {name: "Strawberry", image: "https://upload.wikimedia.org/wikipedia/commons/e/e1/Strawberries.jpg", energy: 39, description: "This is the description 2."}
];

function seedDB() {
  console.log("Seeding the DB.");
  const Nutrition = require("./models/nutrition");
  const Comment = require("./models/comment");

  // Remove all DB nutrition entries.
  console.log("Removing all nutritions.");
  Nutrition.remove({}, function(err, removed_entries){
    if(err) {
        console.log(".remove() error: ");
        console.log(err);
    } else {
        console.log(".remove() successful: ");
        console.log(removed_entries);
    }
  });
  // Remove all DB comment entries.
  console.log("Removing all comments.");
  Comment.remove({}, function(err, removed_entries){
    if(err) {
        console.log(".remove() error: ");
        console.log(err);
    } else {
        console.log(".remove() successful: ");
        console.log(removed_entries);
    }
  });

  // Add all DB nutrition entries from the data array.
  data.forEach(function(currentValue, index, array) {
    console.log("Creating Nutrition Entry.");
    Nutrition.create(currentValue, function(err, new_nutrition){
      if(err) {
          console.log(".create() error: ");
          console.log(err);
      } else {
          console.log(".create() successful: ");
          console.log(new_nutrition);
          test_comment = {text: "Screw you guys, I'm goin' home.", author: "Eric Cartman"};
          console.log("Creating Comment Entry.");
          Comment.create(test_comment, function(err, new_comment){
            if(err) {
                console.log(".create() error: ");
                console.log(err);
            } else {
                console.log(".create() successful: ");
                console.log(new_comment);
                console.log(".pushing() comment and saving().");
                new_nutrition.comments.push(new_comment);
                new_nutrition.save(function(err, saved_nutrition){
                  if(err) {
                      console.log(".save() error: ");
                      console.log(err);
                  } else {
                      console.log(".save() successful: ");
                      console.log(saved_nutrition);
                  }
                })
            }
          });
      }
    });
  });
}

module.exports = seedDB;