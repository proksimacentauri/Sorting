function loadData(textfile)
{
    var fs = require("fs");
    var input = fs.readFileSync(textfile,"utf8");
    input = input.split("\n").map(Number);
 
    return input;       
}

  function swap(array,index,swapIndex)
  {
  	var temporary = array[index];
      array[index] = array[swapIndex];
      array[swapIndex] = temporary;
  }

function qsort(array, low, high)
{ 
  var pivot = array[Math.round((low+high)/2)];
  
  var i = low;
  var j = high;
  while (i <= j)
  {
    while (array[i] < pivot)
    {
      i++;
    }
    while (array[j] > pivot)
    {
      j--;
    }
    if (i <= j)
    {
      swap(array, i, j);
      i++;
      j--;
    }
  }

  if (low < j)
  {
    qsort(array, low, j);
  }
  if (i < high)
  {
    qsort(array, i,high);
  }

  return array;
}

var data = loadData("100-almost-sorted-integers.txt");
console.time("executiontime");
qsort(data,0 , data.length -1);
console.timeEnd("executiontime");
console.log(data)