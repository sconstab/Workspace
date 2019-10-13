#!/usr/bin/php
<?php
function ft_ascii($char) {
	$ascii = ord($char);

	if ($ascii == 0) {
		return ($ascii);
	}
	if ($ascii < 48 || ($ascii >= 91 && $ascii <= 96) || $ascii > 122) {
		$ascii += 1000;
	}
	elseif (is_numeric($char)) {
		$ascii += 100;
	}
	elseif (ctype_upper($char)) {
		$ascii += 32;
	}
	return ($ascii);
}

function ft_sort($str1, $str2) {
	$len1 = strlen($str1);
	$len2 = strlen($str2);
	for ($i=0; $i<$len1 && $i<$len2; $i++) {
		$asc1 = ft_ascii($str1[$i]);
		$asc2 = ft_ascii($str2[$i]);
		if ($asc1 != $asc2) {
			return ($asc1 < $asc2) ? -1 : 1;
		}
	}
	if ($len1 == $len2) {
		return (0);
	}
	return ($len1 == $i) ? -1 : 1;
}

if ($argc < 2) {
	exit();
}
array_shift($argv);
$str = explode(" ", implode(" ", $argv));
usort($str, "ft_sort");
foreach ($str as $v) {
	echo $v."\n";
}
?>