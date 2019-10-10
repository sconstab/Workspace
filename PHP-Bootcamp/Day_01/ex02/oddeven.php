#!/usr/bin/php
<?php
while (!feof(STDIN)) {
	echo "Enter a number: ";
	$input = rtrim(fgets(STDIN), "\n\r");
	
	if (feof(STDIN)) {
		echo "^D\n";
		return ;
	}
	if (is_numeric($input)) {
		if (($input % 2) == 0) {
			echo "The number $input is even\n";
		}
		else {
			echo "The number $input is odd\n";
		}
	}
	else {
		echo "'$input' is not a number\n";
	}
}
?>