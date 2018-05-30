create table Solar_power (
Solar_powerID int NOT NULL primary key unique AUTO_INCREMENT,
value int NOT NULL,
dt_created datetime DEFAULT CURRENT_TIMESTAMP,
dt_modified datetime DEFAULT CURRENT_TIMESTAMP
);