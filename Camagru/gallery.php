<?php
session_start();
if (!isset($_SESSION[username]) || empty($_SESSION[username])) {
	header('location: index.php');
}

require("config/require.php");
require_once("header.php");
?>

<script type="text/javascript" src="functions.js"></script>
<script>
window.onload = function() {
	window.addEventListener("scroll", endless.listenGallery);
	endless.load("gallery");
};
</script>
<div class="signup form base feed">
	<h1 class="signup form logo">Gallery</h1>
	<div id="page-content"></div>
	<div id="page-loading">Now Loading...</div>
</div>

<?php
require_once("footer.php")
?>