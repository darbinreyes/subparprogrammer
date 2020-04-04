const mongoose = require("mongoose");

// "nutrition" will appear in "show dbs" list.
mongoose.connect("mongodb://localhost/nutrition", {useNewUrlParser: true, useUnifiedTopology: true});

// Add to DB

// Define schema for the data to be added to the DB.
const nutritionSchema = mongoose.Schema({
    name: String,
    portion: Number,
    energy: Number
});

// "nutritions" will show up in "use nutrition; show collections"
// "db.nutritions.find()" will display DB entries.
// Get an instance of the DB for the given schema.
const Nutrition = mongoose.model("Nutrition", nutritionSchema);

// Same thing in one line.
// const Nutrition = mongoose.model("Nutrition", {name: String, portion: Number, energy: Number});

// var food0 = new Nutrition({
//     name: "banana",
//     portion: 100,
//     energy: 89
// })

// var food0 = new Nutrition({
//     name: "strawberry",
//     portion: 100,
//     energy: 32
// })

// food0.save(function(err, food){
//     if(err) {
//         console.log(err);
//     } else {
//         console.log(food);
//     }
// })

// Read from DB

// Nutrition.find({}, function(err, foods){
//     if(err) {
//         console.log(err);
//     } else {
//         console.log(foods);
//     }
// });

// Nutrition.find({name: "banana"}, function(err, foods){
//     if(err) {
//         console.log(err);
//     } else {
//         console.log(foods);
//     }
// });

Nutrition.create({name: "mango", portion: 100, energy: 60}, function(err, food){
    if(err) {
        console.log(err);
    } else {
        console.log(food);
    }
});