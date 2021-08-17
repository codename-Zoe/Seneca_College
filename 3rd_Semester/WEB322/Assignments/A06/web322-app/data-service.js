const Sequelize = require('sequelize');
var sequelize = new Sequelize('d4ovjsg3an3im2', 'hbsdpthctvticf', '53d4bbc5911019b60e35f4249c168bb412d5b935b8043f71bcf1811bebc042c8', {
  host: 'ec2-23-21-4-7.compute-1.amazonaws.com',
  dialect: 'postgres',
  port: 5432,
  dialectOptions: {
  ssl: { rejectUnauthorized: false }
  },
  query: { raw: true }
});

var Employee = sequelize.define('Employee', {
  employeeNum: {
    type: Sequelize.INTEGER,
    primaryKey: true,
    autoIncrement: true
  },
  firstName: Sequelize.STRING,
  lastName: Sequelize.STRING,
  email: Sequelize.STRING,
  SSN: Sequelize.STRING,
  addressStreet: Sequelize.STRING,
  addressCity: Sequelize.STRING,
  addressState: Sequelize.STRING,
  addressPostal: Sequelize.STRING,
  maritalStatus: Sequelize.STRING,
  isManager: Sequelize.BOOLEAN,
  employeeManagerNum: Sequelize.INTEGER,
  status: Sequelize.STRING,
  department: Sequelize.INTEGER,
  hireDate: Sequelize.STRING,
});

var Department = sequelize.define('Department', {
  departmentId: {
    type: Sequelize.INTEGER,
    primaryKey: true,
    autoIncrement: true
  },
  departmentName: Sequelize.STRING,
});

module.exports.initialize = function(){
  return new Promise(function (resolve, reject) {
    sequelize.sync().then(()=> {
      resolve();        
    }).catch((err)=>{
      reject("unable to sync the database");
    });
  });
}

module.exports.addDepartment = function(departmentData){
  return new Promise((resolve, reject) => {
    for (const elem in departmentData) {
      departmentData[elem] == "" ? departmentData[elem] = null : departmentData[elem];
    }
    Department.create({
      departmentId: departmentData.departmentId,
      departmentName: departmentData.departmentName
    }).then(() =>{
      resolve();
    }).catch((err) =>{
      reject("unable to create department");
    });
  });
}

module.exports.addEmployee = function(employeeData){
  return new Promise((resolve, reject) => {
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (const elem in employeeData) {
      employeeData[elem] == "" ? employeeData[elem] = null : employeeData[elem];
    }
    Employee.create({
      employeeNum: employeeData.employeeNum,
      firstName: employeeData.firstName,
      lastName: employeeData.lastName,
      email: employeeData.email,
      SSN: employeeData.SSN,
      addressStreet: employeeData.addressStreet,
      addressCity: employeeData.addressCity,
      addressState: employeeData.addressState,
      addressPostal: employeeData.addressPostal,
      maritalStatus: employeeData.maritalStatus,
      isManager: employeeData.isManager,
      employeeManagerNum: employeeData.employeeManagerNum,
      status: employeeData.status,
      department: employeeData.department,
      hireDate: employeeData.hireDate
    }).then(() =>{
      resolve();
    }).catch((err) =>{
      reject("unable to create employee");
    });
  });
}

module.exports.getManagers = function(){
  return new Promise((resolve, reject) => {
    reject();
  });
}

module.exports.getAllEmployees = function(){
  return new Promise((resolve, reject) => {
    Employee.findAll().then(()=>{
      resolve(Employee.findAll());
    }).catch((err) => {
       reject("no results returned");
    });
  });
}

module.exports.getDepartments = function(){
  return new Promise((resolve, reject) => {
    Department.findAll().then(()=>{
      resolve(Department.findAll());
    }).catch((err) => {
       reject("no results returned");
    });
  });
}

