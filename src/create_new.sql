CREATE DATABASE orderDB;
USE orderDB;
CREATE TABLE book (  id int(10) NOT NULL,  title varchar(100) NOT NULL,  authors varchar(200),  publisher_id int(10) NOT NULL,  copies int(10),  PRIMARY KEY  (id));
quit