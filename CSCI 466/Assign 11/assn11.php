<?php 
	include ('includes/header.html');
	require ('includes/conn.php');

	echo '<form action="assn11.php" method="post">';
	echo 'Enter Breed';
	echo '<input type="text" name="breed" id="breed" hint="Breed"><br>';
	echo 'Enter Dog Name';
	echo '<input type="text" name="name" id="name" hint="Dog Name"><br>';
	echo '<br><input type="submit" name="submit" value="Submit"><br>';
	echo '</form>';
	
	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$breed = trim($_POST['breed']);
		$name = trim($_POST['name']);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    		$sql = "INSERT INTO Dogs (breed, name) VALUES ('$breed', '$name')";
    		// use exec() because no results are returned
    		$conn->exec($sql);
   		echo "New record created successfully";
   	}
	echo'<p>Check if dog has been added!</p>';
	echo'<a href="http://students.cs.niu.edu/~z1788150/assn11display.php">Dogs added</a>';
	include ('includes/footer.html');
?>