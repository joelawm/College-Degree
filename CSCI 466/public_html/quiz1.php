<?php
	include ("includes/header.html");
	require ("includes/conn.php");
	echo "Show all the flight info<br>";
	$stmt = $conn->query('select * from flight');
	echo '<table border="2">';
	while($row = $stmt->fetch(PDO::FETCH_ASSOC))
	{
		echo '<tr><td>';
		echo $row['flightnum'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['origination'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['destination'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['miles'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['maxcost'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['mincost'];
		echo '</td></tr>';
	}  
	echo '</table>';
	include("includes/footer.html");
?>