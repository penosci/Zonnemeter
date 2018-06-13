<?php
include("sql.php");
$data = ddb_data_one_day_temp();
//print_r($data);
echo json_encode($data);
 ?>
