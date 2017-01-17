function loadData(textfile)
{
    var fs = require("fs");
    var input = fs.readFileSync(textfile,"utf8");
    input = input.split("\n").map(Number);
 
    return input;       
}

function selectionSort(array)
{
	for (var i = 0; i < array.length; i++)
	{
		var minIndex = i;
		for (var a = i+1; a < array.length; a++)
		{
			if(array[a] < array[minIndex])
			{
				minIndex = a;
			}
		}

		if (minIndex != i)
		{
		        var temp = array[i];
				array[i] = array[minIndex];
				array[minIndex] = temp;
		}
	}

	return array;
}

var data = loadData("100000-almost-sorted-integers.txt");
console.time("executiontime");
selectionSort(data);
console.timeEnd("executiontime");
console.log(data);