<?php
require('config/require.php');

try {
	$comment = htmlentities($_POST[comment]);
	$sql = "INSERT INTO comments(`name`, `user`, `comment`) VALUES ('$_POST[name]', '$_SESSION[username]', ".'"'.$comment.'"'.")";
	$req = $conn->prepare($sql);
	$req->execute();

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

	if ($email[Notify] == 1) {
		mail($email[Email], "Camagru", "$_SESSION[username] just commented '$comment' on one of your pictures");
	}
} catch (PDOException $e) {
	echo $e->getMessage();
}
?>