
set SERVEROUTPUT ON;

--1
declare
 v1 constant number := 12;
 v2 varchar2(123) := 'Ala ma kota';
 v3 date := to_date('01-01-2010','dd-mm-yyyy');
begin
    dbms_output.put_line(v1);
    dbms_output.put_line(v2);
    dbms_output.put_line(to_char(v3));
end;    
/

--2
declare 
    v1 constant date := to_date('01-01-2010','dd-mm-yyyy');
    v2 date := sysdate;
    v3 number;
begin
    v3 := v2 - v1;
    dbms_output.put_line('dni: ' || round(v3,0));
    dbms_output.put_line('tygodniu: ' || round(v3/7,0));
    dbms_output.put_line('miesiecy: ' || round(v3/30,0));
end;
/

--3
begin
    dbms_output.put_line('najmniej: ');
    for x in (select * from emp where emp.salary = (select Min(emp.salary) from emp) ) loop
        dbms_output.put_line(x.last_name || ' ' || x.first_name  || ' ' || x.salary);
    end loop;    
    dbms_output.put_line('najwiecej: ');
    for x in (select * from emp where emp.salary = (select max(emp.salary) from emp) ) loop
        dbms_output.put_line(x.last_name || ' ' || x.first_name || ' ' || x.salary);
    end loop;    
end;
/

--4
--a
declare
    v_name varchar2(25);
    v_surname varchar2(25);

    cursor c_emp is
    select first_name, last_name
    from emp;
begin
    open c_emp;
    loop
        fetch c_emp into v_name, v_surname;
        exit when c_emp%NOTFOUND;
        dbms_output.put_line(v_name || ' ' || v_surname);
    end loop;    
    close c_emp;
end;
/

--4
--b
begin
    for x in (select * from emp) loop
        dbms_output.put_line(x.last_name || ' ' || x.first_name);
    end loop;    
end;
/


--5
declare
    date_ordered date;
    date_shipped date;
    customer_name varchar2(30);
    customer_address varchar2(30);
    emp_first_name varchar2(25);
    emp_last_name varchar2(25);

    cursor c_emp (date_ord_from date, date_ord_to date) is
    select ord.date_ordered, ord.date_shipped, customer.name,  customer.address, emp.first_name, emp.last_name
    from ord, customer, emp
    where date_ordered > date_ord_from AND date_ordered < date_ord_to AND
    ord.customer_id = customer.id AND ord.sales_rep_id = emp.id;
begin
    open c_emp(to_date('01-09-1992','dd-mm-yyyy'),to_date('30-09-1992','dd-mm-yyyy'));
   -- for x in c_emp loop
      --  dbms_output.put_line(x.id || ' ' || to_char(x.date_ordered));
      loop
        fetch c_emp into date_ordered, date_shipped, customer_name, customer_address, emp_first_name, emp_last_name;
        exit when  c_emp%NOTFOUND;
        dbms_output.put_line('Zamowienie: ' || date_ordered || ' ' || date_shipped);
        dbms_output.put_line('Klient: ' || customer_name || ' Adres: ' || customer_address);
        dbms_output.put_line('pracownik: ' || emp_first_name || ' ' || emp_last_name);
        dbms_output.put_line(' ');
    end loop;
    close c_emp;
end;
/

--6
create table emp_new as select * from emp;
 
declare
    avg_salary number;
begin
    select avg(salary) into avg_salary from emp_new;
    for x in (select * from emp_new) loop
        if x.salary < (avg_salary/2) then update emp_new set salary = salary*1.2 where id = x.id;--x.salary := x.salary*1.2;
        elsif x.salary < ((avg_salary/6) * 5) then update emp_new set salary = salary*1.1 where id = x.id;
        else update emp_new set salary = salary*1.05 where id = x.id;
        end if;
    end loop;
end;
/
drop table emp_new;