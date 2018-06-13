<?php
include "sql.php";
//print_r(ddb_select_last_records());
$temp_val = ddb_select_last_records()['temp_val'];
$solar_val = (((intval(ddb_select_last_records()['solar_val'])/4095)*5)/0.0034);
$solar = round(((((($temp_val-25)*-1)*0.4)/100)+1)*$solar_val,2);

?>
<div class="row">
  <div class="col-sm-12 padding-bottom-sm">
    <h4 class="text-center">hier is mooie live data(refresh 10 seconde)</h4>
  </div>
</div>
<div class="row text-center">
  <div class="col-sm-3"></div>
  <div class="col-sm-3">
    <h6>W/m2</h6>
    <p><?php echo "$solar"; ?></p>
  </div>
  <div class="col-sm-3">
    <h6>Graden C</h6>
    <p><?php echo "$temp_val"; ?></p>
  </div>
</div>
