<?php
require_once("header.php");

if (!isset($_SESSION[username]) || empty($_SESSION[username])) {
	header('location: index.php');
}

require("config/require.php");
?>

<script type="text/javascript" src="functions.js" href="js/jquery-1.11.3.min.js"></script>
<div class="signup form base feed">
	<h1 class="signup form logo">Camera</h1>
	<div id="newImages"></div>
	<div id="wrapper">
		<video id="player" autoplay></video>
		<canvas id="canvasPic" width="320px" height="240px"></canvas>
		<canvas id="canvasSti" width="320px" height="240px"></canvas>
		<br/>
	</div>
	<div>Please select some stickers if you want</div>
	<br/>
	<div>
		<img src="stickers/CuteCat.png" id="cuteCat" style="height: 120px; width: 120; cursor: pointer;" onclick="cute('cuteCat')">
		<img src="stickers/JaredsPedguin.png" id="cutePed" style="height: 120px; width: 120;" onclick="cute('cutePed')">
	</div>
	<div>
		<img src="stickers/CuteOtter.png" id="cuteOtt" style="height: 120px; width: 120;" onclick="cute('cuteOtt')">
		<img src="stickers/CuteDog.png" id="cuteDog" style="height: 120px; width: 120;" onclick="cute('cuteDog')">
	</div>
	<div class="camera btn">
		<button class="btn btn-primary" onclick="resetPic()">Reset</button>
		<button class="btn btn-primary" id="capture-btn" onclick="capturePic()">Capture</button>
		<button class="btn btn-primary" onclick="savePic()">Save</button>
	</div>
	<br/>
	<div id="pick-image">
		<input type="file" accept="image/*" id="image-picker">
	</div>
</div>
<script src="camera.js"></script>

<?php
require_once("footer.php");
?>