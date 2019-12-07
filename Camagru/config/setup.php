<?php
require('database.php');
$sql = "CREATE DATABASE IF NOT EXISTS $DB_NAME";
try {
	$conn = new PDO($DB_ONCE, $DB_USER, $DB_PASSWORD);
	$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$conn->exec($sql);
} catch (PDOExeption $e) {
	echo $e->getMessage();
}
try {
	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	$sql = "CREATE TABLE IF NOT EXISTS $TB_NAME (
		`ID` INT(11) AUTO_INCREMENT NOT NULL PRIMARY KEY,
		`Username` VARCHAR(255) NOT NULL,
		`FirstName` VARCHAR(255),
		`Surname` VARCHAR(255),
		`Email` VARCHAR(255) NOT NULL,
		`Password` VARCHAR(255) NOT NULL,
		`Valid` BOOLEAN NOT NULL DEFAULT FALSE,
		`Notify` BOOLEAN NOT NULL DEFAULT TRUE
		)";
	$conn->exec($sql);

	$sql = "CREATE TABLE IF NOT EXISTS media (
		`name` VARCHAR(255) NOT NULL PRIMARY KEY,
		`user` VARCHAR(255) NOT NULL
		)";
	$conn->exec($sql);

	$sql = "CREATE TABLE IF NOT EXISTS likes (
		`ID` INT(11) AUTO_INCREMENT NOT NULL PRIMARY KEY,
		`name` VARCHAR(255) NOT NULL,
		`user` VARCHAR(255) NOT NULL,
		`like` BOOLEAN NOT NULL DEFAULT FALSE
		)";
	$conn->exec($sql);

	$sql = "CREATE TABLE IF NOT EXISTS comments (
		`ID` INT(11) AUTO_INCREMENT NOT NULL PRIMARY KEY,
		`name` VARCHAR(255) NOT NULL,
		`user` VARCHAR(255) NOT NULL,
		`comment` VARCHAR(510) NOT NULL
		)";
	$conn->exec($sql);
} catch (PDOException $e) {
	echo $e->getMessage();
}
?>