<?php
	include ("includes/headerassignment.html");
	require ("includes/connassignment.php");
	$stmt = $conn->query('select b.Title, a.BranchName, i.OnHand from Book as b, Branch as a, Inventory as i where a.BranchNum = i.BranchNum and b.BookCode = i.BookCode order by BranchName');
	echo '<table border="2">';
	while($row = $stmt->fetch(PDO::FETCH_ASSOC))
	{
		echo '<tr><td>';
		echo $row['Title'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['BranchName'];
		echo '</td><td>';
		echo '</td><td>';
		echo $row['OnHand'];
		echo '</td></tr>';
	}  
	echo '</table>';
	include("includes/footerassignment.html");
?>