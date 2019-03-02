--1
SELECT LOWER(first_name) "IMIÊ", LOWER(last_name) "NAZWISKO", INITCAP(userid) "IDENTYFIKATOR", UPPER(title) "STANOWISKO"
FROM emp
WHERE title LIKE '%VP%';

--2
SELECT first_name "IMIÊ", last_name "NAZWISKO"
FROM emp
WHERE last_name = INITCAP('PATEL');

--3
SELECT CONCAT(name || ' - ', country) "NAZWA I PAÑSTWO"
FROM customer
WHERE credit_rating = 'GOOD';

--4
SELECT name "NAZWA", LENGTH(name) "LICZBA ZNAKÓW"
FROM product
WHERE  name LIKE 'Ace%';

--5
SELECT ROUND(41.5843,2), ROUND(41.5843,0), ROUND(41.5843,-1)
FROM dual;

--6
SELECT TRUNC(41.5843,2), TRUNC(41.5843,0), TRUNC(41.5843,-1)
FROM dual;

--7
SELECT last_name "NAZWISKO", NVL(MOD(salary,commission_pct),0) "RESZTA"
FROM emp
WHERE salary > 1380;

--8
SELECT SYSDATE
FROM dual;

--9
SELECT last_name "NAZWISKO", ROUND((SYSDATE - start_date)/7) "LICZBA TYGODNI"
FROM emp
WHERE dept_id = 43;

--10
SELECT id, TRUNC(MONTHS_BETWEEN(SYSDATE,start_date)) "LICZBA MIESIÊCY",ADD_MONTHS(start_date,3) "DATA"
FROM emp
WHERE MONTHS_BETWEEN(SYSDATE,start_date) < 320;

--11
SELECT product_id "PRODUCT", restock_date"DOSTAWA", NEXT_DAY(restock_date,5) "PIATEK PO DOSTAWIE", LAST_DAY(restock_date)"OSTATNI DIZEN MIESIACA"
FROM inventory
WHERE restock_date IS NOT NULL;

--12
SELECT id, start_date"DATA", EXTRACT(MONTH FROM start_date)"MIESIAC"
FROM emp
WHERE EXTRACT(YEAR FROM start_date) = 1991;

--13
SELECT id, TO_CHAR(date_ordered, 'MM/YY') "MM/RR"
FROM ord
WHERE sales_rep_id =11;

--14
SELECT last_name "NAZWISKO", INITCAP(TO_CHAR(start_date,'DD MONTH YYYY')) || ' roku' "DATA"
FROM emp
WHERE EXTRACT(YEAR FROM start_date) >= 1991;
