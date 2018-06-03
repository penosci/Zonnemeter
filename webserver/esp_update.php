<?php
include("php/sql.php");

print_r($_POST);
$power = $_POST['power'];
$temp = $_POST['temp'];
ddb_insert_power_and_temp($power,$temp);
echo ('succes')
?>
