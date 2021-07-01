-- Q1 --
-- Display the employee number, full employee name, job title, and hire date of all employees hired outside the Fall months (Sep, Oct, Nov), 
-- including only employees with ‘A’ jobs (their job title starts with A), but that title can not exceed 20 characters. 
-- Sort the output so that the most recently hired employees are displayed first. 

SELECT employee_id "Emp#",
       first_name || ' ' || last_name "Full Name",  
       job_title "Job",
       TO_CHAR(hire_date, 'fmDdspth "of" Month"," YYYY') "Start Date"
FROM employees
WHERE NOT(TO_CHAR(hire_date, 'MM') IN ('09', '10', '11'))
AND LENGTH(job_title) <= 20 
AND UPPER(job_title) LIKE 'A%'
ORDER BY hire_date DESC;

-- Q2 --
-- The company wants to see the total sale amount per sales person (salesman) for all orders. 
-- Display the salesman full name and the total sale amount for that employee. 
-- Exclude sales persons whose first name end on y (like Lily or Daisy).
-- Sort the result so that bigger sales are shown first.
-- Note; Do NOT use LIKE operator.

SELECT last_name || ', ' || first_name "Emp Name", 
       TO_CHAR(SUM(unit_price * quantity),
       CONCAT('$','999,999,999.99')) "Total Sale"
FROM employees e
JOIN orders o ON e.employee_id = o.salesman_id
JOIN order_items oi ON o.order_id = oi.order_id
WHERE SUBSTR(first_name, -1, 1) != 'y'
GROUP BY last_name || ', ' || first_name
ORDER BY 2 DESC;

-- Q3 --
-- Variation of Question 2.
-- The company wants to see the total sale amount per sales person (salesman) for all orders. 
-- Assume that some online orders do not have any sales person involved. Display the salesman full name and the total sale amount for that employee. 
-- Include also the Total Sale amount for all Orders without involvement of a salesman.
-- Exclude sales persons whose first name end on y (like Lily or Daisy).
-- Include only those sales persons who were responsible for more than 4 million dollars in sale.
-- Sort the result so that bigger sales are shown first.
-- Note; Do NOT use LIKE operator.

SELECT TO_CHAR(',') "Emp Name",
       TO_CHAR(SUM(unit_price * quantity),
       CONCAT('$','999,999,999.99')) "Total Sale"
FROM order_items oi
JOIN orders o ON oi.order_id = o.order_id
WHERE o.salesman_id IS NULL
UNION
SELECT last_name || ', ' || first_name "Emp Name", 
       TO_CHAR(SUM(unit_price * quantity),
       CONCAT('$','999,999,999.99')) "Total Sale"
FROM employees e
JOIN orders o ON e.employee_id = o.salesman_id
JOIN order_items oi ON o.order_id = oi.order_id
WHERE SUBSTR(first_name, -1, 1) != 'y'
GROUP BY last_name || ', ' || first_name
HAVING SUM(unit_price * quantity) > 4000000
ORDER BY 2 DESC;

-- Q4 --
-- Display number of orders for customers with name starting on B or L, but only if their total number of orders is less than 2.  
-- Include the customers with no orders in your report as well.
-- The report should show only customers who contain l in their name (if their name starts on B) 
-- and also customers who contain b in their name (if their name starts on L). Exclude Banks from your report (like Bank of New York Mellon).
-- Sort the result by the value of total orders ascending, followed by name ascending.
-- Note; Do NOT use LIKE operator.

SELECT c.customer_id "CustID", 
       c.name "Name",
       COUNT(o.customer_id) "Total Orders"
FROM customers c
FULL OUTER JOIN orders o ON c.customer_id = o.customer_id
WHERE INSTR(UPPER(name), 'BANK')= 0 
AND (SUBSTR(UPPER(name), 1, 1) = 'B'
AND INSTR(UPPER(name), 'L') >1)
OR (SUBSTR(UPPER(name), 1, 1) = 'L'
AND INSTR(UPPER(name), 'B') >1)
GROUP BY c.customer_id, c.name
HAVING COUNT(o.customer_id) < 2
ORDER BY 3, 2;

-- Q5 --
-- a. Display customer number, customer name, and the order id and the order date of all orders placed by contact persons from Area Phone Code 319 (Eastern Iowa in US). 
--    Be careful to avoid phone numbers having these digits somewhere else (like +1 212 319 4567). 
--    Show also the total number of items ordered, the total amount of each customer’s order and last name of the contact person.
-- b.	Exclude Orders with the Total Amount exceeding 800 thousand dollars
-- c.	Exclude orders placed by Contact person Norris.
-- d.	Sort the result from the highest to lowest total order amount.
-- Note: use Multiple Tables JOIN method with USING clause

SELECT customer_id "Cust#",
       name "Customer Name",
       order_id "Order#",
       order_date "Order Date",
       SUM(quantity) "Total#",
       TO_CHAR(SUM(quantity * unit_price),'$999,999.99') "Total Amount",
       last_name "LName"
FROM customers
JOIN contacts USING(customer_id)
JOIN orders USING(customer_id)
JOIN order_items USING(order_id)
WHERE phone LIKE '___319%'
AND UPPER(last_name) NOT IN 'NORRIS'
GROUP BY customer_id, name, order_id, order_date, last_name
HAVING SUM(quantity * unit_price) < 800000
ORDER BY 5 DESC;

