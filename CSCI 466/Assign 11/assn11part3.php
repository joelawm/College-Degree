<?php 
	include ("includes/header.html");
 	echo '<br>';
	require ("includes/conn.php");
	$sql = 'select d.name, v.visit_id from Dogs as d, Visits as v where v.dog_id = d.dog_id';
	echo '<form action="assn11part3.php" method="post"> ';
	echo '<select name="owner">';
 	foreach($conn->query($sql) as $row )
	{
		echo '<option value="';
		echo $row["visit_id"]; //what gets passed
		echo '">';
		echo $row["name"];
		echo '</option>';
	}
	echo '</select>';
	echo '<br><input type="submit" name="submit"
	value="Submit"> <br>';
	echo '</form>';

	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$own = $_POST['owner'];
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    		$sql = "DELETE FROM Visits where visit_id='$own'";
    		// use exec() because no results are returned
    		$conn->exec($sql);
   		echo "Record deleted successfully";

	}
	//Include Footers
	echo'<p>Check if dog has been added!</p>';
	echo'<a href="http://students.cs.niu.edu/~z1788150/assn11display.php">Dogs added</a>';
	include('includes/footerassignment.html');
?>
