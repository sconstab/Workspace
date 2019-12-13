<?php
require('config/require.php');

if (!isset($_GET[email]) || empty($_GET[email])) {
	try {
		$sql = "SELECT `Email` FROM $TB_NAME WHERE `Username` = :u";
		$getEmail = $conn->prepare($sql);
		$getEmail->bindParam(':u', $_SESSION[username]);
		$getEmail->execute();
		$email = $getEmail->fetch();
		mail($email[Email], "Reset password", "10.204.19.3:8080".dirname($_SERVER[PHP_SELF])."/forgotPass.php?email=$email[Email]");

		$sql = "UPDATE $TB_NAME `reset`=1 WHERE `Username` = :u";
		$req = $conn->prepare($sql);
		$req->bindParam(':u', $_SESSION[username]);
		$req->execute();
	} catch (Exception $e) {
		die($e->getMessage());
	}
} else {
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$sql = "SELECT `Password` FROM $TB_NAME WHERE `Username` = :u";
		$getCurrentUser = $conn->prepare($sql);
		$getCurrentUser->bindParam(':u', $_SESSION[username]);
		$getCurrentUser->execute();
		$currentUser = $getCurrentUser->fetch();
		
		if (!preg_match("/^(?=.*\d)(?=.*[A-Za-z])[0-9A-Za-z!@#$%]{6,18}$/", ($_POST[password] = safe_input($_POST[password])))) {
			$passwordErr = "<div style='color: red'>Must contain 1 number</br>1 letter and be 6-18 characters</div>";
		}
		if ($_POST[password] != ($_POST[repassword] = safe_input($_POST[repassword]))) {
			$repasswordErr = "<div style='color: red'>The passwords are not the same</div>";
		}

		$pass_hash = password_hash($_POST[password], PASSWORD_BCRYPT);
		if (password_verify($pass_hash, $currentUser[Password])) {
			$passwordErr = "You have to make a new password";
		}
		try {
			$sql = "UPDATE $TB_NAME `Password`='$pass_hash', `reset`=0 WHERE `Username` = :u";
			$req = $conn->prepare($sql);
			$req->bindParam(':u', $_SESSION[username]);
			$req->execute();
		} catch (PDOException $e) {
			die($e->getMessage());
		}
	}
	require_once('header.php');

	?>
	<script type="text/javascript" src="functions.js" href="js/jquery-1.11.3.min.js"></script>
	<div class="signup form base">
		<h1 class="signup form logo">Reset password</h1>
		<form id="reset-pass" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>?email=<?php echo $_GET[email];?>" method="post">
			<div class="signup form field">
				<input type="password" name="password" placeholder="Password" id="resetPass" class="signup form field" required>
				<?php echo $passwordErr;?>
			</div>
			<div class="signup form field">
				<input type="password" name="repassword" placeholder="Repassword" id="resetRepass" class="signup form field" required>
				<?php echo $repasswordErr;?>
			</div>
			<div class="signup form field">
				<input type="submit" value="Submit" class="signup form field button">
			</div>
		</form>
	</div>
	<?php
	require_once('footer.php');
}
?>