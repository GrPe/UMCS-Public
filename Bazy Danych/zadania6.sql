--1
SELECT * FROM emp
WHERE emp.salary < 1300
ORDER BY emp.last_name ASC;

--2
SELECT date_ordered || ' ' || sum(total)
FROM ord
GROUP BY date_ordered;

--3
SELECT last_name, first_name
FROM emp
WHERE emp.title = 'Stock Clerk' AND
emp.salary > (SELECT AVG(salary) FROM emp WHERE emp.title = 'Warehouse Manager');

--4
SELECT COUNT(id)
FROM emp
WHERE emp.salary < (SELECT AVG(salary) FROM emp);

--5
SELECT * FROM emp
WHERE months_between(to_date('01-03-2017','dd-mm-yyyy'),start_date) > 26*12
ORDER BY start_date;

--6
SELECT emp.id, SUM(ord.total)
FROM emp, ord
WHERE emp.id = ord.sales_rep_id
GROUP BY emp.id;

--7
SELECT * FROM(
SELECT emp.id, SUM(ord.total)
FROM emp, ord
WHERE emp.id = ord.sales_rep_id 
GROUP BY emp.id
ORDER BY 2 DESC)
WHERE ROWNUM = 1;

--8

SELECT * FROM(
SELECT emp.id, emp.last_name, SUM(ord.total)
FROM emp, ord
WHERE emp.id = ord.sales_rep_id 
GROUP BY emp.id, emp.last_name
ORDER BY 3 DESC)
WHERE ROWNUM = 1;

--9
SELECT start_date, COUNT(id)
FROM emp
GROUP BY start_date
ORDER BY start_date;

--10
SELECT product.name
FROM product, inventory
WHERE inventory.product_id = product.id AND
inventory.out_of_stock_explanation IS NOT NULL;

--11
SELECT product.name
FROM product, inventory
WHERE inventory.product_id = product.id
GROUP BY product.name
HAVING SUM(inventory.amount_in_stock) < 500;

--12
SELECT name
FROM product
WHERE LENGTH(name) - LENGTH(REPLACE(name,' ','')) + 1 = 3;