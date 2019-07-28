<?php
	include ("includes/header.html");
	require ("includes/conn.php");
	echo "Show all the dogs info<br>";
	$stmt = $conn->query('select * from Dogs');
	echo '<table border="2">';
	while($row = $stmt->fetch(PDO::FETCH_ASSOC))
	{
		echo '<tr><td>';
		echo $row['breed'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['name'];
		echo '</td></tr>';
	}  
	echo '</table>';
	include("includes/footer.html");
?>