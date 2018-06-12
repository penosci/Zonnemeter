<?php
function ddb_connect() {
	$host="localhost";
	$port=3306;
	$socket="";
	$user="solar";
	$password="kaas";
	$dbname="PV-data";

	$con = new mysqli($host, $user, $password, $dbname, $port, $socket);
	return $con;
	if ($con->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
	//print_r($con);
}

function ddb_disconect($con) {
		$con->close();
		echo "<h3>conclosed</h3>";
}

function ddb_insert_power_and_temp($power,$temp) {
	$con = ddb_connect();
	$power_query= "INSERT INTO Solar_power (`value`) VALUES ({$power})";

	$temp_query= "INSERT INTO Temperature (`value`,Solar_powerid)
								SELECT {$temp}, Solar_powerid
								FROM Solar_power
								order by Solar_powerID desc
								LIMIT 1";

	if ($con->query($power_query) === TRUE) {
    echo "New record created successfully";
	} else {
    echo "Error: " . $power_query . "<br>" . $con->error;
	}

	if ($con->query($temp_query) === TRUE) {
    echo "New record created successfully";
	} else {
    echo "Error: " . $temp_query . "<br>" . $con->error;
	}

	ddb_disconect($con);
}

function ddb_select_last_records(){
	$con = ddb_connect();
	$query = "SELECT Temperature.TemperatureID, Temperature.value AS temp_val, Solar_power.value AS solar_val From Temperature
	INNER JOIN Solar_power ON Temperature.Solar_powerID=Solar_power.Solar_powerID
	ORDER BY Temperature.TemperatureID DESC LIMIT 1
	";

	$result = $con->query($query);

	if ($result->num_rows > 0) {
	    // output data of each row
	    while($row = $result->fetch_assoc()) {
	        return $row;
	    }
	} else {
	    echo "0 results";
	}
	$con->close();
}
function ddb_data_one_day(){
	$con = ddb_connect();
	$query = "SELECT Temperature.TemperatureID, Temperature.value AS temp_val, Solar_power.value AS solar_val, Temperature.dt_created AS date From Temperature
	INNER JOIN Solar_power ON Temperature.Solar_powerID=Solar_power.Solar_powerID WHERE Temperature.dt_created >= NOW() - INTERVAL 1 DAY
	";

	$result = $con->query($query);
	if ($result->num_rows > 0) {
	    // output data of each row
	    while($row = $result->fetch_assoc()) {
				$data[] = array(strftime($row['date']),intval($row['temp_val']),intval($row['solar_val']));
	    }
	} else {
	    echo "0 results";
	}
	return $data;
	$con->close();
}
/*select data one day ;;;;SELECT Temperature.TemperatureID, Temperature.value AS temp_val, Solar_power.value AS solar_val, Temperature.dt_created AS date From Temperature
	INNER JOIN Solar_power ON Temperature.Solar_powerID=Solar_power.Solar_powerID WHERE Temperature.dt_created >= NOW() - INTERVAL 1 DAY*/
//ddb_insert_power_and_temp(1500,25);

?>
