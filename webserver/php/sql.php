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
	$power_query= "INSERT INTO Solar_power (`value`) VALUES (`{$power}`)";

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

//ddb_insert_power_and_temp(1500,25);

?>
