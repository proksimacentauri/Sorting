function loadData(textfile)
{
    var fs = require("fs");
    var input = fs.readFileSync(textfile,"utf8");
    input = input.split("\n").map(Number);
 
    return input;       
}

function bubbleSort(array)
{

    for (var a = 0; a < array.length; a++)
	{
		for (var i = 0; i < array.length ; i++)
		{
			if (array[i] > array[i+1])
			{
				var temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
	}

	return array;
}

var data = loadData("100-unsorted-integers.txt");
console.time("executiontime");
bubbleSort(data);
console.timeEnd("executiontime");
console.log(data);