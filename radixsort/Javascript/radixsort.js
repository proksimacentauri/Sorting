function loadData(textfile)
{
    var fs = require("fs");
    var input = fs.readFileSync(textfile,"utf8");
    input = input.split("\n").map(Number);
 
    return input;       
}

function getMax(array) {
    var max = 0;
    for(var i = 1; i < array.length; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

function radixSort(array,length)
{
var high = getMax(array);
var result = [];
for(var exp = 1; Math.floor(high/exp) > 0; exp *= 10)
{
  var c = [];

  var index; 
  for(var i = 0; i < 10; i++)
  {
  	c[i] = 0;
  }

  for(var b = 0; b < length; b++)
  {
  	index = Math.floor(array[b]/exp);
 	c[index%10]++;
  }
    
  for(var a = 1 ; a < 10; a++)
  {
 	c[a] += c[a-1];
  }

  
  
  for (var j = length - 1; j >= 0; j--)
  {
   index = Math.floor(array[j]/exp);
   result[c[index % 10] - 1] = array[j];
   c[index % 10] -= 1;
   
 }

  for (var i = 0; i < length; i++)
  {
    array[i] = result[i];
  }
}
  
}

var data = loadData("100000-almost-sorted-integers.txt");
var len = data.length;
console.time("executiontime");
radixSort(data,len);
console.timeEnd("executiontime");
console.log(data)