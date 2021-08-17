/********************************************************************************* 
 * WEB322 – Assignment 06 
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
var dataServiceAuth = require('./data-service-auth.js');
var clientSessions = require("client-sessions");
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

app.use(clientSessions({
  cookieName: "session",
  secret: "web322_A6",
  duration: 2 * 60 * 1000,
  activeDuration: 1000 * 60 
}));

const storage = multer.diskStorage({
  destination: "./public/images/uploaded",
  filename: function (req, file, cb) {
    cb(null, Date.now() + path.extname(file.originalname));
    }
});
const upload = multer({ storage: storage });

app.use((req,res,next) => {
  let route = req.baseUrl + req.path;
  app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
  next();
});

app.engine('.hbs', exphbs({ 
  extname: '.hbs',
  helpers: {
    navLink: (url, options) => {
      return '<li' +
      ((url == app.locals.activeRoute) ? ' class="active" ' : '') +
      '><a href="' + url + '">' + options.fn(this) + '</a></li>';
    },
    equal: (lvalue, rvalue, options) => {
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

app.use(function(req, res, next) {
  res.locals.session = req.session;
  next();
});

function ensureLogin(req, res, next){
  if(!req.session.user){
    res.redirect("/login");
  } else {
    next();
  }
}

////////// GET route //////////

app.get("/", (req,res) => {
  res.render("home");
});

app.get("/about", (req,res) => {
  res.render("about");
});

app.get("/images", ensureLogin, (req,res) => {
  fs.readdir(path.join(__dirname, "/public/images/uploaded"), (err, items) => {
    res.render("images", {images: items});
  })
});

app.get("/images/add", ensureLogin, (req,res) => {
  res.render("addImage");
});

app.get("/employees", ensureLogin, (req,res) => {// /employees?status=value
  if(req.query.status){  
    data.getEmployeesByStatus(req.query.status).then((data) => {
      data.length > 0 ? res.render("employees", { employees: data }) : res.render("employees",{ message: "no results" });
    }).catch((err)=>{
      res.render({message: err});
    });
  }
  else if(req.query.department){  // /employees?department=value
    data.getEmployeesByDepartment(req.query.department).then((data) => {
      data.length > 0 ? res.render("employees", { employees: data }) : res.render("employees",{ message: "no results" });
    }).catch((err)=>{
      res.render({message: err});
    });
  }
  else if(req.query.manager){  // /employees?manager=value
    data.getEmployeesByManager(req.query.manager).then((data) => {
      data.length > 0 ? res.render("employees", { employees: data }) : res.render("employees",{ message: "no results" });
    }).catch((err)=>{
      res.render({message: err});
    });
  }
  else{    
    data.getAllEmployees().then((data) => {
      data.length > 0 ? res.render("employees", { employees: data }) : res.render("employees",{ message: "no results" });
    }).catch((err)=>{
      res.render({message: err});
    });
  }
});

app.get("/employees/add", ensureLogin, (req,res) => {
  data.getDepartments().then((data)=>{
    res.render("addEmployee", {departments: data});
  }).catch((err)=>{
    res.render("addEmployee", {departments: []});
  });
});

app.get("/employees/delete/:empNum", ensureLogin, (req, res) => {
  data.deleteEmployeeByNum(req.params.empNum)
  .then((data) => {
    res.redirect('/employees');
  }).catch((err)=>{
    res.status(500).send("Unable to Remove Employee / Employee not found");
  });
})

app.get("/employee/:empNum", ensureLogin, (req, res) => {
  // initialize an empty object to store the values
  let viewData = {};
  data.getEmployeeByNum(req.params.empNum).then((data) => {
    if (data) {
      viewData.employee = data; //store employee data in the "viewData" object as "employee"
    } else {
      viewData.employee = null; // set employee to null if none were returned
    }
  }).catch(() => {
    viewData.employee = null; // set employee to null if there was an error
  }).then(data.getDepartments)
  .then((data) => {
    viewData.departments = data; 
    for (let i = 0; i < viewData.departments.length; i++) {
      if (viewData.departments[i].departmentId == viewData.employee.department) {
        viewData.departments[i].selected = true;
      }
    }
  }).catch(() => {
    viewData.departments = []; // set departments to empty if there was an error
  }).then(() => {
    if (viewData.employee == null) { // if no employee - return an error
      res.status(404).send("Employee Not Found");
    } else {
      res.render("employee", { viewData: viewData }); // render the "employee" view
    }
  });
});

app.get("/departments", ensureLogin, (req,res) => {
  data.getDepartments().then((data) => {
    data.length > 0 ? res.render("departments", { departments: data }) : res.render("departments",{ message: "no results" });
  }).catch((err)=>{
    res.render({message: err});
  });
});

app.get("/departments/add",ensureLogin, (req,res) => {
  res.render("addDepartment");
});

app.get("/department/:departmentId",ensureLogin, (req,res) => {
  data.getDepartmentById(req.params.departmentId).then((data) => {
    res.render("department", {department: data});
  }).catch(() => {
    res.status(404).send("Department Not Found");
  });
});

app.get("/department/delete/:departmentId", ensureLogin, (req, res) => {
  data.deleteDepartmentById(req.params.departmentId)
  .then((data) => {
    res.redirect('/departments');
  }).catch((err)=>{
    res.status(500).send("Unable to Remove Department / Department not found");
  });
})

app.get("/login", (req,res)=>{
  res.render("login");
});

app.get("/register", (req,res)=>{
  res.render("register");
});

app.get("/logout", (req,res)=>{
  req.session.reset();
  res.redirect("/");
});

app.get("/userHistory", ensureLogin, (req,res)=>{
  res.render("userHistory");
});


////////// POST route //////////

app.post("/images/add", ensureLogin, upload.single("imageFile"), (req, res) => {
  res.redirect("/images");
});

app.post("/employees/add", ensureLogin, (req, res) => {
  data.addEmployee(req.body).then(() => {
    res.redirect('/employees');
  });
});

app.post("/employee/update", ensureLogin, (req, res) => {
  data.updateEmployee(req.body).then((data)=>{
    res.redirect("/employees");
  }).catch((err)=>{
    res.render({message: err});
  });
});

app.post("/departments/add", ensureLogin, (req, res) => {
  data.addDepartment(req.body).then(() => {
    res.redirect('/departments');
  });
});

app.post("/department/update", ensureLogin, (req, res) => {
  data.updateDepartment(req.body).then((data)=>{
    res.redirect("/departments");
  }).catch((err)=>{
    res.render({message: err});
  });
});

app.post("/register", (req,res)=>{
  dataServiceAuth.registerUser(req.body).then(()=>{
    res.render("register", {successMessage: "User created"});
  }).catch((err)=>{
    res.render("register", {errorMessage: err, userName: req.body.userName});
  });
});

app.post("/login", (req,res)=>{
  req.body.userAgent = req.get("User-Agent");
  dataServiceAuth.checkUser(req.body).then((user)=>{
    req.session.user = {
      userName: user.userName,
      email: user.email,
      loginHistory: user.loginHistory
    }
    res.redirect("/employees");
  }).catch((err)=>{
    res.render("login", {errorMessage: err, userName: req.body.userName});
  });
});

dataServiceAuth.initialize()
.then(dataServiceAuth.initialize)
.then(() => {
  app.listen(HTTP_PORT, () => {
    console.log("app listening on: " + HTTP_PORT);
  });
}).catch((err)=>{
  console.log("Unable to start server: " + err);
});

app.use((req,res)=>{  
  res.status(404).sendFile(path.join(__dirname,"views/error.html"));
});