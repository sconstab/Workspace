#!/usr/bin/php
<?php
$str = array_filter(explode(" ", $argv[1]));
$tmp = array_shift($str);
array_push($str, $tmp);
echo implode(" ", $str)."\n";
?>