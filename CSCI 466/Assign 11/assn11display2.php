<?php
	include ("includes/header.html");
	require ("includes/conn.php");
	echo "Show all the dogs info<br>";
	$stmt = $conn->query('select d.name, v.date from Dogs as d, Visits as v where v.dog_id = d.dog_id');
	echo '<table border="2">';
	while($row = $stmt->fetch(PDO::FETCH_ASSOC))
	{
		echo '<tr><td>';
		echo $row['name'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['date'];
		echo '</td></tr>';
	}  
	echo '</table>';
	include("includes/footer.html");
?>