-- Q6 --
-- Display Warehouse Id, warehouse name, product category Id, product category name, and the lowest product list price for this combination.
-- In your result, include the rows that the lowest list price is less then $50.
-- Also, include the rows that the lowest cost is more than $200.
-- Observe only warehouses that are located in Countries that start on C
-- Sort the output according to Warehouse Id and then product category Id

SELECT w.warehouse_id "Wrhs#",
       w.warehouse_name "Warehouse Name",
       pc.category_id "Category#",
       pc.category_name "Category Name",
       TO_CHAR(MIN(p.list_price), '$999.99') "Lowest Price"
FROM product_categories pc
JOIN products p ON pc.category_id = p.category_id
JOIN inventories i ON p.product_id = i.product_id
JOIN warehouses w ON i.warehouse_id = w.warehouse_id
JOIN locations l ON w.location_id = l.location_id
JOIN countries c ON l.country_id = c.country_id
WHERE w.location_id IN (SELECT lo.location_id
                        FROM locations lo
                        JOIN countries co USING(country_id)
                        WHERE UPPER(co.country_name) LIKE 'C%'
                        GROUP BY lo.location_id)
GROUP BY w.warehouse_id, w.warehouse_name, pc.category_id, pc.category_name
HAVING MIN(p.standard_cost) > 200
OR MIN(p.list_price) < 50
ORDER BY 1,3;

-- Q7 --
-- Display product Id, category Id, product Name, and list Price for products that were purchased in orders handled by salesmen 
-- whose last name begins on E or F, but only for product category that starts on Video. Sort the output by product Id ascending.
-- Note; You must NOT use JOIN method, just use SubQueries. Also you must use LIKE operator (not SUBSTR or INSTR).

SELECT product_id "ProdId",
       category_id "Category#",
       product_name "Product Name",
       list_price "Lprice"
FROM products
WHERE category_id IN (SELECT category_id
                      FROM product_categories
                      WHERE UPPER(category_name) LIKE 'VIDEO%')
AND product_id IN (SELECT product_id
                   FROM order_items
                   WHERE order_id IN (SELECT order_id 
                                      FROM orders
                                      WHERE salesman_id IN (SELECT employee_id
                                                            FROM employees
                                                            WHERE UPPER(last_name) LIKE 'E%'
                                                            OR UPPER(last_name) LIKE 'F%')))
ORDER BY 1;

-- Q8 --
-- Variation of Q7
-- Display product Id, product Name, and list Price for products that were purchased in orders handled by salesmen 
-- whose last name begins on E or F and who were hired in December of any year, but only for product category that starts on Video.
-- Include only products with list Price smaller than Any Average Price per product Category. Sort the output by product Id ascending.
-- Note; You must NOT use JOIN method, just SubQueries. Also, you must NOT use LIKE operator.

SELECT product_id "ProdId",
       product_name "Product Name",
       list_price "Lprice"
FROM products
WHERE category_id IN (SELECT category_id
                      FROM product_categories
                      WHERE UPPER(category_name) LIKE 'VIDEO%')
AND product_id IN (SELECT product_id
                   FROM order_items
                   WHERE order_id IN (SELECT order_id 
                                      FROM orders
                                      WHERE salesman_id IN (SELECT employee_id
                                                            FROM employees
                                                            WHERE UPPER(last_name) LIKE 'E%'
                                                            OR UPPER(last_name) LIKE 'F%'
                                                            AND TO_CHAR(hire_date, 'MM') = '12')))
AND list_price < ANY (SELECT AVG(list_price)
                      FROM products
                      GROUP BY category_id)
ORDER BY 1;

-- Q9 --
-- Display product Id, product Name, and list Price for products that their list price is less than Any lowest product standard cost per warehouse inside regions of Europe or Asia.
-- (You need to find the lowest standard cost for each warehouse that is located inside these two regions. 
-- Then you need to return all products that their list price is less than any lowest standard cost of those warehouses.). 
-- Include only products with Quantity greater than Any highest quantity per warehouse (anywhere).
-- Sort the result according to list price descending.
-- Note; You should use both methods here, Subquery first, then followed by JOIN/USING method.

SELECT p.product_id "Product ID",
       p.product_name "Product Name",
       TO_CHAR(p.list_price, '$999.99') "List Price"
FROM products p JOIN inventories i ON p.product_id = i.product_id
WHERE p.list_price < ANY (SELECT list_price
                          FROM products
                          WHERE p.list_price < ANY (SELECT MIN(standard_cost)
                                                       FROM products pr
                                                       JOIN inventories i USING(product_id)
                                                       JOIN warehouses w ON i.warehouse_id = w.warehouse_id
                                                       JOIN locations l USING(location_id)
                                                       JOIN countries c USING(country_id)
                                                       JOIN regions r USING(region_id)
                                                       WHERE UPPER(r.region_name) IN ('EUROPE', 'ASIA')
                                                       GROUP BY w.warehouse_id))
AND i.quantity > ANY (SELECT MAX(quantity)
                      FROM inventories
                      WHERE warehouse_id IN (SELECT warehouse_id
                                             FROM warehouses)
                      GROUP BY warehouse_id)
GROUP BY p.product_id, p.product_name, p.list_price
ORDER BY 3 DESC;