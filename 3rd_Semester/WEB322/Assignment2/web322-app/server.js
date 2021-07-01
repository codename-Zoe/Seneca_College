/********************************************************************************* 
 * WEB322 – Assignment 02 
 * I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part 
 * of this assignment has been copied manually or electronically from any other source 
 * (including 3rd party web sites) or distributed to other students. 
 * 
 * Online (Heroku) Link: https://tranquil-tundra-26636.herokuapp.com/
 * 
 * ********************************************************************************/

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var data = require("./data-service.js");
var path = require("path");
var app = express();
app.use(express.static('public'));
app.use(express.static('public/css'));

function onHTTPStart(){
  console.log("Express http server listening on PORT: " + HTTP_PORT);
}

app.get("/", function(req,res){
  res.sendFile(path.join(__dirname, "/views/home.html"));
});

app.get("/about", function(req,res){
  res.sendFile(path.join(__dirname, "/views/about.html"));
});

app.get("/employees", function(req,res){
  data.getAllEmployees().then((data) => {
    res.json(data);
  }).catch((err)=>{
    res.json({message: err});
  });
});

app.get("/managers", function(req,res){
  data.getManagers().then((data) => {
    res.json(data);
  }).catch((err)=>{
    res.json({message: err});
  });
});

app.get("/departments", function(req,res){
  data.getDepartments().then((data) => {
    res.json(data);
  }).catch((err)=>{
    res.json({message: err});
  });
});

data.initialize().then(function(){
  app.listen(HTTP_PORT, onHTTPStart);
}).catch((err)=>{
  console.log("Unable to start server: " + err);
});

app.use((req,res)=>{  
  res.status(404).sendFile(path.join(__dirname,"views/error.html"));
});
