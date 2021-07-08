-- Q1 --
-- The HR department needs a list of Department IDs for departments that do not contain the job ID of ST_CLERK. 
-- Exclude NULL departments from your result. Use a set operator to create this list.
SELECT department_id "Dept#"
FROM	department 
WHERE department_id IS NOT NULL
MINUS
SELECT department_id
FROM employee
WHERE	job_id = 'ST_CLERK';

-- Q2 --
-- Display list with employee’s Id, Job Id and Salary that will include the current job and salary and all previous Jobs,
-- if they have them (here you will display salary of -1). 
-- Use a set operator for this report.
SELECT employee_id "Employee#",
       job_id "Job#",
       salary "Salary"
FROM employee
UNION ALL
SELECT employee_id, job_id, TO_NUMBER(-1)
FROM job_history
ORDER BY 1;

-- Q3 --
-- Display cities that no warehouse is located in them. Use set operator to answer this question.
SELECT city "City"
FROM locations
MINUS
SELECT l.city
FROM locations l JOIN warehouses w USING(location_id);

-- Q4 --
-- Display the category ID, category name, and the number of products in category 1, 2, and 5.
-- In your result, display first the number of products in category 5, then category 1 and then 2.
-- Use ANY method to solve this problem.
SELECT pc.category_id "Category#",
       pc.category_name "Category Name",
       COUNT(p.product_id) "Num of products"
FROM product_categories pc
JOIN products p ON pc.category_id = p.category_id
WHERE pc.category_id = 5
GROUP BY pc.category_id, pc.category_name
UNION ALL
SELECT pc.category_id, pc.category_name, COUNT(p.product_id) "Num of products"
FROM product_categories pc
JOIN products p ON pc.category_id = p.category_id
WHERE pc.category_id = 1
GROUP BY pc.category_id, pc.category_name
UNION ALL
SELECT pc.category_id, pc.category_name, COUNT(p.product_id) "Num of products"
FROM product_categories pc
JOIN products p ON pc.category_id = p.category_id
WHERE pc.category_id = 2
GROUP BY pc.category_id, pc.category_name;

-- Q5 --
-- Display product ID for ordered products whose quantity in the inventory is greater than 250.
-- (You are not allowed to use JOIN for this question.)
SELECT product_id "Product#"
FROM order_items
INTERSECT
SELECT product_id
FROM inventories
WHERE quantity > 250;

-- Q6 --
-- We need a single report to display all warehouses and the city and state that they are located in,
-- also all states regardless of whether they have warehouses in them or not.
--If state value is blank, display "No State".
SELECT location_id "Loc#",
       city "City", 
       NVL(state, 'No State') "State", 
       TO_CHAR(null) "Warehouse"
FROM locations
UNION 
SELECT location_id, TO_CHAR(null), TO_CHAR(null), warehouse_name
FROM warehouses;
