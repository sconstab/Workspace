#!/usr/bin/php
<?php
for ($x=1; $x<$argc; $x++) {
	$str.=" ".$argv[$x];
}
$str = array_filter(explode(' ', $str));
$x = 0;
foreach ($str as $key => $value) {
	if (is_string($str[$x++])) {
		$str2[$key] = $value;
		/* unset($str[$key]); */
	}
}
print_r($str);
print_r($str2);

rsort($str);
foreach ($str as $v) {
	echo $v."\n";
}
?>