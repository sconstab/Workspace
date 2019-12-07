<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta http-equiv="X-UA-Compatible" content="ie=edge">
	<title>Camagru</title>
	<link rel="stylesheet" href="style.css">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>
<body>
	<div class="signup page">
	<br/>
	<div id="header">
		<a href="index.php" id="left">Camagru</a>
		<a href="feed.php" id="left">Feed</a>
		<?php
		if (!(isset($_SESSION[username])) && empty($_SESSION[username])) {
			?>	<a href="login.php" id="right">Login</a>
				<a href="signup.php" id="right">Sign Up</a>
		<?php
		} else {
			?>	
				<a href="gallery.php" id="right">Gallery</a>
				<a href="camera.php" id="right">Camera</a>
				<a href="profile.php" id="right">Profile</a>
				<a href="logout.php" id ="right">Logout</a>
		<?php
		}
		?>
	</div>
	<br/>
	<hr class="h" style="border-color: black;">