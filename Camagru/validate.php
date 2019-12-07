<?php
require('config/require.php');

if (isset($_GET[email])) {
	try {
		$sql = "UPDATE $TB_NAME SET `Valid`=1 WHERE `Email` = :e";
		$req = $conn->prepare($sql);
		$req->execute(['e' => $_GET[email]]);
		echo $_GET[email]." Verified.";
	} catch (PDOExeption $e) {
		echo $e->getMessage();
	}
}
?>