<?php
require_once('header.php');
require_once('config/setup.php');
require('config/require.php');
?>

<div class="signup form base">
	<h1 class="signup form logo"><?php echo "Welcome to Camagru"; if (isset($_SESSION[username])) { echo "</br><p style='font-size: 0.5em'>$_SESSION[username]</p></h1>"; } else { echo "</h1><p style='text-align: center;'>please login to customize your experence</p>"; }?>
</div>

<?php
require_once('footer.php');
?>