<?php
require('config/require.php');
require_once('header.php');

$error = "";

try {
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$username = $_POST[username];
		$password = $_POST[password];
		$sql = "SELECT `Username`, `FirstName`, `Surname`, `Email`, `Password`, `Valid`, `Notify` FROM $TB_NAME WHERE `Username` = :u OR `Email` = :e";
		$getUsers = $conn->prepare($sql);
		$getUsers->bindParam(':e', $_POST[username]);
		$getUsers->bindParam(':u', $_POST[username]);
		$getUsers->execute();
		$users = $getUsers->fetch();
		
		if (password_verify($_POST[password], $users[Password])) {
			if ($users[Valid] == 1) {
				$_SESSION[username] = $users[Username];
				$_SESSION[name] = $users[FirstName];
				$_SESSION[surname] = $users[Surname];
				$_SESSION[email] = $users[Email];
				$_SESSION[notify] = $users[Notify];
				header("location: index.php");
			} else {
				$error = "<div style='color: red'>Please go check your email<br/>for the verify email</div>";
			}
		} else {
			$error = "<div style='color: red'>wrong username or password</div>";
		}
	}
}
catch (PDOException $message) {
	echo $message->getMessage()	;
}
?>

<div class="signup form base">
	<h1 class="signup form logo">Camagru</h1>
	<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]) ?>" method="POST">
		<div class="signup form field">
			<input type="text" name="username" placeholder="Username/Email" class="signup form field" <?php if (isset($username)) {echo 'value="'.$username.'"';} ?> required>
		</div>
		<div class="signup form field">
			<input type="password" name="password" placeholder="Password" class="signup form field" required>
			<?php echo $error; ?>
		</div>
		<div class="signup form field">
			<input type="submit" value="Login" class="signup form field button">
		</div>
	</form>
</div>

<?php
require_once('footer.php');
?>