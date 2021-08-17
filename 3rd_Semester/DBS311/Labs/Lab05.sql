SET SERVEROUTPUT ON;

-- Q1 --
-- Write a store procedure called Even_Odd that gets an integer number and prints
-- "The number is even."
-- If a number is divisible by 2. Otherwise, it prints 
-- "The number is odd."
CREATE OR REPLACE PROCEDURE Even_Odd (value IN INT) AS    
BEGIN   
IF MOD(value,2) = 0 THEN     
 DBMS_OUTPUT.PUT_LINE ('The number is even');   
ELSE    
 DBMS_OUTPUT.PUT_LINE ('The number is odd');   
END IF;   
END;
/
DECLARE
 value INT :=100;  
BEGIN   
  Even_Odd(value);
END;
/
DECLARE
 value INT :=99;  
BEGIN   
  Even_Odd(value);
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/
ROLLBACK;
/

-- Q2 --
-- Create a stored procedure named Find_Employee. This procedure gets an employee number and prints the following employee information:
-- First name 
-- Last name 
-- Email
-- Phone 	
-- Hire date 
-- Job title
-- The procedure gets a value as the employeeID of type NUMBER.
-- The procedure displays a proper error message if any error occurs.
CREATE OR REPLACE PROCEDURE Find_Employee(employeeID NUMBER) AS
  firstName VARCHAR2(255 BYTE);
  lastName VARCHAR2(255 BYTE);
  email VARCHAR2(255 BYTE);
  phone VARCHAR2(255 BYTE);
  hireDate VARCHAR2(255 BYTE);
  jobTitle VARCHAR2(255 BYTE);
BEGIN
  SELECT first_name, last_name,email,phone,hire_date,job_title INTO firstName, lastName, email, phone, hireDate, jobTitle
  FROM employees
  WHERE employee_id = employeeID;
  DBMS_OUTPUT.PUT_LINE ('First name: ' || firstName);
  DBMS_OUTPUT.PUT_LINE ('Last name: ' || lastName);
  DBMS_OUTPUT.PUT_LINE ('Email: ' || email);
  DBMS_OUTPUT.PUT_LINE ('Phone: ' || phone);
  DBMS_OUTPUT.PUT_LINE ('Hire date: ' || hireDate);
  DBMS_OUTPUT.PUT_LINE ('Job title: ' || jobTitle);
EXCEPTION
WHEN OTHERS
  THEN 
      DBMS_OUTPUT.PUT_LINE ('Error!');
END;
/
DECLARE
 ID NUMBER := 107;  
BEGIN   
  Find_Employee(ID);
END;
/
DECLARE
 ID NUMBER := 99999;  
BEGIN   
  Find_Employee(ID);
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/
ROLLBACK;
/

-- Q3 --
-- Every year, the company increases the price of all products in one category. For example, the company wants to increase the price (list_price) of products in category 1 by $5. 
-- Write a procedure named Update_Price_by_Cat to update the price of all products in a given category and the given amount to be added to the current price if the price is greater than 0.
-- The procedure shows the number of updated rows if the update is successful or shows 0 rows updated, if the input was an invalid category Id.
-- The procedure gets two parameters:
-- *category_id IN NUMBER
-- *amount NUMBER(9,2)
-- Make sure the type of your variable is compatible with the value that is stored in your variable.
-- To show the number of affected rows the update query, declare a variable named rows_updated of type NUMBER and use the SQL variable sql%rowcount to set your variable. 
-- Then, print its value in your stored procedure.
-- *Rows_updated := sql%rowcount;
-- SQL%ROWCOUNT stores the number of rows affected by an INSERT, UPDATE, or DELETE
CREATE OR REPLACE PROCEDURE Update_Price_by_Cat (id products.category_id%type,amount NUMBER) AS
  Rows_updated NUMBER;
BEGIN
  UPDATE PRODUCTS SET List_price = List_price + amount
  WHERE CATEGORY_ID = id
  AND LIST_PRICE > 0;
        Rows_updated := sql%rowcount;
  IF (Rows_updated = 0) then
        DBMS_OUTPUT.PUT_LINE ('Invalid Category ID');
  ELSE 
        DBMS_OUTPUT.PUT_LINE ('The number of updated rows is: ' || Rows_updated);
  END IF; 
