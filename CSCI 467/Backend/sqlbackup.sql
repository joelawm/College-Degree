create database csci467;
use csci3467;

create table purchaseOrder(associateID int NOT NULL, customerID int NOT NULL UNIQUE, purchaseOrderNum int UNIQUE, amount int);
