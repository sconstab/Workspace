<?php
require_once('header.php');
require_once('config/setup.php');
require('config/require.php');

$sql = "SELECT `name`, `user` FROM media ORDER BY `name` DESC";
$getPics = $conn->prepare($sql);
$getPics->execute();
$pics = $getPics->fetchAll();
?>

<script type="text/javascript" src="functions.js" href="js/jquery-1.11.3.min.js"></script>
<div class="signup form base feed">
	<h1 class="signup form logo">Feed</h1>
	<?php
	foreach ($pics as $pic) {
		$sql = "SELECT `like` FROM likes WHERE `name` = :n AND `user` = :u";
		$getLike = $conn->prepare($sql);
		$getLike->bindParam(':n', $pic[name]);
		$getLike->bindParam(':u', $_SESSION[username]);
		$getLike->execute();
		$like = $getLike->fetch();
	?>
	<img src='./uploads/images/<?php echo $pic[name]?>'>
	<p>Taken by: <?php echo $pic[user]?></p>
	<br/>
	<?php
		if (isset($_SESSION[username]) && !empty($_SESSION[username])) {
	?>
	<button style='border: none; cursor: pointer;' onclick="likePic('<?php echo $pic[name]?>')">
		<i style="font-size:24px; color: blue;" class="fa">&#xf087;</i>
	</button>
	<?php
			if (isset($like[like]) && !empty($like[like]))
				echo 'Liked<br/><br/>';
			else
				echo 'Not liked<br/><br/>';
		}
		try {
			$sql = "SELECT COUNT(*) FROM likes WHERE `name` = :n AND `like` = 1";
			$likeCount = $conn->prepare($sql);
			$likeCount->bindParam(':n', $pic[name]);
			$likeCount->execute();
			$count = $likeCount->fetch();
			echo "Likes: $count[0]";

			$sql = "SELECT `user`, `comment` FROM comments WHERE `name` = :n";
			$getComments = $conn->prepare($sql);
			$getComments->bindParam(':n', $pic[name]);
			$getComments->execute();
			$comments = $getComments->fetchAll();
		} catch (PDOException $e) {
			echo $e->getMassage();
		}
		foreach ($comments as $comment) {
	?>
		<textarea class="comments"><?php echo $comment[user]?>: <?php echo $comment[comment]?></textarea>
	<?php
		}
		if (isset($_SESSION[username]) && !empty($_SESSION[username])) {
	?>
	<form method="post" action="#" id="<?php echo $pic[name]?>">
		<textarea name="comment" id="comment<?php echo $pic[name]?>" style="border: 2px solid blue;" class="signup form field, comments" autocomplete="off" placeholder="Comment"></textarea>
		<br/>
		<button style="cursor: pointer;" onclick="commentPic('<?php echo $pic[name]?>')">Comment</button>
	</form>
	<br/>
	<hr style="width: 400px"/>
	<br/>
	<?php
		} else {
			?><br/><?php
		}
	}
	?>
</div>

<?php
require_once('footer.php');
?>