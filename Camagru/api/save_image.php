<?php
require("../config/require.php");

$destinationFolder = $_SERVER['DOCUMENT_ROOT'] . $location;
$maxFileSize = 2 * 1024 * 1024;
// $postdata = file_get_contents("php://input");

// if (!isset($postdata) || empty($postdata))
//     exit(json_encode(["success" => false, "reason" => "Not a post data"]));

// $request = json_decode($postdata);

// if (trim($request->data) === "")
//     exit(json_encode(["success" => false, "reason" => "Not a post data"]));

// $file = $request->data;
// $size = getimagesize($file);
// $ext = $size['mime'];

// if ($ext == 'image/jpeg')
//     $ext = '.jpg';
// elseif ($ext == 'image/png')
//     $ext = '.png';
// else
//     exit(json_encode(['success' => false, 'reason' => 'only png and jpg mime types are allowed']));

// if (strlen(base64_decode($file)) > $maxFileSize)
//     exit(json_encode(['success' => false, 'reason' => "file size exceeds {$maxFileSize} Mb"]));

// $img = str_replace('data:image/png;base64,', '', $file);
// $img = str_replace('data:image/jpeg;base64,', '', $img);
// $img = str_replace(' ', '+', $img);
// $img = base64_decode($img);
// $filename = date("d_m_Y_H_i_s") . "-" . time() . $ext;
// $destinationPath = "$destinationFolder$filename";
// $success = file_put_contents($destinationPath, $img);

// if (!$success)
//     exit(json_encode(['success' => false, 'reason' => 'the server failed in creating the image']));

// $sql = "INSERT INTO media(`name`, `user`) VALUES ('$filename', '$_SESSION[username]')";
// $req = $conn->prepare($sql);
// $req->execute();

// exit(json_encode(['success' => true, 'path' => "$folder$filename"]));

$pic = $_POST[pic];
$sti = $_POST[sti];

if (!isset($pic) || empty($pic)) {
	exit(json_encode(["success" => false, "reason" => "Not a post data"]));
}

if (trim($pic) === "") {
	exit(json_encode(["success" => false, "reason" => "Not a post data"]));
}

$picSize = getimagesize($pic);
$picExt = $picSize['mime'];

if ($picExt == 'image/jpeg') {
	$picExt = '.jpeg';
} elseif ($picExt == 'image/png') {
	$picExt = '.png';
} else {
	exit(json_encode(['success' => false, 'reason' => 'only png and jpg mime types are allowed']));
}

$pic = str_replace('data:image/png;base64,', '', $pic);
$pic = str_replace('data:image/jpeg;base64,', '', $pic);
$pic = str_replace(' ', '+', $pic);

$sti = str_replace('data:image/png;base64,', '', $sti);
$sti = str_replace('data:image/jpeg;base64,', '', $sti);
$sti = str_replace(' ', '+', $sti);

if (isset($sti) && !empty($sti)) {
	imagecopy($pic, $sti, 0, 0, 0, 0, 320, 240);
}

if (strlen(base64_decode($pic)) > $maxFileSize) {
	exit(json_encode(['success' => false, 'reason' => "file size exceeds {$maxFileSize} Mb"]));
}

$pic = base64_decode($pic);
$filename = date("d_m_Y_H_i_s") . "-" . time() . $picExt;
$destinationPath = "$destinationFolder$filename";
$success = file_put_contents($destinationPath, $pic);

if (!$success) {
	exit(json_encode(['success' => false, 'reason' => 'the server failed in creating the image']));
}

$sql = "INSERT INTO media(`name`, `user`) VALUES ('$filename', '$_SESSION[username]')";
$req = $conn->prepare($sql);
$req->execute();

exit(json_encode(['success' => true, 'path' => "$folder$filename"]));