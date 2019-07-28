<?php
	if ($_SERVER['REQUEST_METHOD'] == 'POST')
	{
		$own = $_POST['owner'];
		$sql = "select b.Title from Book as b, Publisher as p where p.BookCode = b.BookCode and p.PublisherName = '$own'";
	}
	echo '<table border="2">';
	while($row = $sql->fetch(PDO::FETCH_ASSOC))
	{
		echo '<tr><td>';
		echo $row['Title'];
		echo '</td></tr>';
	}  
	echo '</table>';

?>