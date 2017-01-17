<?php

/*
	Generate an amount of random integers between min and max.
	if want to reverse data use rsort()
	if want to perturb data use sort then perturb func
*/
function loadData($fileName)
{
    $data = file_get_contents($fileName);
    $data = explode(PHP_EOL, $data);
    return $data;
}

function generateIntegers($min, $max, $amount)
{
	$data = [];

	for($i = 0;$i<$amount;$i++)
	{
		$data[] = mt_rand($min, $max);
	}

	return $data;
}

function perturb($array,$amount,$length)
{
	for($a = 0;$a<$amount;$a++)
	{
		$i = mt_rand(0, $length-1);
		$j = mt_rand(0, $length-1);
		while ($i == $j)
		{
		 $i = mt_rand(0, $length-1);
		 $j = mt_rand(0, $length-1);
		
		}
		
		if($i != $j)
		{
		 $temp = $array[$i];
		 $array[$i] = $array[$j];
		 $array[$j] = $temp;
		}
		
	}

	return $array;
}


$data = loadData("100000-unsorted-integers.txt");
sort($data);
$data = perturb($data,10000,100000);
$data = implode($data, "
");
file_put_contents("100000-reversed-integers.txt", $data); 