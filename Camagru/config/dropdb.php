<?php
require('require.php');

try {
	$drop = "DROP DATABASE IF EXISTS $DB_NAME";
	$conn->exec($drop);
	echo 'whatever the fuck';
} catch (PDOExeption $e) {
	echo $e->getMessage();
}
?>