<?php
include("php/sql.php");
ini_set('error_reporting', E_ALL);
$power = $_POST['power'];
$temp = $_POST['temp'];
ddb_insert_power_and_temp($power,$temp);
echo ('succes')
?>
