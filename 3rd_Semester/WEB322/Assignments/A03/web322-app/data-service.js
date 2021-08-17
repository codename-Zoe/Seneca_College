const fs = require("fs");
let employees = [];
let managers = [];
let departments = [];

module.exports.initialize = function(){
  return new Promise((resolve, reject) =>{
    fs.readFile('./data/employees.json', (err, data)=>{
      if(err){
        reject(err);
      }
      employees = JSON.parse(data);
      resolve();
    });
    fs.readFile('./data/departments.json', (err, data)=>{
      if(err){
        reject(err);
      }
      departments = JSON.parse(data);
      resolve();
    }); 
  });
}

module.exports.getAllEmployees = function(){
  return new Promise((resolve, reject)=>{
    if(employees.length == 0){
      reject("No Results Returned");
    }
    resolve(employees);
  });
}

module.exports.getManagers = function(){
  return new Promise((resolve, reject)=>{
    for(let i = 0; i < employees.length; i++){
      if(employees[i].isManager == true){
        managers.push(employees[i]);
      }
    }
    if(employees.length == 0){
      reject("No Results Returned");
    }
    resolve(managers);
  });
}

module.exports.getDepartments = function(){
  return new Promise((resolve, reject)=>{
    if(departments.length == 0){
      reject("No Results Returned");
    }
    resolve(departments);
  });
}

module.exports.addEmployee = function(employeeData){
  return new Promise((resolve,reject) =>{
    if(employeeData.length == 0){
      reject("No Data to be added")
    }
    employeeData.isManager = (employeeData.isManager == null)? false : true;
    employeeData.employeeNum = employees.length + 1;
    employees.push(employeeData);
    resolve(employees);
  });
}

module.exports.getEmployeesByStatus = function(status){
  return new Promise((resolve, reject)=>{
    let emp_arr = [];
    for(let i = 0; i < employees.length; i++){
      if(employees[i].status == status){
        emp_arr.push(employees[i]);
      }
    }
    if(emp_arr.length == 0){
      reject("No Results Returned");
    }  
    resolve(emp_arr);
  });
}

module.exports.getEmployeesByDepartment = function(department){
  return new Promise((resolve, reject)=>{
    let emp_arr = [];
    for(let i = 0; i < employees.length; i++){
      if(employees[i].department == department){
        emp_arr.push(employees[i]);
      }
    }
    if(emp_arr.length == 0){
      reject("No Results Returned");
    }  
    resolve(emp_arr);
  });
}

module.exports.getEmployeesByManager = function(manager){
  return new Promise((resolve, reject)=>{
    let emp_arr = [];
    for(let i = 0; i < employees.length; i++){
      if(employees[i].employeeManagerNum == manager){
        emp_arr.push(employees[i]);
      }
    }
    if(emp_arr.length == 0){
      reject("No Results Returned");
    }  
    resolve(emp_arr);
  });
}

module.exports.getEmployeeByNum = function(num){
  return new Promise((resolve, reject)=>{
    let emp_arr = [];
    for(let i = 0; i < employees.length; i++){
      if(employees[i].employeeNum == num){
        emp_arr.push(employees[i]);
      }
    }
    if(emp_arr.length == 0){
      reject("No Results Returned");
    }  
    resolve(emp_arr);
  });
}