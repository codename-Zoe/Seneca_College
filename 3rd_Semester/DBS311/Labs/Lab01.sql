-- Q1 --
-- Write a query to display the After-tomorrow’s date in the following format:
-- September 28th of year 2016
-- Your result will depend on the day when you create this query.
-- Label the column "After Tomorrow".
SELECT TO_CHAR(sysdate + 2, 'fmMonth ddth "of year" YYYY') "After Tomorrow"
FROM dual;

-- Q2 --
-- For each employee in departments 50 and 60 display last name, first name, salary, and salary increased by 7% and expressed as a whole number.
-- Label the column "Good Salary". 
-- Also add a column that subtracts the old salary from the new salary and multiplies by 12. 
-- Label the column "Annual Pay Increase".
SELECT last_name,
       first_name,
       salary * 1.07 "Good Salary",
       (salary * 1.07 - salary) * 12 "Annual Pay Increse"
FROM employee
WHERE department_id IN (50, 60);

-- Q3 --
-- Write a query that displays the employee’s Full Name and Job Title in the following format:
-- "DAVIES, CURTIES is Store Clerk" 
-- for all employees whose last name ends with S and first name starts with  C or K.
-- Give this column an appropriate label like Person and Job
-- Sort the result by the employees’ last names.
SELECT UPPER(last_name)||','||UPPER(first_name)||' is '||
       DECODE(job_id, 'ST_CLERK', 'Store Clerk',
                      'ST_MAN', 'Store Manager') "Person and Job"
FROM employee
WHERE last_name LIKE '%s' AND (first_name LIKE 'C%' OR first_name LIKE'K%')
ORDER BY last_name;

-- Q4 --
-- For each employee hired before 1992 who is earning more than $10000, 
-- display the employee’s last name, salary, hire date and calculate the number of YEARS between TODAY 
-- and the date the employee was hired. Round the number of years up to the closest whole number. 
-- Label the column "Years Worked". 
-- Order your results by the highest paid people first and then by number of years employed. 
SELECT last_name "Last Name", 
       salary "Salary",
       hire_date "Hire Date",
       ROUND(MONTHS_BETWEEN(sysdate, hire_date)/12, 0) "Years Worked"
FROM employee
WHERE hire_date < '01-JAN-92' 
AND salary > 10000
ORDER BY salary DESC;

-- Q5 --
-- Create a query that displays the city names, country codes and state province names, 
-- but only for those cities that start on S and have at least 8 characters in their name. 
-- If city does not have province name assigned, then put "Unknown Province".
SELECT city "City",
       country_id "Country#",
       NVL(state_province, 'Unknown Province') "State Province"
FROM location
WHERE city LIKE 'S%' AND LENGTH(city) >= 8;

-- Q6 --
-- Display each employee’s last name, hire date, and salary review date, which is the first Tuesday after a year of service, but only for those hired after 1997.
-- Label the column "REVIEW DAY". 
-- Format the dates to appear in the format similar to 
-- "TUESDAY, August the Thirty-First of year1998"
SELECT last_name "Last Name",
       hire_date "Hire Date",
       TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date, 12), 'Tuesday'),
       'fmDAY, Month "the"Ddspth "of year"YYYY') "Review Day"
FROM employee
WHERE hire_date > TO_DATE('31-DEC-1997', 'DD-Mon-YYYY');