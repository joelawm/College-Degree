<?php 
	//Includes links to other programs
	include ("includes/headerassignmentpart2.html");
 	echo '<br>';
	require ("includes/connassignment.php");
	$sql = 'SELECT * FROM Publisher';
	echo '<form action="assn10part2.php" method="post"> ';
	echo '<select name="owner">'; //create the drop down
 	foreach($conn->query($sql) as $row )
	{
		echo '<option value="';
		echo $row["PublisherName"]; //what gets passed
		echo '">';
		echo $row["PublisherName"]; //what is visible
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
		$sql = "select b.Title from Book as b, Publisher as p where p.PublisherName = '$own' and p.PublisherCode = b.PublisherCode";
		echo '<table border="2">';
		echo '<th>Published by: ';
		echo $own;
		echo '</th>';
		foreach($conn->query($sql) as $row )
		{
			echo '<tr><td>';
			echo $row['Title'];
			echo '</td></tr> ';
		}
	echo '</table>';
	}
	//Include Footers
	include('includes/footerassignment.html');
?>
