-- Q1 Solution --
CREATE TABLE new_employees(
     employeenumber NUMBER(38,0) PRIMARY KEY,
     lastname VARCHAR2(50) NOT NULL,
     firstname VARCHAR2(50) NOT NULL,
     extension VARCHAR2(10) NOT NULL,
     email VARCHAR2(100) NOT NULL,
     officecode VARCHAR2(10) NOT NULL,
     reportsto NUMBER (38,0) default NULL,
     jobtitle VARCHAR2(50) NOT NULL,
     CONSTRAINT OFFICE_CODE_FK FOREIGN KEY (officecode) REFERENCES offices (officecode),
     CONSTRAINT REPORTSTO_FK FOREIGN KEY (reportsto) REFERENCES employees (employeenumber)
);

-- Q2 Solution --
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

-- Q3 Solution --
INSERT ALL
INTO new_employees VALUES ('100', 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
INTO new_employees VALUES ('101', 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
INTO new_employees VALUES ('102', 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
INTO new_employees VALUES ('103', 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
INTO new_employees VALUES ('104', 'Ropeburn', 'Audrey', '77888' , 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;

-- Q4 Solution --
SELECT * FROM new_employees;
-- 5 rows are fetched

-- Q5 Solution --
ROLLBACK;
SELECT * FROM new_employees; 

-- Q6 Solution --
INSERT ALL
INTO new_employees VALUES ('100', 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
INTO new_employees VALUES ('101', 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
INTO new_employees VALUES ('102', 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
INTO new_employees VALUES ('103', 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
INTO new_employees VALUES ('104', 'Ropeburn', 'Audrey', '77888' , 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;
COMMIT;
SELECT * FROM new_employees;

-- Q7 Solution --
UPDATE new_employees SET jobtitle = 'unknown'; 

-- Q8 Solution --
COMMIT;

-- Q9 Solution --
ROLLBACK;

-- Q9-a Solution --
SELECT * FROM new_employees WHERE jobtitle = 'unknown';

-- Q9-b Solution --
-- ROLLBACK was not effective.

-- Q9-c Solution --
-- I placed COMMIT after Q7 and this means the change of Q7 is permanent.

-- Q10 Solution --
COMMIT;
TRUNCATE TABLE new_employees;

-- Q11 Solution --
CREATE VIEW vw_new_emps AS
SELECT *
FROM new_employees
ORDER BY lastname, firstname;

-- Q12 Solution --
ROLLBACK;

-- Q12-a Solution --
SELECT * FROM new_employees;

-- Q12-b Solution --
-- Deletion was done because TRUNCATE is a DDL and it commits automatically.

-- Q13 Solution --
COMMIT;
INSERT ALL
INTO new_employees VALUES ('100', 'Patel', 'Ralph', '22333', 'rpatel@mail.com', '1', NULL, 'Sales Rep')
INTO new_employees VALUES ('101', 'Denis', 'Betty', '33444', 'bdenis@mail.com', '4', NULL, 'Sales Rep')
INTO new_employees VALUES ('102', 'Biri', 'Ben', '44555', 'bbirir@mail.com', '2', NULL, 'Sales Rep')
INTO new_employees VALUES ('103', 'Newman', 'Chad', '66777', 'cnewman@mail.com', '3', NULL, 'Sales Rep')
INTO new_employees VALUES ('104', 'Ropeburn', 'Audrey', '77888' , 'aropebur@mail.com', '1', NULL, 'Sales Rep')
SELECT * FROM dual;

-- Q14 Solution --
SAVEPOINT insertion;

-- Q15 Solution --
UPDATE new_employees SET jobtitle = 'unknown';
SELECT * FROM new_employees;

-- Q16 Solution --
ROLLBACK TO insertion;
SELECT * FROM new_employees; 

-- Q17 Solution --
ROLLBACK;
SELECT * FROM new_employees;

-- Q18 Solution --
REVOKE ALL ON new_employees FROM PUBLIC;

-- Q19 Solution --
GRANT SELECT ON new_employees TO dbs211_211h02;

-- Q20 Solution --
GRANT INSERT, UPDATE, DELETE ON new_employees TO dbs211_211h02;

-- Q21 Solution --
REVOKE ALL ON new_employees FROM dbs211_211h02;

-- Q22 Solution --
DROP VIEW vw_new_emps;
DROP TABLE new_employees;


