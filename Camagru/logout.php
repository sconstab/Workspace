<?php
session_start();

if (!isset($_SESSION[username]) || empty($_SESSION[username])) {
	header('location: index.php');
}


if (isset($_SESSION[username])) {
	session_unset();
	session_destroy();
	header("Location: index.php");
}
?>