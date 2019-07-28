<?php 
	//Includes links to other programs
	include ("includes/header.html");
 	echo '<br>';
	require ("includes/conn.php");
	$sql = 'SELECT * FROM passenger';
	echo '<form action="quiz2.php" method="post"> ';
	echo '<select name="owner">'; //create the drop down
 	foreach($conn->query($sql) as $row )
	{
		echo '<option value="';
		echo $row["fname"]; //what gets passed
		echo '">';
		echo $row["fname"]; //what is visible
		echo '</option>';
	}
	echo '</select>';
	echo '<br><input type="submit" name="submit"
	value="Show"> <br>';
	echo '</form>';
	//Post Form

	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$own = $_POST['owner'];
		$sql = "select f.flightnum from passenger as p, manifest as m, flight as f where p.fname = '$own' and f.flightnum = m.flightnum and p.passnum = m.passnum";
		echo '<table border="2">';
		echo '<th>Flights passenger is on: ';
		echo $own;
		echo '</th>';
		foreach($conn->query($sql) as $row )
		{
			echo '<tr><td>';
			echo $row['flightnum'];
			echo '</td></tr> ';
		}
	echo '</table>';
	}
	//Include Footers
	include('includes/footer.html');
?>