EXCEPTION
WHEN OTHERS
  THEN 
      DBMS_OUTPUT.PUT_LINE ('Error!');
END;
/
DECLARE
  A NUMBER :=1;
  B NUMBER :=5;
  BEGIN
    Update_Price_by_Cat (A,B);
  END;
/
DECLARE
  A NUMBER :=99999;
  B NUMBER :=5;
  BEGIN
    Update_Price_by_Cat (A,B);
    DBMS_OUTPUT.PUT_LINE('==========================================================');
    DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/
ROLLBACK;
/

-- Q4 --
-- Every year, the company increase the price of products whose price is less than the average price of all products by 1%. (list_price * 1.01). 
-- Write a stored procedure named Update_Price_Under_Avg. This procedure does not have any parameters. 
-- If the average price is less than or equal to $1000, update products’ price by 2% if the price of the product is less than the calculated average. 
-- If the average price is greater than $1000, update products’ price by 1% if the price of the product is less than the calculated average. 
-- The query displays an error message if any error occurs. Otherwise, it displays the number of updated rows.
CREATE OR REPLACE PROCEDURE Update_Price_Under_Avg AS
  avg_price products.list_price%type;
  updated_row NUMBER;
BEGIN
  SELECT AVG(list_price) INTO avg_price
  FROM products;
IF avg_price <= 1000 THEN
  UPDATE products SET list_price = (list_price * 1.02)
  WHERE list_price < avg_price;
  updated_row := sql%rowcount;
ELSE
  UPDATE products SET list_price = (list_price * 1.01)
  WHERE list_price < avg_price;
  updated_row := sql%rowcount;
END IF;
  DBMS_OUTPUT.PUT_LINE('The number of updated row is: ' || updated_row);
EXCEPTION 
WHEN OTHERS
  THEN
    DBMS_OUTPUT.PUT_LINE('Error!');
END;
/
BEGIN
  Update_Price_Under_Avg;
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/
ROLLBACK;
/

-- Q5 --
-- The company needs a report that shows three category of products based their prices. The company needs to know if the product price is cheap, fair, or expensive. 
-- Let’s assume that
-- If the list price is less than 
-- -> (avg_price - min_price) / 2
-- The product’s price is cheap.
-- If the list price is greater than 
-- -> (max_price - avg_price) / 2
-- The product’ price is expensive.
-- If the list price is between 
-- -> (avg_price - min_price) / 2 and (max_price - avg_price) / 2 (the end values included)
-- The product’s price is fair.
-- Write a procedure named Product_Price_Report to show the number of products in each price category
-- The procedure has no parameter.
-- First, you need to find the average, minimum, and maximum prices (list_price) in your database and store them into varibles avg_price, min_price, and max_price.
CREATE OR REPLACE PROCEDURE Product_Price_Report AS
  avg_price NUMBER(6,2);
  min_price NUMBER(6,2);
  max_price NUMBER(6,2);
  cheap_count NUMBER := 0;
  fair_count NUMBER := 0;
  exp_count NUMBER := 0;
BEGIN
  SELECT AVG(list_price) INTO avg_price FROM products; 
  SELECT MIN(list_price) INTO min_price FROM products; 
  SELECT MAX(list_price) INTO max_price FROM products;
FOR elem IN (SELECT list_price FROM products)
LOOP
  IF elem.list_price < (avg_price - min_price) / 2 THEN
    cheap_count := cheap_count + 1;
  ELSIF elem.list_price > (max_price - avg_price) / 2 THEN
    exp_count := exp_count + 1;
  ELSE
    fair_count := fair_count + 1;
  END IF;
END LOOP;
  DBMS_OUTPUT.PUT_LINE('Cheap: ' || cheap_count);
  DBMS_OUTPUT.PUT_LINE('Fair: ' || fair_count);
  DBMS_OUTPUT.PUT_LINE('Expensive: ' || exp_count);
EXCEPTION 
WHEN OTHERS
  THEN
    DBMS_OUTPUT.PUT_LINE('Error!');
END;
/
BEGIN
  Product_Price_Report;
  DBMS_OUTPUT.PUT_LINE('==========================================================');
  DBMS_OUTPUT.PUT_LINE('Execute time: ' || CURRENT_TIMESTAMP);
END;
/
ROLLBACK;
/
