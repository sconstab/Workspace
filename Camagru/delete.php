<?php
require('config/require.php');

$sql = "DELETE FROM media WHERE `name` = :n";
$req = $conn->prepare($sql);
$req->bindParam(':n', $_POST['file']);
$req->execute();

$sql = "DELETE FROM likes WHERE `name` = :n";
$req = $conn->prepare($sql);
$req->bindParam(':n', $_POST['file']);
$req->execute();

$sql = "DELETE FROM comments WHERE `name` = :n";
$req = $conn->prepare($sql);
$req->bindParam(':n', $_POST['file']);
$req->execute();

unlink(__DIR__."/uploads/images/".$_POST['file']);
echo __DIR__."/uploads/images/".$_POST['file'];
?>