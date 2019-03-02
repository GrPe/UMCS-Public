/* 1
COMMIT - zatwierdzenie zmian
ROLLBACK - F9 wczytanie checkpointa
SAVEPOINT - F5 zapisanie checkpointa
*/

--2
SET AUTOCOMMIT OFF;

--3
INSERT INTO emp (id,first_name,last_name) VALUES (102,'Jan', 'Kowalski');
COMMIT;

--4
INSERT INTO emp (id,first_name, last_name, start_date,salary) 
VALUES (103,'Grzegorz','Perzanowski',TO_DATE('14-03-2016','dd-mm-yyyy'),5000);

SELECT * FROM emp WHERE id = 103;

ROLLBACK;

--5
INSERT INTO emp (id,first_name, last_name, start_date,salary) 
VALUES (103,'Grzegorz','Perzanowski',TO_DATE('14-03-2016','dd-mm-yyyy'),5000);
COMMIT;

--6a
UPDATE
item
SET price = 1.15*price;

--6b
SAVEPOINT S1;

--6c
SELECT SUM(price)
FROM item;

--6d
UPDATE item
SET price = 1.1*price;

--6e
SAVEPOINT S2;

--6f
SELECT SUM(price)
FROM item;

--6g
UPDATE item
SET price = 1.6*price;

--6h
SELECT SUM(price)
FROM item;

--6i
ROLLBACK TO SAVEPOINT S2;

--6j
SELECT SUM(price)
FROM item;

--6k
ROLLBACK TO SAVEPOINT S1;

--6l
SELECT SUM(price)
FROM item;

--6m
COMMIT;

--7
SET AUTOCOMMIT ON;

--8
CREATE TABLE region_kopia AS
SELECT * FROM region;

--9

INSERT INTO dept 
 SELECT id*100,SUBSTR(name,1,4),region_id FROM dept;
 
 --10
 INSERT INTO region_kopia
 SELECT customer.id*10,customer.name FROM customer, ord
 WHERE ord.customer_id = customer.id
 GROUP BY customer.id*10, customer.name
 HAVING MAX(ord.total) > 1000;
 
 --11
 UPDATE emp
 SET
salary = 3*salary,
start_date = TO_DATE('31-12-2001','dd-mm-yyyy');

--12a
UPDATE product
SET
suggested_whlsl_price = 0.9*suggested_whlsl_price
WHERE id IN (SELECT product_id FROM item WHERE quantity_shipped < 30 GROUP BY product_id );

--12b
UPDATE product
SET
suggested_whlsl_price = 1.08*suggested_whlsl_price
WHERE id IN (SELECT product_id FROM
(SELECT product_id, SUM(quantity_shipped) FROM item GROUP BY product_id ORDER BY 2 DESC) WHERE ROWNUM < 6);

--13
UPDATE emp
SET
salary = 1.30*salary
WHERE title LIKE '%VP%';

--14
DELETE FROM emp
WHERE id > 100;

--15
DROP TABLE region_kopia;