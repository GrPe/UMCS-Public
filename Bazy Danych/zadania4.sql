--1
SELECT credit_rating "ZDOLNOSC KREDYTOWA", count(id)"LICZBA KLIENTOW"
FROM customer
GROUP BY credit_rating;

--2
SELECT title"STANOWISKO", sum(salary)"ZAROBKI"
FROM emp
GROUP BY title
HAVING title NOT LIKE '%VP%'
ORDER BY sum(salary) ASC;

--3
SELECT title"STANOWISKO", MAX(salary)"MAKSYMALNE ZAROBKI"
FROM emp
GROUP BY title;

--4
SELECT dept.name"NAZWA DEPARTAMENTU", AVG(emp.salary)"SREDNIE ZAROBKI"
FROM emp, dept
WHERE emp.dept_id = dept.id
GROUP BY dept.name
HAVING AVG(emp.salary) > 1499;

--5
SELECT ord.id"NR", customer.name"KLIENT", product.name"PRODUKT", ord.payment_type"PLATNOSC",
TO_DATE(ord.date_ordered,'YYYY/MM/DD')"DATA ZAMOWIENIA", item.price"CENA", item.quantity"LICZBA"
FROM ord, customer, item, product
WHERE 
ord.customer_id = customer.id AND
item.ord_id = ord.id AND
item.product_id = product.id AND
ord.payment_type = 'CASH' AND
EXTRACT(MONTH FROM ord.date_ordered) = 9 AND
EXTRACT(YEAR FROM ord.date_ordered) = 1992
ORDER BY ord.id, product.name ASC;

--6
SELECT ord.id"NR", customer.name"KLIENT", ord.payment_type"PLATNOSC",
TO_DATE(ord.date_ordered,'YYYY/MM/DD')"DATA ZAMOWIENIA", SUM(item.price*item.quantity)"WYSOKOSC ZAMOWIENIA"
FROM ord, customer, item
WHERE 
ord.customer_id = customer.id AND
item.ord_id = ord.id AND
ord.payment_type = 'CASH' AND
EXTRACT(MONTH FROM ord.date_ordered) = 9 AND
EXTRACT(YEAR FROM ord.date_ordered) = 1992
GROUP BY ord.id, customer.name, ord.payment_type, TO_DATE(ord.date_ordered,'YYYY/MM/DD')
ORDER BY ord.id ASC;

--7
SELECT last_name "NAZWISKO"
FROM emp
GROUP BY last_name
HAVING CoUNT(id) > 1;

--8
SELECT emp.first_name, emp.last_name, emp.title, LEVEL-1, LEVEL
FROM emp
CONNECT BY PRIOR
emp.id = emp.manager_id
START WITH
emp.manager_id IS NULL
ORDER BY LEVEL;

--9
SELECT emp.first_name, emp.last_name, emp.title, LEVEL-1, LEVEL
FROM emp
CONNECT BY PRIOR
emp.id = emp.manager_id
START WITH
emp.title = 'VP, Operations'
ORDER BY LEVEL;

--10
SELECT region_id, name
FROM dept
UNION
SELECT id, name
FROM region
ORDER BY name;

--11
SELECT name
FROM dept
UNION
SELECT name
FROM region
ORDER BY name;

--12
SELECT name
FROM dept
UNION ALL
SELECT name
FROM region;

--13
SELECT dept.id, emp.last_name
FROM dept, emp
WHERE
emp.dept_id = dept.id
UNION
SELECT region.id, region.name
FROM region
ORDER BY 2;

--14
SELECT customer.id
FROM customer
INTERSECT
SELECT ord.customer_id
FROM ord;

--15
SELECT customer.id
FROM customer
MINUS
SELECT ord.customer_id
FROM ord;
