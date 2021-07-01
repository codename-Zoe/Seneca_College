-- Q1 --
-- Display last name and job title for all employees who perform the same job as Davies. 
-- Exclude "Davies" from this query.
SELECT last_name "Last Name",
       job_id "Job#"
FROM employee
WHERE job_id = (SELECT job_id
                FROM employee
                WHERE last_name = 'Davies')
AND last_name <> 'Davies';

-- Q2 --
-- Display last name, job title and hire date for all employees hired after Grant.
-- Sort the output by the most recent hire date.
SELECT last_name "Last Name",
       job_id "Job#",
       hire_date "Hire Date"
FROM employee
WHERE hire_date > (SELECT hire_date
                   FROM employee
                   WHERE last_name = 'Grant')
ORDER BY 3 DESC;

-- Q3 --
-- Display city, province name, postal code and country code for all cities located in countries with NAMES 
-- (not Country Codes) starting on letter I (meaning  Italy, Israel and India). 
-- If the province is blank, show message "Unknown". 
-- Heading sample should be like:
-- City, Province, PCode, CC
-- Sort the output by city ascending. Do NOT use Join method.
SELECT city "City",
       NVL(state_province, 'Unknown') "Province",
       postal_code "Pcode",
       country_id "CC"
FROM location
WHERE country_id IN (SELECT country_id
                     FROM country
                     WHERE country_name LIKE 'I%')
ORDER BY 1 ASC;

-- Q4 --
-- Display last name, job title and salary for all employees who earn less than the Average salary in the Sales department. 
-- Do NOT use Join method.Sort the output by top salaries first and then by job_title. 
SELECT last_name "Last Name",
       job_id "Job#",
       salary "Salary"
FROM employee
WHERE salary < (SELECT AVG(salary)
                FROM employee
                WHERE department_id = (SELECT department_id
                                       FROM department
                                       WHERE UPPER(department_name) = 'SALES'))
ORDER BY 3 DESC, 2;

-- Q5 --
-- Display last name, job title and salary for all employees whose salary matches
-- any of the salaries from the IT Department. Do NOT use Join method.
-- Sort the output by salary ascending first and then by last_name.
SELECT last_name "Last Name",
       job_id "Job#",
       salary "Salary"
FROM employee
WHERE salary = ANY (SELECT salary
                    FROM employee
                    WHERE department_id = (SELECT department_id
                                           FROM department
                                           WHERE UPPER(department_name) = 'IT'))
ORDER BY 3, 1;

-- Q6 --
-- Display last name and salary for all employees who earn less than the Lowest salary in ANY department. 
-- Sort the output by top salaries first and then by last name.
SELECT last_name "Last Name",
       salary "Salary"
FROM employee
WHERE salary < ANY (SELECT MIN(salary)
                    FROM employee
                    GROUP BY department_id)
ORDER BY 2 DESC, 1;