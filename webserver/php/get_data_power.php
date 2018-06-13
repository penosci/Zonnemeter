<?php
include("sql.php");
$data = ddb_data_one_day_power();
//print_r($data);
echo json_encode($data);
 ?>
