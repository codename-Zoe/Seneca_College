/********************************************************************************* 
 * WEB322 – Assignment 04 
 * I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part 
 * of this assignment has been copied manually or electronically from any other source 
 * (including 3rd party web sites) or distributed to other students. 
 * ********************************************************************************/

var HTTP_PORT = process.env.PORT || 8080;
var express = require('express');
var multer = require('multer');
var bodyParser = require('body-parser');
var data = require('./data-service.js');
var path = require('path');
const exphbs = require('express-handlebars');
const fs = require('fs');
const { homedir } = require('os');
var app = express();
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.engine('.hbs', exphbs({ extname: '.hbs', defaultLayout: 'main' }));
app.set('view engine', '.hbs');

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

app.use(function(req,res,next){
  let route = req.baseUrl + req.path;
  app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
  next();
});

app.engine('.hbs', exphbs({ 
  extname: '.hbs',
  helpers: {
    navLink: function(url, options){
      return '<li' +
      ((url == app.locals.activeRoute) ? ' class="active" ' : '') +
      '><a href="' + url + '">' + options.fn(this) + '</a></li>';
    },
    equal: function (lvalue, rvalue, options) {
      if (arguments.length < 3)
      throw new Error("Handlebars Helper equal needs 2 parameters");
      if (lvalue != rvalue) {
      return options.inverse(this);
      } else {
      return options.fn(this);
      }
    }
  }
}));

app.get("/", function(req,res){
  res.render("home");
});

app.get("/about", function(req,res){
  res.render("about");
});

app.get("/employees/add", function(req,res){
  res.render("addEmployee");
});

app.get("/images/add", function(req,res){
  res.render("addImage");
});

app.post("/employees/add", (req, res) => {
  data.addEmployee(req.body).then(() => {
    res.redirect('/employees');
  });
});

app.post("/images/add", upload.single("imageFile"), (req, res) => {
  res.redirect("/images");
});

app.get("/employees", function(req,res){ // /employees?status=value
  if(req.query.status){  
    data.getEmployeesByStatus(req.query.status).then((data) => {
      res.render("employees", {employees: data});
    }).catch((err)=>{
      res.render({message: err});
    });
  }
  else if(req.query.department){  // /employees?department=value
    data.getEmployeesByDepartment(req.query.department).then((data) => {
      res.render("employees", {employees: data});
    }).catch((err)=>{
      res.render({message: err});
    });
  }
  else if(req.query.manager){  // /employees?manager=value
    data.getEmployeesByManager(req.query.manager).then((data) => {
      res.render("employees", {employees: data});
    }).catch((err)=>{
      res.render({message: err});
    });
  }
  else{    
    data.getAllEmployees().then((data) => {
      res.render("employees", {employees: data});
    }).catch((err)=>{
      res.render({message: err});
    });
  }
});
  
app.get("/employee/:value", function(req,res){  // /employee/6
  data.getEmployeeByNum(req.params.value).then((data) => {
    res.render("employee", {employee: data});
  }).catch((err)=>{
    res.render("employee", {message: err});
  });
});

app.post("/employee/update", (req, res) => {
  data.updateEmployee(req.body).then((data)=>{
    res.redirect("/employees");
  }).catch((err)=>{
    res.render({message: err});
  });
});

// app.get("/managers", function(req,res){
//   data.getManagers().then((data) => {
//     res.json(data);
//   }).catch((err)=>{
//     res.json({message: err});
//   });
// });

app.get("/departments", function(req,res){
  data.getDepartments().then((data) => {
    res.render("departments", {departments: data});
  }).catch((err)=>{
    res.render({message: err});
  });
});

app.get("/images", function(req,res){
  fs.readdir(path.join(__dirname, "/public/images/uploaded"), function(err, items) {
    res.render("images", {images: items});
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
