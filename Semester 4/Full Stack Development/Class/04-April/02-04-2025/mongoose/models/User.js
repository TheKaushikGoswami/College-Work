const mongoose = require("mongoose");

const Uuser = mongoose.Schema({
    name: String,
    email: String,
    password: String
});

const User = mongoose.model("Uuser", Uuser);

module.exports = User;