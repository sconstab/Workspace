<?php
require('connect.php');
require('require.php');
require('database.php');

$usernameErr = $nameErr = $surnameErr = $emailErr = $passwordErr = "";
$username = $name = $surname = $email = $password = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
	if (empty($_POST[username])) {
		$usernameErr = "Username required";
	} else {
		$username = safe_input($_POST[username]);	
	}
	if (!preg_match("/^[a-zA-Z ]*$/", ($name = safe_input($_POST[name])))) {
		$nameErr = "Invalid name";
	}
	if (!preg_match("/^[a-zA-Z ]*$/", ($surname = safe_input($_POST[surname])))) {
		$surnameErr = "Invalid surname";
	}
	if (empty($_POST[email]) || !filter_var($_POST[email], FILTER_VALIDATE_EMAIL)) {
		$emailErr = "Invalid email";
	} else {
		$email = safe_input($_POST[email]);
	}
	if (!preg_match("/^(?=.*\d)(?=.*[A-Za-z])[0-9A-Za-z!@#$%]{6,18}$/", ($password = safe_input($_POST[password])))) {
		$passwordErr = "Must contain 1 number, 1 letter and be 6-18";
	}
	$repassword = safe_input($_POST[repassword]);
	$pass_hash = password_hash($password, PASSWORD_BCRYPT);

	$error = 'your passwords are not the same.</label>';
	$sql = "INSERT INTO $TB_NAME(`Username`, `FirstName`, `Surname`, `Email`, `Password`) VALUES ('$username', '$name', '$surname', '$email', '$pass_hash')";

	if ($password != $repassword) {
		echo $error_msg.$error;
	} else {
		try {
			$stat = $conn->prepare($sql);
			$stat->bindParam(':Username', $username);
			$stat->bindParam(':Password', $password);
			$stat->execute();
			header("Location: login.php");
		} catch (PDOException $e) {
			echo $e->getMessage();
		}
	}
}
?>
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta http-equiv="X-UA-Compatible" content="ie=edge">
		<link rel="stylesheet" href="style.css">
		<title>Signup</title>
	</head>
	<body>
		<div class="signup page">
			<div class="signup form base">
				<h1 class="signup form logo">Camagru</h1>
				<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
					<div class="signup form field">
						<input type="text" name="username" placeholder="Username" class="signup form field" required>
					</div>
					<div class="signup form field">
						<input type="text" name="name" placeholder="First Name" class="signup form field">
					</div>
					<div class="signup form field">
						<input type="text" name="surname" placeholder="Surname" class="signup form field">
					</div>
					<div class="signup form field">
						<input type="email" name="email" placeholder="Email" class="signup form field" required>
					</div>
					<div class="signup form field">
						<input type="password" name="password" placeholder="Password" class="signup form field" required>
					</div>
					<div class="signup form field">
						<input type="password" name="repassword" placeholder="Repassword" class="signup form field" required>
					</div>
					<div class="signup form field">
						<input type="submit" value="Submit" class="signup form field button">
					</div>
				</form>
			</div>
		</div>
	</body>
</html>