<?PHP
$host = 'courses';
$user = 'z1788150';
$password='1998Jan14';
$db = 'z1788150';
    // UTF-8 is a character encoding scheme that allows you to conveniently store
    // a wide varienty of special characters, like ¢ or €, in your database.
    // By passing the following $options array to the database connection code we
    // are telling the MySQL server that we want to communicate with it using UTF-8
    // See Wikipedia for more information on UTF-8:
    // http://en.wikipedia.org/wiki/UTF-8
        $options = array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8');

$conn = new PDO("mysql:host=$host;dbname=$db",$user,$password);
try
{
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $conn->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
}
catch(PDOException $e)
{
  echo 'ERROR: ' . $e->getMessage();
}
?>