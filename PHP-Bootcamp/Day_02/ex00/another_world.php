#!/usr/bin/php
<?php
echo trim(preg_replace("/[ ]{2,}|[\t]/", " ", $argv[1]))."\n";
?>