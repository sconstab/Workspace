<?php
require_once("header.php");

if (!isset($_SESSION[username]) || empty($_SESSION[username])) {
	header('location: index.php');
}

require("config/require.php");

try {
	$sql = "SELECT `name` FROM media WHERE `user` = :u";
	$getPics = $conn->prepare($sql);
	$getPics->bindParam(':u', $_SESSION[username]);
	$getPics->execute();
	$pics = $getPics->fetchAll();
} catch (PDOException $e) {
	echo $e->getMessage();
}
?>

<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
<script type="text/javascript" src="functions.js" href="js/jquery-1.11.3.min.js"></script>
<div class="signup form base feed">
	<h1 class="signup form logo">Gallery</h1>
	<?php
	foreach ($pics as $pic) {
		?><img src='./uploads/images/<?php echo $pic[name]?>' class='signup form field'>
		<button class='btn btn-primary' onclick="deletePic('<?php echo $pic[name]?>')">
			Delete
		</button>
		<br/>
		<?php
	}
	?>
</div>

<?php
require_once("footer.php")
?>