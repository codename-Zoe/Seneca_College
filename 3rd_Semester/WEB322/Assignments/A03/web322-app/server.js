/********************************************************************************* 
 * WEB322 – Assignment 03 
 * I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part 
 * of this assignment has been copied manually or electronically from any other source 
 * (including 3rd party web sites) or distributed to other students. 
 * 
 * Name: Nozomi Tsuchiya Student ID: 154666192 Date: 2021-06-22 
 * 
 * Online (Heroku) Link: https://tranquil-tundra-26636.herokuapp.com/
 * 
 * ********************************************************************************/

var HTTP_PORT = process.env.PORT || 8080;
var express = require('express');
var multer = require('multer');
var bodyParser = require('body-parser');
var data = require('./data-service.js');
var path = require('path');
const fs = require('fs');
var app = express();
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));

function onHTTPStart(){
  console.log("Express http server listening on PORT: " + HTTP_PORT);
}

const storage = multer.diskStorage({
  destination: "./public/images/uploaded",
  filename: function (req, file, cb) {
    cb(null, Date.now() + path.extname(file.originalname));
    }
});
const upload = multer({ storage: storage });


app.get("/", function(req,res){
  res.sendFile(path.join(__dirname, "/views/home.html"));
});

app.get("/about", function(req,res){
  res.sendFile(path.join(__dirname, "/views/about.html"));
});

app.get("/employees/add", function(req,res){
  res.sendFile(path.join(__dirname, "/views/addEmployee.html"));
});

app.post("/employees/add", (req, res) => {
  data.addEmployee(req.body).then(() => {
    res.redirect('/employees');
  });
});

app.get("/images/add", function(req,res){
  res.sendFile(path.join(__dirname, "/views/addImage.html"));
});

app.post("/images/add", upload.single("imageFile"), (req, res) => {
  res.redirect("/images");
});

app.get("/employees", function(req,res){
  if(req.query.status){  // /employees?status=value
    data.getEmployeesByStatus(req.query.status).then((data) => {
      res.json(data);
    }).catch((err)=>{
      res.json({message: err});
    });
  }
  else if(req.query.department){  // /employees?department=value
    data.getEmployeesByDepartment(req.query.department).then((data) => {
      res.json(data);
    }).catch((err)=>{
      res.json({message: err});
    });
  }
  else if(req.query.manager){  // /employees?manager=value
    data.getEmployeesByManager(req.query.manager).then((data) => {
      res.json(data);
    }).catch((err)=>{
      res.json({message: err});
    });
  }
  else{    
    data.getAllEmployees().then((data) => {
      res.json(data);
    }).catch((err)=>{
      res.json({message: err});
    });
  }
});
  
app.get("/employee/:value", function(req,res){  // /employee/6
  data.getEmployeeByNum(req.params.value).then((data) => {
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

app.get("/images", function(req,res){
  fs.readdir(path.join(__dirname, "/public/images/uploaded"), function(err, items) {
    var images = [];
    for (let i = 0; i < items.length; i++) {
      images.push(items[i]);
    }
    res.json({images: images});
  })
});

data.initialize().then(function(){
  app.listen(HTTP_PORT, onHTTPStart);
}).catch((err)=>{
  console.log("Unable to start server: " + err);
});

app.use((req,res)=>{  
  res.status(404).sendFile(path.join(__dirname,"views/error.html"));
});
