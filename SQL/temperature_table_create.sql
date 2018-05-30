create table Temperature (
TemperatureID int NOT NULL primary key unique AUTO_INCREMENT,
value int NOT NULL,
dt_created datetime DEFAULT CURRENT_TIMESTAMP,
dt_modified datetime DEFAULT CURRENT_TIMESTAMP,
Solar_powerID int,
foreign key(Solar_powerID) references Solar_power(Solar_powerID)
);