SET SERVEROUTPUT ON;

-- Q1 --
-- Write a store procedure called Get_Fact that gets an integer number n and calculates and displays its factorial.
CREATE OR REPLACE PROCEDURE Get_Fact(n INTEGER) AS
factorial INTEGER := 1;
BEGIN
    FOR i IN REVERSE 1..n LOOP
        factorial := factorial * i;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(n || '! = ' || factorial);
END;
/
BEGIN
  Get_Fact(1);
  Get_Fact(12);
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/

-- Q2 --
-- The company wants to calculate the employees’ annual salary:
-- The first year of employment, the amount of salary is his/her base salary (shown under column Salary).
-- Every year after that, the salary increases by 5%.
-- Write a stored procedure named Calculate_Salary which gets an Employee ID and 
-- for that employee calculates the salary based on the number of years the employee has been working in the company. 
-- (Use a loop construct to calculate the salary).
-- The procedure calculates and prints the Name and Annual Salary
-- If the employee does not exist, the procedure displays a proper message.
CREATE OR REPLACE PROCEDURE Calculate_Salary(empID employee.employee_id%type) AS
  emp employee%rowtype;
  new_salary employee.salary%type;
  years_worked INTEGER := 0;
BEGIN
  SELECT * INTO emp
  FROM employee
  WHERE employee_id = empID;
  new_salary := emp.salary;
  years_worked := trunc(MONTHS_BETWEEN(SYSDATE, emp.hire_date) / 12);
  FOR year IN 1..years_worked LOOP
    new_salary := new_salary * 1.05;
  END LOOP;
  DBMS_OUTPUT.PUT_LINE('First Name: ' || emp.first_name);
  DBMS_OUTPUT.PUT_LINE('Last Name: ' || emp.last_name);
  DBMS_OUTPUT.PUT_LINE('Annual Salary: $' || to_char(new_salary, '$99,999'));
  EXCEPTION WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('Employee (ID: ' || empID || ') does not exist.');
END;
/
BEGIN
  Calculate_Salary(0);
  Calculate_Salary(124);
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/

-- Q3 --
-- Write the code for the procedure called Find_Prod_price, that will search table Products 
-- and for a given Product ID will find its Description and display a message (note) regarding its List Price.
-- This note will show Cheap for price below $200, Not Expensive for price between $200 and $500, 
-- otherwise will be Expensive (for price higher than $500). You need to take care of the wrong input (Product ID is invalid) as well.  
-- Use one IN parameter and two OUT parameters, then use PL/SQL block to show your output
CREATE OR REPLACE PROCEDURE Find_Prod_price(productID IN products.product_id%type, d OUT VARCHAR2, note OUT VARCHAR2) AS
  price products.list_price%type;
BEGIN 
  SELECT description, list_price INTO d, price
  FROM products
  WHERE productID = product_id;
    CASE 
      WHEN price < 200 THEN
           note := 'Cheap';
      WHEN price BETWEEN 200 AND 500 THEN
           note := 'Not Expensive';
      WHEN price > 500 THEN 
           note := 'Expensive';
    END CASE;
  DBMS_OUTPUT.PUT_LINE(d || ' is ' || note);
  EXCEPTION WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('Invalid Product ID: ' || productID);
END;
/
  var p_desc VARCHAR2(200);
  var p_note VARCHAR2(200);
BEGIN
  Find_Prod_Price(94, :p_desc, :p_note);
  Find_Prod_Price(64, :p_desc, :p_note);
  Find_Prod_Price(0, :p_desc, :p_note);
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/
-- Q4 --
-- Write a stored procedure named Warehouses_Report to print the warehouse ID, warehouse name, and the city where the warehouse is located in the following format for ALL warehouses
-- If the value of state does not exist (null), display “no state”.
-- The value of warehouse ID ranges from 1 to 9.
-- You can use a loop to find and display the information of each warehouse inside the loop.
-- (Use a loop construct to answer this question. Do not use cursors.) 
CREATE OR REPLACE PROCEDURE Warehouses_Report AS
  w_ID warehouses.warehouse_id%type;
  w_name warehouses.warehouse_name%type;
  w_city locations.city%type;
  w_state locations.state%type;
BEGIN
  FOR i IN 1..9 LOOP
    SELECT warehouse_id, warehouse_name, city, NVL(state, 'no state') INTO w_ID, w_name, w_city, w_state
    FROM warehouses JOIN locations USING(location_id)
    WHERE warehouse_id = i;  
    DBMS_OUTPUT.PUT_LINE('Warehouse ID:   ' || w_ID);
    DBMS_OUTPUT.PUT_LINE('Warehouse Name: ' || w_name);
    DBMS_OUTPUT.PUT_LINE('City:           ' || w_city);
    DBMS_OUTPUT.PUT_LINE('State:          ' || w_state);
    DBMS_OUTPUT.PUT_LINE(' ');
  END LOOP;
END;
/
BEGIN
  Warehouses_Report();
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/
