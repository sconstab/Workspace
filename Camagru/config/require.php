<?php
session_start();

require('database.php');
$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

$location = "/Workspace/Camagru/uploads/images/";

function safe_input($data) {
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return ($data);
}

function scriptPath() {
    list($scriptPath) = get_included_files();
    return($scriptPath);
}

function get($start=0, $end=10) {
	$sql = "SELECT `name`, `user` FROM media ORDER BY `name` DESC LIMIT $start, $end";
	$getPics = $conn->prepare($sql);
	$getPics->execute();
	$pics = $getPics->fetchAll();
	return (count($pics) == 0 ? false : $pics);
}
?>