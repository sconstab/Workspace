<?php
require('config/require.php');

try {
	$sql = "SELECT `name`, `user`, `like` FROM likes WHERE `name` = :n AND `user` = :u";
	$getLike = $conn->prepare($sql);
	$getLike->bindParam(':n', $_POST[name]);
	$getLike->bindParam(':u', $_SESSION[username]);
	$getLike->execute();
	$like = $getLike->fetch();

	$sql = "SELECT `user` FROM media WHERE `name` = :n";
	$getUser = $conn->prepare($sql);
	$getUser->bindParam(':n', $_POST[name]);
	$getUser->execute();
	$user = $getUser->fetch();

	$sql = "SELECT `Email`, `Notify` FROM $TB_NAME WHERE `Username` = :u";
	$getEmail = $conn->prepare($sql);
	$getEmail->bindParam(':u', $user[user]);
	$getEmail->execute();
	$email = $getEmail->fetch();

	if (!isset($like) || empty($like)) {
		$sql = "INSERT INTO likes(`name`, `user`, `like`) VALUES ('$_POST[name]', '$_SESSION[username]', TRUE)";
		$req = $conn->prepare($sql);
		$req->execute();
	} else {
		if ($like[like] == true) {
			$sql = "UPDATE likes SET `like`=0 WHERE `name` = :n AND `user` = :u";
		} else {
			$sql = "UPDATE likes SET `like`=1 WHERE `name` = :n AND `user` = :u";
			if ($email[Notify] == 1) {
				mail($email[Email], "Camagru", "$like[user] just liked one of your pictures");
			}
		}
		$req = $conn->prepare($sql);
		$req->bindParam(':n', $_POST[name]);
		$req->bindParam(':u', $_SESSION[username]);
		$req->execute();
	}
} catch (PDOException $e) {
	echo "Error: ".$e->getMessage();
}
?>