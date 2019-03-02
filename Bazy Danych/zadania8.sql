

DROP TABLE klient CASCADE CONSTRAINTS;
DROP TABLE zamowienia CASCADE CONSTRAINTS;
DROP TABLE pozycja CASCADE CONSTRAINTS;
DROP TABLE produkt CASCADE CONSTRAINTS;

CREATE TABLE klient
(
    customerID  INTEGER     PRIMARY KEY,
    name        VARCHAR(25) NOT NULL,
    surname     VARCHAR(35) NOT NULL,
    addr_street VARCHAR(45) NOT NULL,
    addr_zip    CHAR(5)     NOT NULL,
    addr_city   VARCHAR(45) NOT NULL,
    login       VARCHAR(14) NOT NULL,
    psswd       VARCHAR(12) NOT NULL
);

CREATE TABLE zamowienia
(
    orderID     INTEGER     NOT NULL PRIMARY KEY,
    IDcustomer  INTEGER     NOT NULL,
    crDATE      DATE        NOT NULL    
);

CREATE TABLE produkt
(
    productID   INTEGER     NOT NULL PRIMARY KEY,
    name        VARCHAR(35) NOT NULL,
    price_net   FLOAT       NOT NULL,
    price_gross FLOAT       NOT NULL,
    description CLOB
);

CREATE TABLE pozycja
(
    IDproduct   INTEGER     NOT NULL,
    IDorder     INTEGER     NOT NULL,
    quantity    INTEGER     NOT NULL
);


ALTER TABLE zamowienia
ADD CONSTRAINT rel_klient2zamowienie
FOREIGN KEY (IDcustomer)
REFERENCES klient (customerID);

ALTER TABLE pozycja
ADD CONSTRAINT rel_zamowienie2pozycja
FOREIGN KEY (IDorder)
REFERENCES zamowienia (orderID);

ALTER TABLE pozycja
ADD CONSTRAINT rel_produkt2pozycja
FOREIGN KEY (IDproduct)
REFERENCES produkt (productID);

--2.1
ALTER TABLE klient
ADD (email VARCHAR(50));

--2.2
ALTER TABLE klient RENAME COLUMN addr_zip TO addr_postalcode;
ALTER TABLE klient MODIFY (addr_postalcode varchar(7));

--2.3
ALTER TABLE zamowienia
ADD (completed CHAR(1) CHECK (completed IN ('Y','N')));

--2.4
ALTER TABLE zamowienia
ADD (completedDate DATE);

--2.5
--zmienic pole completed z char(1) na varchar(40) z check (wartosci)
--ALTER TABLE ZAMOWIENIA MODIFY (completed varchar(40) CHECK (completed IN ('Nowe Zamowienie','Przesylka Zamowienia', 'Realiacja zamowienia', 'zakonczono')));

--2.6
ALTER TABLE PRODUKT
ADD (Vat FLOAT DEFAULT 0.23);
ALTER TABLE PRODUKT
DROP COLUMN price_gross;
ALTER TABLE PRODUKT
ADD (price_gross FLOAT AS (price_net*(vat+1)) VIRTUAL);

--2.7
CREATE INDEX surname ON klient (surname ASC);
CREATE INDEX login ON klient (login ASC);
CREATE INDEX email ON klient (email ASC);

--2.8
--Przy tworzeniu tabeli dodac NOT NULL UNIQUE;

