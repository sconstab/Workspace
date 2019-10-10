#!/usr/bin/php
<?php
function ft_is_sort($list) {
	$s_list = $list;
	sort($s_list);
	if ($s_list == $list) {
		return (true);
	}
	else {
		return (false);
	}
}
?>