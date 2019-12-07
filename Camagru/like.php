<?php
require('config/require.php');

try {
	$sql = "SELECT `name`, `user`, `like` FROM likes WHERE `name` = :n AND `user` = :u";
	$getLike = $conn->prepare($sql);
	$getLike->bindParam(':n', $_POST[name]);
	$getLike->bindParam(':u', $_SESSION[username]);
	$getLike->execute();
	$like = $getLike->fetch();

	if (!isset($like) || empty($like)) {
		$sql = "INSERT INTO likes(`name`, `user`, `like`) VALUES ('$_POST[name]', '$_SESSION[username]', TRUE)";
		$req = $conn->prepare($sql);
		$req->execute();
	} else {
		if ($like[like] == true) {
			$sql = "UPDATE likes SET `like`=0 WHERE `name` = :n AND `user` = :u";
		} else {
			$sql = "UPDATE likes SET `like`=1 WHERE `name` = :n AND `user` = :u";
		}
		$req = $conn->prepare($sql);
		$req->bindParam(':n', $_POST[name]);
		$req->bindParam(':u', $_SESSION[username]);
		$req->execute();
	}
} catch (PDOException $e) {
	echo $e->getMessage();
}
?>