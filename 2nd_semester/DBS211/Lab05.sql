-- Q1 Solution --
SELECT employeenumber,
       firstname,
       lastname,
       city,
       phone,
       postalcode
FROM employees INNER JOIN offices
USING (officecode)
WHERE LOWER (country) = 'france'
ORDER BY 1;

-- Q2 Solution –-
SELECT *
FROM payments INNER JOIN customers
USING (customernumber)
WHERE LOWER (country) = 'canada';

-- Q2 a SOLUTION --
SELECT *
FROM payments INNER JOIN customers
USING (customernumber)
WHERE LOWER (country) = 'canada'
ORDER BY customernumber;

-- Q2 b SOLUTION --
SELECT customernumber,
       customername,
       paymentdate,
       amount
FROM payments INNER JOIN customers
USING (customernumber)
WHERE LOWER (country) = 'canada'
ORDER BY 1;

-- Q2 c SOLUTION --
SELECT customernumber,
       customername,
       TO_CHAR(paymentdate,'Mon DD, YYYY') AS paymentdate,
       amount
FROM payments INNER JOIN customers
USING (customernumber)
WHERE LOWER (country) = 'canada'
ORDER BY 1;

-- Q3 Solution --
SELECT employeenumber,
       firstname||' '||lastname AS employeename,
       email
FROM customers c RIGHT OUTER JOIN employees e
ON c.salesrepemployeenumber = e.employeenumber
WHERE c.salesrepemployeenumber IS NULL
ORDER BY 2;

-- Q4 a Solution --
CREATE VIEW vw_customer_order AS 
SELECT o.customernumber, o.ordernumber, o.orderdate, p.productname, d.quantityordered, d.priceeach
FROM orderdetails d, orders o, products p
WHERE d.ordernumber = o.ordernumber
AND d.productcode = p.productcode;

-- Q4 b Solution --
SELECT * FROM vw_customer_order
ORDER BY 1;

-- Q5 Solution --
CREATE OR REPLACE VIEW vw_customer_order AS
SELECT o.customernumber, o.ordernumber, o.orderdate, p.productname, d.quantityordered, d.priceeach, d.orderlinenumber
FROM orderdetails d, orders o, products p
WHERE d.ordernumber = o.ordernumber
AND d.productcode = p.productcode
AND customernumber = 124;

SELECT * FROM vw_customer_order
ORDER BY ordernumber, orderlinenumber;

-- Q6 Solution --
SELECT c.customernumber,
       c.contactfirstname,
       c.contactlastname,
       c.phone,
       c.creditlimit
FROM  customers c LEFT OUTER JOIN orders o
ON c.customernumber = o.customernumber
WHERE o.customernumber IS NULL
ORDER BY 1;

-- Q7 Solution --
CREATE VIEW vw_employee_manager AS
SELECT l.*, r.firstname || ' ' ||r.lastname AS managername
FROM employees l LEFT OUTER JOIN employees r
ON l.reportsto = r.employeenumber
ORDER BY l.employeenumber;

-- Q8 Solution --
CREATE OR REPLACE VIEW vw_employee_manager AS
SELECT l.*, r.firstname || ' ' ||r.lastname AS managername
FROM employees l LEFT OUTER JOIN employees r
ON l.reportsto = r.employeenumber
WHERE l.reportsto IS NOT NULL
ORDER BY l.employeenumber;

-- Q9 Solution --
DROP VIEW vw_customer_order;
DROP VIEW vw_employee_manager;