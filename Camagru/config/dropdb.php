<?php
require('require.php');

try {
	$loc = __DIR__;
	$loc = substr($loc, 0, strrpos($loc, '/'));
	$drop = "DROP DATABASE IF EXISTS $DB_NAME";
	$conn->exec($drop);
	$files = glob($loc."/uploads/images/*");
	foreach($files as $file){
		if(is_file($file))
			unlink($file);
	}
	session_destroy();
	echo 'whatever the fuck';
} catch (PDOExeption $e) {
	echo $e->getMessage();
}
?>