<?php
require_once('config/setup.php');
require('config/require.php');
require_once('header.php');
?>

<br/>
<?php if (isset($_SESSION[username])) {echo "Welcome ".$_SESSION[username]." ".$_SESSION[notify]; }?>

<?php
require_once('footer.php');
?>