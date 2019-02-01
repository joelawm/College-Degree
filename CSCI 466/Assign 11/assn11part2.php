<?php 
	include ("includes/header.html");
 	echo '<br>';
	require ("includes/conn.php");
	$sql = 'SELECT * FROM Dogs';
	echo '<form action="assn11part2.php" method="post"> ';
	echo '<select name="owner">';
 	foreach($conn->query($sql) as $row )
	{
		echo '<option value="';
		echo $row["dog_id"]; //what gets passed
		echo '">';
		echo $row["name"]; //what is visible
		echo '</option>';
	}
	echo '</select>';
	echo 'Enter date as EX: 2018-11-29';
	echo '<input type="text" name="date" id="date" hint="Date"><br>';
	echo '<br><input type="submit" name="submit"
	value="Submit"> <br>';
	echo '</form>';

	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$own = $_POST['owner'];
		$date = trim($_POST['date']);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    		$sql = "INSERT INTO Visits (date, dog_id) VALUES ('$date', '$own')";
    		// use exec() because no results are returned
    		$conn->exec($sql);
   		echo "New record created successfully";

	}
	//Include Footers
	echo'<p>Check if dog has been added!</p>';
	echo'<a href="http://students.cs.niu.edu/~z1788150/assn11display.php">Dogs added</a>';
	include('includes/footerassignment.html');
?>
