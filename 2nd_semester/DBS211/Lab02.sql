-- Q1 Solution --
SELECT officecode, city, state, country, phone
FROM offices;

-- Q2 Solution –
SELECT employeenumber, firstname, lastname, extension
FROM employees
WHERE officecode = 1
ORDER BY employeenumber;

-- Q3 Solution -
SELECT customernumber,
       customername,
       contactfirstname,
       contactlastname,
       phone
FROM customers
WHERE LOWER (city) = 'paris'
ORDER BY customernumber;

-- Q4 Solution -
SELECT customernumber,
       customername,
       contactlastname || ',' || contactfirstname AS contactname,
       phone
FROM customers
WHERE LOWER (country) = 'canada'
ORDER BY customername;

-- Q5 Solution -
SELECT customernumber
FROM customers
WHERE creditlimit > 0
ORDER BY customernumber
FETCH NEXT 10 ROWS ONLY;

-- Q6 Solution -
SELECT customernumber,
       checknumber,
       amount
FROM payments
WHERE amount NOT BETWEEN 1500 AND 120000 --amount < 1500 OR 120000 < amount
ORDER BY amount DESC;

-- Q7 Solution
SELECT productcode,
       productname,
       buyprice,
       msrp,
       (msrp - buyprice) AS markup,
       ROUND(100 * ((msrp - buyprice) / buyprice),1) AS percmarkup       
FROM products
WHERE 100 * ((msrp - buyprice) / buyprice) > 140.0
ORDER BY percmarkup ASC;

-- Q8 Solution -
SELECT REPLACE(productcode, '_', ' ') AS productcode, --productcode,
       productname,
       quantityinstock
FROM products
WHERE UPPER(productname) LIKE '%CO%'
ORDER BY quantityinstock;

-- Q9 Solution -
SELECT customernumber,
       contactfirstname,
       contactlastname
FROM customers
WHERE UPPER(contactfirstname) LIKE 'S%E%'
ORDER BY customernumber;