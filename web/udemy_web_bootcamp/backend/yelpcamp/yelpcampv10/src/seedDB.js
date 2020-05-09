// @flow

// Mongoose is our DB API.
const mongoose = require("mongoose");

// Initial DB entries
const description0 = "A mango is a juicy stone fruit (drupe) produced from numerous species of tropical trees belonging to the flowering plant genus Mangifera, cultivated mostly for their edible fruit. Most of these species are found in nature as wild mangoes. The genus belongs to the cashew family Anacardiaceae. Mangoes are native to South Asia,[1][2] from where the \"common mango\" or \"Indian mango\", Mangifera indica, has been distributed worldwide to become one of the most widely cultivated fruits in the tropics. Other Mangifera species (e.g. horse mango, Mangifera foetida) are grown on a more localized basis. Worldwide, there are several hundred cultivars of mango. Depending on the cultivar, mango fruit varies in size, shape, sweetness, skin color, and flesh color which may be pale yellow, gold, or orange.[1] Mango is the national fruit of India and Pakistan, and the national tree of Bangladesh.[3] It is the unofficial national fruit of the Philippines.";
const description1 = "There are several species of citrus trees whose fruits are called limes, including the Key lime (Citrus aurantiifolia), Persian lime, kaffir lime, and desert lime. Limes are a rich source of vitamin C, are sour, and are often used to accent the flavours of foods and beverages. They are grown year-round.[3] Plants with fruit called \"limes\" have diverse genetic origins; limes do not form a monophyletic group.";
const description2 = "The garden strawberry (or simply strawberry; Fragaria × ananassa)[1] is a widely grown hybrid species of the genus Fragaria, collectively known as the strawberries, which are cultivated worldwide for their fruit. The fruit is widely appreciated for its characteristic aroma, bright red color, juicy texture, and sweetness. It is consumed in large quantities, either fresh or in such prepared foods as jam, juice, pies, ice cream, milkshakes, and chocolates. Artificial strawberry flavorings and aromas are also widely used in products such as candy, soap, lip gloss, perfume, and many others. The garden strawberry was first bred in Brittany, France, in the 1750s via a cross of Fragaria virginiana from eastern North America and Fragaria chiloensis, which was brought from Chile by Amédée-François Frézier in 1714.[2] Cultivars of Fragaria × ananassa have replaced, in commercial production, the woodland strawberry (Fragaria vesca), which was the first strawberry species cultivated in the early 17th century.[3]";

const data = [
 {name: "Mango", image: "https://upload.wikimedia.org/wikipedia/commons/f/fb/Carabao_mangoes_%28Philippines%29.jpg", energy: 60, description: description0},
 {name: "Lime", image: "https://upload.wikimedia.org/wikipedia/commons/6/68/Lime-Whole-Split.jpg", energy: 30, description: description1},
 {name: "Strawberry", image: "https://upload.wikimedia.org/wikipedia/commons/e/e1/Strawberries.jpg", energy: 32, description: description2}
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
        //console.log(removed_entries);
    }
  });
  // Remove all DB comment entries.
  // console.log("Removing all comments.");
  // Comment.remove({}, function(err, removed_entries){
  //   if(err) {
  //       console.log(".remove() error: ");
  //       console.log(err);
  //   } else {
  //       console.log(".remove() successful: ");
  //       //console.log(removed_entries);
  //   }
  // });

  // Add all DB nutrition entries from the data array.
  // data.forEach(function(currentValue, index, array) {
  //   console.log("Creating Nutrition Entry.");
  //   Nutrition.create(currentValue, function(err, new_nutrition){
  //     if(err) {
  //         console.log(".create() error: ");
  //         console.log(err);
  //     } else {
  //         console.log(".create() successful: ");
  //         //console.log(new_nutrition);
  //         var test_comment = {text: "Screw you guys, I'm goin' home.", author: "Eric Cartman"};
  //         console.log("Creating Comment Entry.");
  //         Comment.create(test_comment, function(err, new_comment){
  //           if(err) {
  //               console.log(".create() error: ");
  //               console.log(err);
  //           } else {
  //               console.log(".create() successful: ");
  //               //console.log(new_comment);
  //               console.log(".pushing() comment and saving().");
  //               new_nutrition.comments.push(new_comment);
  //               new_nutrition.save(function(err, saved_nutrition){
  //                 if(err) {
  //                     console.log(".save() error: ");
  //                     console.log(err);
  //                 } else {
  //                     console.log(".save() successful: ");
  //                     //console.log(saved_nutrition);
  //                 }
  //               })
  //           }
  //         });
  //     }
  //   });
  // });
}

module.exports = seedDB;