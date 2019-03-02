SET SERVEROUT ON;

--1
CREATE SEQUENCE seq1
    MINVALUE 30
    MAXVALUE 10000
    START WITH 30
    INCREMENT BY 1;


CREATE OR REPLACE PROCEDURE add_emp (
in_last_name VARCHAR2,
in_first_name VARCHAR2,
in_userid VARCHAR2 DEFAULT NULL,
in_start_date DATE DEFAULT NULL,
in_comments VARCHAR2 DEFAULT NULL,
in_manager_id NUMBER DEFAULT NULL,
in_title VARCHAR2 DEFAULT NULL,
in_dept_id NUMBER DEFAULT NULL,
in_salary NUMBER DEFAULT NULL,
in_commission_pct NUMBER DEFAULT NULL) IS


BEGIN
    INSERT INTO emp  VALUES 
    ( seq1.nextval, in_last_name, in_first_name,in_userid, in_start_date, in_comments, in_manager_id,
    in_title, in_dept_id, in_salary, in_commission_pct);
    COMMIT;
END;
/


EXECUTE add_emp('kowalski', 'jan');


--2
CREATE OR REPLACE PROCEDURE change_emp(
in_id NUMBER,
in_last_name VARCHAR2,
in_first_name VARCHAR2,
in_userid VARCHAR2 DEFAULT NULL,
in_start_date DATE DEFAULT NULL,
in_comments VARCHAR2 DEFAULT NULL,
in_manager_id NUMBER DEFAULT NULL,
in_title VARCHAR2 DEFAULT NULL,
in_dept_id NUMBER DEFAULT NULL,
in_salary NUMBER DEFAULT NULL,
in_commission_pct NUMBER DEFAULT NULL) IS

BEGIN
    UPDATE emp
    SET last_name = in_last_name,
        first_name = in_first_name,
        userid = in_userid,
        start_date = in_start_date,
        comments = in_comments,
        manager_id = in_manager_id,
        title = in_title,
        dept_id = in_dept_id,
        salary = in_salary,
        commission_pct = in_commission_pct
    WHERE id = in_id;
    COMMIT;
END;
/
EXECUTE change_emp(31,'Nowak' ,'jan');


--3
CREATE OR REPLACE PROCEDURE delete_emp (in_id NUMBER) IS
BEGIN
    DELETE FROM emp
    WHERE id = in_id;
    COMMIT;
END;
/

EXECUTE delete_emp(31);

--4
CREATE OR REPLACE PROCEDURE change_salary(
in_id NUMBER,
in_change NUMBER) IS
uv_change NUMBER := 1+(in_change/100);
BEGIN
    UPDATE emp
    SET salary = salary*uv_change
    WHERE in_id = id;
    COMMIT;
END;
/


EXECUTE change_salary(1,-50);


--5

DROP TABLE top_n_emp_;
CREATE TABLE top_n_emp_
(
    first_name VARCHAR2(30),
    last_name VARCHAR2(30),
    salary NUMBER
);
/

CREATE OR REPLACE PROCEDURE top_n_emp(
n NUMBER) AS
    v_name emp.first_name%TYPE;
    v_surname emp.last_name%TYPE;
    v_salary emp.salary%TYPE;
    
    i NUMBER;
    
    CURSOR c_emp 
    IS
    SELECT first_name, last_name, salary
    FROM emp
    ORDER BY salary DESC;
BEGIN

    OPEN c_emp;
    i := 0;
    LOOP
        EXIT WHEN i >= n;
        FETCH c_emp INTO v_name, v_surname, v_salary;
        EXIT WHEN c_emp%NOTFOUND;
        dbms_output.put_line('IMIE: ' || v_name);
        dbms_output.put_line('NAZWISKO: ' || v_surname);
        dbms_output.put_line('SALARY: ' || v_salary);
        INSERT INTO top_n_emp_ VALUES (v_name, v_surname, v_salary);
        COMMIT;
        i := i+1;
    END LOOP;
    CLOSE c_emp;   
END;
/
EXECUTE top_n_emp(4);


--6
CREATE OR REPLACE PROCEDURE change_dept(v_id_emp NUMBER, v_dept NUMBER) IS
BEGIN
    UPDATE emp
    SET dept_id = v_dept
    WHERE v_id_emp = emp.id;
END;
/

EXECUTE change_dept(32,10);

--7
CREATE OR REPLACE PROCEDURE stat_emp(param VARCHAR2) IS
    v_result NUMBER;
BEGIN
    IF param = 'MAX' THEN SELECT MAX(salary) INTO v_result FROM emp;
    ElSIF param = 'MIN' THEN  SELECT MIN(salary) INTO v_result FROM emp;
    ELSIF param = 'AVG' THEN  SELECT AVG(salary) INTO v_result FROM emp;
    ELSIF param = 'SUM' THEN  SELECT SUM(salary) INTO v_result FROM emp;
    ELSE GOTO error;
    END IF;
    GOTO koniec;
<<error>>
    dbms_output.put_line('Nieznany parametr');
<<koniec>>    
    dbms_output.put_line(param || ': ' || v_result);
END;
/

EXECUTE stat_emp('SUM');