<?php
require('config/require.php');
require_once('config/setup.php');
require_once('header.php');
?>

<script type="text/javascript" src="functions.js" href="js/jquery-1.11.3.min.js"></script>
<script>
window.onload = function() {
	window.addEventListener("scroll", endless.listenFeed);
	endless.load("feed");
};
</script>
<div class="signup form base feed">
	<h1 class="signup form logo">Feed</h1>
	<div id="page-content"></div>
	<div id="page-loading">Now Loading...</div>
</div>

<?php
require_once('footer.php');
?>