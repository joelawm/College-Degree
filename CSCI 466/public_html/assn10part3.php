<?php 
	include ('includes/headerassignmentpart3.html');
	require ('includes/connassignment.php');

	echo '<form action="assn10part3.php" method="post">';
	echo 'Enter the book name to find';
	echo '<input type="text" name="go" id="go" hint="Book Name"><br>';
	echo '<br><input type="submit" name="submit" value="Go!"><br>';
	echo '</form>';

	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$Name = trim($_POST['go']);
		echo '<br><br>';
		$sql = "select * from Book where Title = '$Name'";
		$stmt = $conn->prepare($sql);
		$stmt->execute(array($Name));
		$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
		echo 'The price of records for '.$Name.' is ';

		foreach($rows as $r)
		{
			echo $r['Price'].' <br>';
		}
	}
	include ('includes/footerassignment.html');
?>