<?php
include "sql.php";
//print_r(ddb_select_last_records());
$temp_val = ddb_select_last_records()['temp_val'];
$solar_val = ddb_select_last_records()['solar_val'];
?>
<div class="row">
  <div class="col-sm-12 padding-bottom-sm">
    <h4 class="text-center">hier is mooie live data</h4>
  </div>
</div>
<div class="row text-center">
  <div class="col-sm-6">
    <div class="well">
      <h6>W/m2</h6>
      <p><?php echo "$solar_val"; ?></p>
    </div>
  </div>
  <div class="col-sm-6">
    <h6>Graden C</h6>
    <p><?php echo "$temp_val"; ?></p>
  </div>
</div>
