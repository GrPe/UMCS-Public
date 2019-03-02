--1
SELECT id, total
FROM ord
WHERE total = (SELECT MAX(total) FROM ord);

--2
SELECT id, date_ordered, date_shipped, total
FROM ord
WHERE payment_type = 'CASH' AND
total = (SELECT MIN(total) FROM ord);

--3
SELECT id, date_ordered, date_shipped, total
FROM ord
WHERE total > (SELECT AVG(total) FROM ord);

--4
SELECt name, suggested_whlsl_price
FROM  product
WHERE suggested_whlsl_price < 
(SELECT AVG(suggested_whlsl_price) FROM product WHERE name LIKE '%Prostar%');

--5
SELECT warehouse_id, product_id, amount_in_stock
FROM inventory
WHERE (warehouse_id, amount_in_stock) IN 
(SELECT warehouse_id, MAX(amount_in_stock) FROM inventory GROUP BY warehouse_id);

--6
SELECT warehouse_id, product_id, amount_in_stock
FROM inventory I1
WHERE amount_in_stock = 
(SELECT MAX(amount_in_stock) FROM inventory I2 
WHERE I2.warehouse_id = I1.warehouse_id);

--7
SELECT product.name, warehouse.address, I1.amount_in_stock
FROM product, warehouse, inventory I1
WHERE
product.id = I1.product_id AND
warehouse.id = I1.warehouse_id AND
I1.amount_in_stock = 
(SELECT MAX(amount_in_stock) FROM inventory I2
WHERE I2.warehouse_id = I1.warehouse_id); 

--8
SELECT name FROM customer C
WHERE NOT EXISTS
(SELECT * FROM ord O WHERE C.id = O.customer_id);

--9
SELECT C.id, C.name, ord.id FROM customer C, ord
WHERE  EXISTS
(SELECT * FROM ord O WHERE C.id = O.customer_id) AND
ord.customer_id = C.id;

--10
SELECT customer_id, id FROM ord
WHERE  EXISTS
(SELECT * FROM ord O)
ORDER BY customer_id;

--11
SELECT emp.last_name
FROM emp, ord
WHERE emp.id = ord.sales_rep_id AND
ord.id < ANY
(SELECT ord.id FROM ord WHERE ord.id < 100);

--12
SELECT emp.last_name
FROM emp, ord
WHERE emp.id = ord.sales_rep_id AND
ord.id < 100
GROUP BY emp.last_name;

--13
SELECT emp.first_name, emp.last_name
FROM emp, ord
WHERE emp.id = ord.sales_rep_id
GROUP BY emp.first_name, emp.last_name
HAVING COUNT(ord.id) > 3;