<?php
require('config/require.php');

$page = is_numeric($_POST[page]) ? $_POST[page] : 1;
$start = ($page-1) * PER_PAGE;

if ($_POST[type] == "gallery") {
	try {
		$sql = "SELECT `name`, `user` FROM media WHERE `user` = :u ORDER BY `name` LIMIT $start, 10";
		$getPics = $conn->prepare($sql);
		$getPics->bindParam(':u', $_SESSION[username]);
		$getPics->execute();
		$pics = $getPics->fetchAll();
	} catch (PDOException $e) {
		echo $e->getMessage();
	}
} else if ($_POST[type] == "feed") {
	try {
		$sql = "SELECT `name`, `user` FROM media ORDER BY `name` DESC LIMIT $start, 10";
		$getPics = $conn->prepare($sql);
		$getPics->execute();
		$pics = $getPics->fetchAll();
	} catch (PDOEception $e) {
		echo $e->getMessage();
	}
} else {
	return;
}

if (is_array($pics)) {
	if (count($pics) == 0) {
		echo "END";
		return;
	}

	foreach ($pics as $pic) {
		?>
			<img src='./uploads/images/<?php echo $pic[name]?>' class='signup form field'>
		<?php
		if ($_POST[type] == "gallery") {
			?>
			<br/>
			<button class='btn btn-primary delete' onclick="deletePic('<?php echo $pic[name]?>')">Delete</button>
			<br/>
			<?php
		} else if ($_POST[type] == "feed") {
			$sql = "SELECT `like` FROM likes WHERE `name` = :n AND `user` = :u";
			$getLike = $conn->prepare($sql);
			$getLike->bindParam(':n', $pic[name]);
			$getLike->bindParam(':u', $_SESSION[username]);
			$getLike->execute();
			$like = $getLike->fetch();
			?>
			<p>Taken by: <?php echo $pic[user];?></p><br/>
			<?php
			if (isset($_SESSION[username]) && !empty($_SESSION[username])) {
				?>
				<button style='border: none; cursor: pointer;' onclick="likePic('<?php echo $pic[name]?>')">
					<i style="font-size:24px; color: blue;" class="fa">&#xf087;</i>
				</button>
				<?php
				if (isset($like[like]) && !empty($like[like])) {
					echo 'Liked<br/><br/>';
				} else {
					echo 'Not liked<br/><br/>';
				}
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
				<button class="btn btn-primary" style="cursor: pointer;" onclick="commentPic('<?php echo $pic[name]?>')">Comment</button>
			</form>
			<br/>
			<hr style="width: 400px"/>
			<br/>
			<?php
			}
		}
	}
}
?>