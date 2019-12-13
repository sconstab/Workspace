<?php
require("../config/require.php");

$destinationFolder = $_SERVER['DOCUMENT_ROOT'] . $location;
$pic = $_POST[pic];
$sti = $_POST[sti];
$picExt = '.png';

$pic = imagecreatefromstring(base64_decode($pic));
$sti = imagecreatefromstring(base64_decode($sti));

if (isset($sti) && !empty($sti)) {
	$test = imagecopy($pic, $sti, 0, 0, 0, 0, 320, 240);
}

$filename = date("d_m_Y_H_i_s") . "-" . time() . $picExt;
$destinationPath = "$destinationFolder$filename";
$success = imagepng($pic, $destinationPath);

if (!$success) {
	echo "the server failed in creating the image";
	return NULL;
}

$sql = "INSERT INTO media(`name`, `user`) VALUES ('$filename', '$_SESSION[username]')";
$req = $conn->prepare($sql);
$req->execute();

echo "$folder$filename";
?>