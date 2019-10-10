#!/usr/bin/php
<?php
for ($x=1; $x<$argc; $x++) {
	$str.=" ".$argv[$x];
}
$str = array_filter(explode(' ', $str));
sort($str);
foreach ($str as $v) {
	echo $v."\n";
}
?>