<?php 
	include ('includes/header.html');
	require ('includes/conn.php');

	echo '<form action="quiz3.php" method="post">';
	echo 'Enter First Name';
	echo '<input type="text" name="first" id="first" hint="First Name"><br>';
	echo 'Enter Last Name';
	echo '<input type="text" name="last" id="last" hint="Last Name"><br>';
	echo '<br><input type="submit" name="submit" value="Submit"><br>';
	echo '</form>';
	
	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$first = trim($_POST['first']);
		$last = trim($_POST['last']);
		echo $first; echo $last;
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    		$sql = "INSERT INTO passenger (fname, lname) VALUES ('$first', '$last')";
    		// use exec() because no results are returned
    		$conn->exec($sql);
   		echo "New record created successfully";
   	}
	include ('includes/footer.html');
?>