module.exports.getEmployeesByStatus = function(status){
  return new Promise((resolve, reject) => {
    Employee.findAll({
      where: {status: status}
    }).then(()=>{
      resolve(Employee.findAll({
        where: {status: status}
      }));
    }).catch((err) => {
       reject("no results returned");
    });
  });
}

module.exports.getEmployeesByDepartment = function(department){
  return new Promise((resolve, reject) => {
    Employee.findAll({
      where: {department: department}
    }).then(()=>{
      resolve(Employee.findAll({
        where: {department: department}
      }));
    }).catch((err) => {
       reject("no results returned");
    });
  });
}

module.exports.getEmployeesByManager = function(manager){
  return new Promise((resolve, reject) => {
    Employee.findAll({
      where: {employeeManagerNum: manager}
    }).then(()=>{
      resolve(Employee.findAll({
        where: {employeeManagerNum: manager}
      }));
    }).catch((err) => {
       reject("no results returned");
    });
  });
}

module.exports.getEmployeeByNum = function(num){
  return new Promise((resolve, reject) => {
    Employee.findAll({
      where: {employeeNum: num}
    }).then((data)=>{
      if(data.length > 0){
        resolve(data[0]);
      } else{
        reject("Employee not found");
      }
    }).catch((err) => {
       reject("no results returned");
    });
  });
}

module.exports.getDepartmentById = function(id){
  return new Promise((resolve, reject) => {
    Department.findAll({
      where: {departmentId: id}
    }).then((data)=>{
      if(data.length > 0){
        resolve(data[0]);
      } else{
        reject("Department not found");
      }
    }).catch((err) => {
       reject("no results returned");
    });
  });
}

module.exports.updateDepartment = function(departmentData){
  return new Promise((resolve, reject) => {
    for (const elem in departmentData) {
      departmentData[elem] == "" ? departmentData[elem] = null : departmentData[elem];
    }
    Department.update({
      departmentId: departmentData.departmentId,
      departmentName: departmentData.departmentName
    },{where: { departmentId: departmentData.departmentId}}).then(() =>{
      resolve();
    }).catch((err) =>{
      reject("unable to update department");
    });
  });
}

module.exports.updateEmployee = function(employeeData){
  return new Promise((resolve, reject) => {
    employeeData.isManager = (employeeData.isManager) ? true : false;
    for (const elem in employeeData) {
      employeeData[elem] == "" ? employeeData[elem] = null : employeeData[elem];
    }
    Employee.update({
      employeeNum: employeeData.employeeNum,
      firstName: employeeData.firstName,
      lastName: employeeData.lastName,
      email: employeeData.email,
      SSN: employeeData.SSN,
      addressStreet: employeeData.addressStreet,
      addressCity: employeeData.addressCity,
      addressState: employeeData.addressState,
      addressPostal: employeeData.addressPostal,
      maritalStatus: employeeData.maritalStatus,
      isManager: employeeData.isManager,
      employeeManagerNum: employeeData.employeeManagerNum,
      status: employeeData.status,
      department: employeeData.department,
      hireDate: employeeData.hireDate
    }, {where: { employeeNum: employeeData.employeeNum}}).then(() =>{
      resolve();
    }).catch((err) =>{
      reject("unable to create employee");
    });
  });
}

module.exports.deleteEmployeeByNum = function(empNum){
  return new Promise((resolve, reject) => {
    Employee.destroy({
      where: {employeeNum: empNum}
    }).then(()=>{
      resolve(Employee.destroy({
        where: {employeeNum: empNum}
      }));
    }).catch((err)=>{
      reject("unable to delete employee");
    });
  });
}

module.exports.deleteDepartmentById = function(depId){
  return new Promise((resolve, reject) => {
    Department.destroy({
      where: {departmentId: depId}
    }).then(()=>{
      resolve(Department.destroy({
        where: {departmentId: depId}
      }));
    }).catch((err)=>{
      reject("unable to delete department");
    });
  });
}
