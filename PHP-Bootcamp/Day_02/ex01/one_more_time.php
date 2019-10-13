#!/usr/bin/php
<?php
setlocale(LC_TIME, "fr_FR");
if ($argc == 2) {
	$date2 = "1970-01-01 01:00:00";
	
	$adate = array_filter(explode(" ", $argv[1]));
	array_shift($adate);
	$atime = array_pop($adate);
	$adate[1] = fr_eng($adate[1]);
	$date = implode(" ", $adate);
	$date = date_for($date)." ".$atime;
	$ret = strtotime($date) - strtotime($date2)."\n";
	if ($ret != -3600) {
		echo $ret;
	}
	else {
		echo "Wrong Format";
	}
}

function fr_eng($month) {
	switch($month) {
		case 'janvier':
		case 'Janvier':
			return ("01");
			break;
		case 'février':
		case 'Février':
			return ("02");
			break;
		case 'mars':
		case 'Mars':
			return ("03");
			break;
		case 'avril':
		case 'Avril':
			return ("04");
			break;
		case 'mai':
		case 'Mai':
			return ("05");
			break;
		case 'juin':
		case 'Juin':
			return ("06");
			break;
		case 'juillet':
		case 'Juillet':
			return ("07");
			break;
		case 'août':
		case 'Août':
			return ("08");
			break;
		case 'septembre':
		case 'Septembre':
			return ("09");
			break;
		case 'octobre':
		case 'Octobre':
			return ("10");
			break;
		case 'novembre':
		case 'Novembre':
			return ("11");
			break;
		case 'décembre':
		case 'Décembre':
			return ("12");
			break;

		default:
			return ("false");
			break;
	}
}

function date_for($date) {
	$tabDate = explode(' ' , $date);
	$date  = $tabDate[2].'-'.$tabDate[1].'-'.$tabDate[0];
	return $date;
}
?>