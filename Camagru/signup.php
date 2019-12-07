<?php
require_once('header.php');
require_once('config/setup.php');
require('config/require.php');
require('config/database.php');

$usernameErr = $nameErr = $surnameErr = $emailErr = $passwordErr = $passCheckErr = $dupNameErr = $dupEmailErr = "";
$username = $name = $surname = $email = $password = "";
$sql = "SELECT `Username`, `Email` FROM $TB_NAME";
$getUsers = $conn->prepare($sql);
$getUsers->execute();
$users = $getUsers->fetchAll();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
	$username = safe_input($_POST[username]);
	if (!preg_match("/^[a-zA-Z é-]*$/", ($name = safe_input($_POST[name])))) {
		$nameErr = "<div style='color: red'>Invalid name</div>";
	}
	if (!preg_match("/^[a-zA-Z ]*$/", ($surname = safe_input($_POST[surname])))) {
		$surnameErr = "<div style='color: red'>Invalid surname</div>";
	}
	if (empty($_POST[email]) || !filter_var($_POST[email], FILTER_VALIDATE_EMAIL)) {
		$emailErr = "<div style='color: red'>Invalid email</div>";
	} else {
		$email = safe_input($_POST[email]);
	}
	if (!preg_match("/^(?=.*\d)(?=.*[A-Za-z])[0-9A-Za-z!@#$%]{6,18}$/", ($password = safe_input($_POST[password])))) {
		$passwordErr = "<div style='color: red'>Must contain 1 number</br>1 letter and be 6-18 characters</div>";
	}
	foreach ($users as $user) {
		if ($user[Username] == $username) {
			$dupNameErr = "<div style='color: red'>This Username is taken</div>";
		} elseif ($user[Email] == $email) {
			$dupEmailErr = "<div style='color: red'>This email is already in use</div>";
		}
	}
	$repassword = safe_input($_POST[repassword]);
	$pass_hash = password_hash($password, PASSWORD_BCRYPT);
	$sql = "INSERT INTO $TB_NAME(`Username`, `FirstName`, `Surname`, `Email`, `Password`) VALUES ('$username', '$name', '$surname', '$email', '$pass_hash')";

	if ($password != $repassword) {
		$passCheckErr = "<div style='color: red'>Passwords where not the same.</div>";
	} elseif ($usernameErr == "" && $nameErr == "" && $surnameErr == "" && $emailErr == "" && $passwordErr == "" && $passCheckErr == "" && $dupNameErr == "" && $dupEmailErr == "") {
		try {
			$stat = $conn->prepare($sql);
			$stat->bindParam(':Username', $username);
			$stat->bindParam(':Password', $password);
			$stat->execute();
			mail($email, "Confirm", "10.204.19.3:8080/Workspace/Camagru/validate.php?email=$email");
			header("Location: login.php");
		} catch (PDOException $e) {
			echo $e->getMessage();
		}
	}
}
?>

<div class="signup form base">
	<h1 class="signup form logo">Signup</h1>
	<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
		<div class="signup form field">
			<input type="text" name="username" placeholder="Username" class="signup form field" <?php if (isset($username)) {echo 'value="'.$username.'"';} ?> required autofocus>
			<?php echo $usernameErr; if ($dupNameErr != "") {echo $dupNameErr;} ?>
		</div>
		<div class="signup form field">
			<input type="text" name="name" placeholder="First Name" class="signup form field" <?php if (isset($name)) {echo 'value="'.$name.'"';} ?>>
			<?php echo $nameErr; ?>
		</div>
		<div class="signup form field">
			<input type="text" name="surname" placeholder="Surname" class="signup form field" <?php if (isset($surname)) {echo 'value="'.$surname.'"';} ?>>
			<?php echo $surnameErr; ?>
		</div>
		<div class="signup form field">
			<input type="email" name="email" placeholder="Email" class="signup form field" <?php if (isset($email)) {echo 'value="'.$email.'"';} ?> required>
			<?php echo $emailErr; if ($dupEmailErr != "") {echo $dupEmailErr;} ?>
		</div>
		<div class="signup form field">
			<input type="password" name="password" placeholder="Password" class="signup form field" required>
			<?php echo $passwordErr; ?>
		</div>
		<div class="signup form field">
			<input type="password" name="repassword" placeholder="Repassword" class="signup form field" required>
			<?php echo $passCheckErr; ?>
		</div>
		<div class="signup form field">
			<input type="submit" value="Submit" class="signup form field button" id="submit"/>
		</div>
	</form>
</div>

<?php
require_once('footer.php');
?>