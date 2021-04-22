SET AUTOCOMMIT ON;

-- Q1 SOLUTION --
CREATE TABLE employee2 (
    employeenumber NUMBER(38,0) NOT NULL,
    lastname VARCHAR2(50) NOT NULL,
    firstname VARCHAR2(50) NOT NULL,
    extension VARCHAR2(10) NOT NULL,
    email VARCHAR2(100) NOT NULL,
    officecode VARCHAR2(100) NOT NULL,
    reportsto NUMBER(38,0),
    jobtitle VARCHAR2(50) NOT NULL,
    CONSTRAINT EMPLOYEEUNMBER_PK PRIMARY KEY (employeenumber)
    );

-- Q2 SOLUTION -- 
ALTER TABLE employee2
ADD CONSTRAINT REPORTSTO_FK FOREIGN KEY (reportsto) REFERENCES employee2;

-- Q3 SOLUTION --
INSERT INTO employee2
SELECT * FROM employees;

-- Q4 SOLUTION --
INSERT INTO employee2 (EMPLOYEENUMBER,LASTNAME,FIRSTNAME,EMAIL,EXTENSION,JOBTITLE,OFFICECODE,REPORTSTO)
VALUES (1750,'Tsuchiya','Nozomi','ntsuchiya1@myseneca.ca','x2222','Head Cashier','4',1088);

-- Q5 SOLUTION -- 
INSERT INTO employee2 (EMPLOYEENUMBER,LASTNAME,FIRSTNAME,EMAIL,EXTENSION,JOBTITLE,OFFICECODE,REPORTSTO)
VALUES (1760,'King','Steven','Steven.k@myseneca.ca','x100','Cashier','5',1750);

-- Q6 SOLUTION --
--DELETE FROM employee2 WHERE EMPLOYEENUMBER = 1750;

-- Q7 SOLUTION --
DELETE FROM employee2 WHERE EMPLOYEENUMBER = 1760;
DELETE FROM employee2 WHERE EMPLOYEENUMBER = 1750;

-- Q8 SOLUTION --
INSERT ALL
INTO employee2 VALUES (1750,'Tsuchiya','Nozomi','x2222','ntsuchiya1@myseneca.ca','4',1088,'Head Cashier')
INTO employee2 VALUES (1760,'King','Steven','x100','Steven.k@myseneca.ca','5',1088,'Cashier')
SELECT * FROM dual;
       
-- Q9 SOLUTION --
DELETE FROM employee2 WHERE EMPLOYEENUMBER IN (1750,1760);

-- Q10 SOLUTION --
UPDATE employee2
   SET LASTNAME = 'Tsuchiya',
       FIRSTNAME = 'Nozomi'
WHERE EMPLOYEENUMBER = 1002;

-- Q11 SOLUTION --
DELETE FROM employee2;

-- Q12 SOLUTION --
DROP TABLE employee2;



