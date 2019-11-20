<?php
	require('require.php');
	require('database.php');
	if (isset($_REQUEST[login])) {
		$username = $_POST[username];
		$password = $_POST[password];
		$error = 'wrong username or password.</label>';
		$sql = "SELECT Username FROM $TB_NAME";
		$sql1 = "SELECT Password FROM $TB_NAME";
		$users = user($sql);
		
		foreach ($users as $user) {
			if ($user[Username] == $username && password_verify($password, $user[Password])) {
				$_SESSION[logged_in] = true;
				$_SESSION[username] = $_POST[username];
				header("Location: main_page.php");
			}
		}
		if (db_datacmp($username, $sql)) {
			// hello finish off here
		}
		echo $error_msg.$error;
	}
?>
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta http-equiv="X-UA-Compatible" content="ie=edge">
		<link rel="stylesheet" href="style.css">
		<title>Camagru</title>
	</head>
	<body>
		<div class="signup page">
			<div class="signup form base">
				<h1 class="signup form logo">Camagru</h1>
				<form action="login.php?login=true" method="post">
					<div class="signup form field">
						<input type="text" name="username" placeholder="Username" class="signup form field" required>
					</div>
					<div class="signup form field">
						<input type="password" name="password" placeholder="Password" class="signup form field" required>
					</div>
					<div class="signup form field">
						<input type="submit" value="Login" class="signup form field button">
					</div>
				</form>
			</div>
		</div>
	</body>
</html>