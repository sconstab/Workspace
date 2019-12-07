<?php
require('config/require.php');

try {
	$comment = htmlentities($_POST[comment]);
	$sql = "INSERT INTO comments(`name`, `user`, `comment`) VALUES ('$_POST[name]', '$_SESSION[username]', ".'"'.$comment.'"'.")";
	$req = $conn->prepare($sql);
	$req->execute();
} catch (PDOException $e) {
	echo $e->getMessage();
}
?>