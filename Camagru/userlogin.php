<?php
require('require.php');
require('database.php');

$username = $_POST[username];
$password = $_POST[password];
$error = 'wrong username or password.</label>';
$sql = "SELECT Username, Password FROM $TB_NAME";

try {
	$get_users = $conn->prepare($sql);
	$get_users->execute();
	$users = $get_users->fetchAll();
} catch (PDOException $e) {
	echo $e->getMessage();
}

foreach ($users as $user) {
	if ($user[Username] == $username && password_verify($password, $user[Password])) {
		header("Location: main_page.php/'$user[Username]'");
	}
}
echo $error_msg.$error;
?>