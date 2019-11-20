<?php
session_start();
if (!isset($_SESSION[logged_in])) {
	$_SESSION[logged_in] = false;
}
require('database.php');
$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

function safe_input($data) {
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return ($data);
}

function users($sql) {
	try {
		$get_users = $conn->prepare($sql);
		$get_users->execute();
		$users = $get_users->fetchAll();
		return ($users);
	} catch (PDOException $e) {
		echo $e->getMessage();
	}
	return (NULL);
}

function db_datacmp($data, $sql) {
	users($sql);
	foreach ($users as $user => $value) {
		if ($data == $value) {
			return (true);
		}
	}
	return (false);
}
?>