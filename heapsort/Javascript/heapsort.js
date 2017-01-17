function loadData(textfile)
{
    var fs = require("fs");
    var input = fs.readFileSync(textfile,"utf8");
    input = input.split("\n").map(Number);
 
    return input;       
}

function heapSort(array)
{
	var len = array.length;
    n = Math.floor(len/2);
	for(var i = n - 1 ; i >= 0; i--)
	{
		buildMaxHeap(array, len, i);
			
	}

	 for (var i=len-1; i>=0; i--)
    {
        var temp = array[0];
        array[0] = array[i];
        array[i] = temp;
       
        buildMaxHeap(array, i, 0);
    }
}


function buildMaxHeap(array,length,i)
{
 var left = 2*i;
 var right = 2*i+1;
 var largest = i;
 if(left < length && array[left] > array[i])
 {
 	largest = left;
 }

 if(right < length && array[right] > array[largest])
 {
 	largest = right;
 }

 if(largest != i)
 {
 	var temp = array[i];
 	array[i] = array[largest];
 	array[largest] = temp;
 	buildMaxHeap(array,length,largest);
 }
  
}

var data = loadData("100-almost-sorted-integers.txt");
var len = data.length;
console.time("executiontime");
heapSort(data);
console.timeEnd("executiontime");
console.log(data);