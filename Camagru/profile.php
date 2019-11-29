<?php
require('config/require.php');
require_once('header.php');

$nameErr = $surnameErr = $emailErr = $passwordErr = $passCheckErr = $dupNameErr = $dupEmailErr = "";
$username = $name = $surname = $password = $email = $notify = "";
$sql = "SELECT `Username`, `Email` FROM $TB_NAME";
$getUsers = $conn->prepare($sql);
$getUsers->execute();
$users = $getUsers->fetchAll();

try {
	if ($_POST) {
		$_POST[username] = safe_input($_POST[username]);
		if (!preg_match("/^[a-zA-Z é-]*$/", ($_POST[name] = safe_input($_POST[name])))) {
			$nameErr = "<div style='color: red'>Invalid name</div>";
		}
		if (!preg_match("/^[a-zA-Z ]*$/", ($_POST[surname] = safe_input($_POST[surname])))) {
			$surnameErr = "<div style='color: red'>Invalid surname</div>";
		}
		if (!filter_var(($_POST[email] = safe_input($_POST[email])), FILTER_VALIDATE_EMAIL)) {
			$emailErr = "<div style='color: red'>Invalid email</div>";
		}
		if (!empty($_POST[password]) && !preg_match("/^(?=.*\d)(?=.*[A-Za-z])[0-9A-Za-z!@#$%]{6,18}$/", ($_POST[password] = safe_input($_POST[password])))) {
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
		$pass_hash = password_hash($_POST[password], PASSWORD_BCRYPT);

		if (isset($_POST[password]) && $_POST[password] != $repassword) {
			$passCheckErr = "<div style='color: red'>Passwords where not the same.</div>";
		}
		if ($nameErr == "" && $surnameErr == "" && $emailErr == "" && $passwordErr == "" && $passCheckErr == "" && $dupNameErr == "" && $dupEmailErr == "") {
			$username = "`Username`='$_POST[username]'";
			$name = ", `FirstName`='$_POST[name]'";
			$surname = ", `Surname`='$_POST[surname]'";
			$email = ", `Email`='$_POST[email]'";
			if (isset($_POST[password]) && $_POST[password] == $repassword) {
				$password = ", `Password`='$pass_hash'";
			}
			if (isset($_POST[notify])) {
				$notify = ", `Notify`=1";
				$_SESSION[notify] = 1;
			} else {
				$notify = ", `Notify`=0";
				$_SESSION[notify] = 0;
			}

			$sql1 = "UPDATE $TB_NAME SET $username $name $surname $email $password $notify WHERE `Username` = :u";
			$req = $conn->prepare($sql1);
			$req->execute(['u' => $_SESSION[username]]);
			$_SESSION[username] = $_POST[username];
			$_SESSION[name] = $_POST[name];
			$_SESSION[surname] = $_POST[surname];
			$_SESSION[email] = $_POST[email];
		}
	}
} catch (PDOExecption $e) {
	echo $e->getMessage();
}
?>

<div class="signup form base">
	<h1 class="signup form logo">Profile</h1>
	<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]) ?>" method="POST">
		<div class="signup form field">
			<input type="text" name="username" placeholder="Username" class="signup form field" <?php if ($_SESSION[username]) { echo "value='$_SESSION[username]'"; } ?> require>
			<?php echo $dupNameErr; ?>
		</div>
		<div class="signup form field">
			<input type="text" name="name" placeholder="Name" class="signup form field" <?php if ($_SESSION[name]) { echo "value='$_SESSION[name]'"; } ?>>
			<?php echo $nameErr; ?>
		</div>
		<div class="signup form field">
			<input type="text" name="surname" placeholder="Surname" class="signup form field" <?php if ($_SESSION[surname]) { echo "value='$_SESSION[surname]'"; } ?>>
			<?php echo $surnameErr; ?>
		</div>
		<div class="signup form field">
			<input type="text" name="email" placeholder="Email" class="signup form field" <?php if ($_SESSION[email]) { echo "value='$_SESSION[email]'"; } ?> require>
			<?php echo $emailErr; if ($dupEmailErr != "") {echo $dupEmailErr;} ?>
		</div>
		<div class="signup form field">
			<input type="password" name="password" placeholder="Password" class="signup form field">
			<?php echo $passwordErr;?>
		</div>
		<div class="signup form field">
			<input type="password" name="repassword" placeholder="Repassword" class="signup form field">
			<?php echo $passCheckErr;?>
		</div>
		<div class="signup form field">
			Notifications
			<input type="checkbox" name="notify" <?php if ($_SESSION[notify] == 1) {echo "checked";} ?>>
		</div>
		<div class="signup form field">
			<input type="submit" value="Confirm" class="signup form field button">
		</div>
	</form>
</div>

<?php
require_once('footer.php');
?>