#!/usr/bin/php
<?php
if ($argc == 4) {
	array_shift($argv);
	$arr = array_values(array_filter(explode(" ", implode(" ", $argv))));
	if ($arr[1] == "+") {
		echo (int)$arr[0] + (int)$arr[2]."\n";
	}
	elseif ($arr[1] == "-") {
		echo (int)$arr[0] - (int)$arr[2]."\n";
	}
	elseif ($arr[1] == "*") {
		echo (int)$arr[0] * (int)$arr[2]."\n";
	}
	elseif ($arr[1] == "/") {
		echo (int)$arr[0] / (int)$arr[2]."\n";
	}
	else {
		echo "something broke\n";
	}
}
else {
	echo "Incorrect Parameters\n";
}
?>