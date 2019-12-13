<?php
if (session_status() == PHP_SESSION_NONE) {
	session_start();
}

require('database.php');
$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
define('PER_PAGE', 10);

$location = "/Workspace/Camagru/uploads/images/";

function safe_input($data) {
	$data = trim($data);
	$data = stripslashes($data);
	$data = htmlspecialchars($data);
	return ($data);
}

function scriptPath() {
    list($scriptPath) = get_included_files();
    return($scriptPath);
}

class Content {
	public $pdo = null;
	private $stmt = null;

	function __construct() {
		try {
			echo "hello";
			$this->pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
			return true;
		} catch (PDOException $e) {
			die($e->getMessage());
		}
	}

	function __destruct() {
		if ($this->stmt !== null) {$this->stmt = null;}
		if ($this->pdo !== null) {$this->pdo = null;}
	}

	function get($start=0, $end=10) {
		$sql = "SELECT `name`, `user` FROM media ORDER BY `name` DESC LIMIT $start, $end";
		$this->stmt = $this->pdo->prepare($sql);
		$this->stmt->execute();
		$pics = $this->stmt->fetchAll();
		return count($pics) == 0 ? false : $pics;
	}
}
?>