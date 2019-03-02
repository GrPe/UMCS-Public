--1
SELECT
    *
FROM
    dept;
    
--2
SELECT
    dept_id, last_name, manager_id
FROM emp;

--3
SELECT
    salary*12, last_name
FROM emp;

--4
SELECT 
    first_name "Imiê", last_name "Nazwisko", salary "Zarobki miesiêczne", salary*12 + 1000 "zarobki roczne"
FROM emp;    

--5
SELECT
    first_name "Imiê", last_name "Nazwisko", salary "Zarobki miesiêczne", (salary*12)*1.08 "Zarobki roczne"
FROM emp; 

--6
SELECT
    last_name, salary*12+salary*0.05 "Roczny dochód"
FROM emp;   

--7
SELECT CONCAT(first_name, last_name) "Imiê i Nazwisko"
FROM emp;

--8
SELECT CONCAT(CONCAT(first_name, last_name),CONCAT(' - ',title)) "Super pracownicy"
FROM emp;

--9
SELECT last_name, salary, title, salary*commission_pct/100 "PROWIZJA"
FROM emp;

--10
SELECT last_name, salary, title, NVL(salary*commission_pct/100,0) "PROWIZJA"
FROM emp;

--11
SELECT name
FROM dept
GROUP BY name;

--12
SELECT last_name, dept_id, salary, start_date
FROM emp
ORDER BY dept_id, salary DESC;

--13
SELECT last_name, dept_id, start_date
FROM emp
ORDER BY start_date ASC;

--14
SELECT first_name, last_name, title
FROM emp
WHERE last_name LIKE 'Patel';

--15
SELECT first_name, last_name, start_date
FROM emp
WHERE start_date >= TO_DATE('02-05-1991','dd-mm-yyyy') AND start_date <= TO_DATE('15-06-1991','dd-mm-yyyy'); 

--16
SELECT id, name, region_id
FROM dept
WHERE region_id = 1 OR region_id = 3;

--17
SELECT
    *   
FROM emp
WHERE last_name LIKE 'M%';

--18
SELECT
    *   
FROM emp
WHERE last_name NOT LIKE '%a%';

--19
SELECT last_name, start_date
FROM emp
WHERE start_date >= TO_DATE('01-01-1991', 'dd-mm-yyyy');

--20
SELECT last_name
FROM emp
WHERE last_name LIKE '_a%';

--21
SELECT name
FROM customer
WHERE name LIKE '%s_o%';
