--1
SELECT emp.last_name, emp.first_name,  emp.dept_id, dept.name
FROM emp, dept
WHERE emp.dept_id = dept.id;

--2
SELECT dept.id, dept.region_id, region.name
FROM dept, region
WHERE dept.region_id = region.id;

--3
SELECT emp.last_name,  emp.first_name, emp.dept_id, dept.name
FROM emp, dept
WHERE emp.last_name = 'Menchu' AND
emp.dept_id = dept.id;

--4
SELECT emp.last_name, region.name, emp.commission_pct
FROM emp, dept, region
WHERE emp.dept_id = dept.id AND
dept.region_id = region.id AND
emp.commission_pct != 0;

--5

SELECT NVL(TO_CHAR(emp.last_name),'-'), NVL(TO_CHAR(emp.id),'-'), customer.name
FROM emp, customer
WHERE customer.sales_rep_id = emp.id(+);

--6
SELECT TO_CHAR(E1.last_name) || ' pracuje dla ' || TO_CHAR(E2.last_name) "KTO DLA KOGO"
FROM emp E1, emp E2
WHERE E1.manager_id = E2.id;

--7
SELECT customer.name "NAZWA KLIENTA", emp.last_name " NAZWISKO",
ord.date_ordered "DATA ZAMOWIENIA", item.quantity "LICZBA" , product.name "NAZWA PRODUKTU"
FROM customer, ord, emp, item, product
WHERE ord.customer_id = customer.id AND
ord.sales_rep_id = emp.id AND
ord.id = item.ord_id AND
product.id = item.product_id AND
ord.id = 101;

--8
SELECT customer.id "NR KLIENTA", customer.name "NAZWA KLIENTA", NVL(TO_CHAR(ord.id),'-') "NR ZAMOWIENIA"
FROM customer, ord
WHERE customer.id = ord.customer_id(+);

--9
SELECT MAX(salary), MIN(salary), AVG(salary), sum(salary), COUNT(id)
FROM emp;

--10
SELECT MIN(last_name) "PIERWSZE NAZWISKO", MAX(last_name) "OSTATNIE NAZWISKO"
FROM emp;

--11
SELECT COUNT(id) "LICZBA PRACOWNIKOW"
FROM emp
WHERE commission_pct IS NOT NULL AND
dept_id = 31;
