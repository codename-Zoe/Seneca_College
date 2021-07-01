-- Q1 --
-- Display the department number and Highest, Lowest and Average pay per each department. 
-- Name these results "High", "Low" and "Avg".
-- Sort the output so that department with highest average salary are shown first.  
SELECT department_id,
       MAX(salary) "High",
       MIN(salary) "Low",
       ROUND(AVG(salary),0) "Avg"
FROM employee
GROUP BY department_id
ORDER BY 4 DESC;

-- Q2 --
-- Display how many people work the same job in the same department.
-- Name these results "Dept#", "Job" and "HowMany".
-- Include only jobs that involve more than one person.
-- Sort the output so that jobs with the most people involved are shown first.  
SELECT department_id "Dept#",
       job_id "Job",
       COUNT(job_id) "HowMany"
FROM employee
GROUP BY department_id, job_id
HAVING COUNT(job_id) > 1
ORDER BY 3 DESC;

-- Q3 --
-- For each job title display the job title and total amount paid each month for this type of the job. 
-- Exclude titles AD_PRES and AD_VP and also include only jobs that require more than $15,000.
-- Sort the output so that top paid jobs are shown first.  
SELECT job_id "Job#",
       SUM(salary) "Total Amount Paid"
FROM employee
WHERE job_id NOT IN ('AD_PRES', 'AD_VP')
GROUP BY job_id
HAVING SUM(salary) > 15000
ORDER BY 2 DESC;

-- Q4 --
-- For each manager number display how many persons he / she supervises.
-- Exclude managers with numbers 100, 101 and 102 and also include only those managers that supervise more than 2 persons.
-- Sort the output so that manager numbers with the most supervised persons are shown first. 
SELECT manager_id "Manager#",
       COUNT(employee_id) "Supervise"
FROM employee
WHERE manager_id NOT IN (100,101,102)
GROUP BY manager_id
HAVING COUNT (employee_id) > 2
ORDER BY 2 DESC;

-- Q5 --
-- For each  department show the latest and earliest hire date, but exclude departments 10 and 20 
-- and also exclude those departments where the last person was hired in this century (Century started on Jan 01st  2000).
-- Sort the output so that most recent latest hire dates are shown first. 
SELECT department_id "Dept#",
       MAX(hire_date) "Latest",
       MIN(hire_date) "Earliest"
FROM employee
WHERE department_id NOT IN (10,20)
GROUP BY department_id
HAVING MAX(hire_date) < TO_DATE('01-Jan-2020', 'DD-MON-YYYY')
ORDER BY 2 DESC;

-- Q6 --
-- For each department show its name, city and how many people work there,
-- excluding departments which name starts on S (do not use LIKE here) 
-- and showing only those ones that employ at least 3 persons. 
-- Sort the output by department name ascending.
SELECT d.department_name "Dept Name",
       l.city "City",
       COUNT(e.employee_id) "Total"
FROM department d
JOIN location l USING(location_id)
JOIN employee e USING(department_id)
WHERE SUBSTR((d.department_name), 1, 1) NOT IN 'S'
GROUP BY d.department_name, l.city
HAVING COUNT(e.employee_id) >= 3
ORDER BY 1 ASC;

-- Q7 --
-- Variation of Q6, Sounds like Assign1 question, where you will show only departments 
-- that do not begin on A and with less than 3 employees, including also Empty departments.
SELECT d.department_name "Dept Name",
       l.city "City",
       COUNT(e.employee_id) "Total"
FROM department d
JOIN location l USING(location_id)
LEFT JOIN employee e USING(department_id)
WHERE SUBSTR((d.department_name), 1, 1) NOT IN 'A'
GROUP BY d.department_name, l.city
HAVING COUNT(e.employee_id) < 3
ORDER BY 1 ASC;