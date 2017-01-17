function loadData(textfile)
{
    var fs = require("fs");
    var input = fs.readFileSync(textfile,"utf8");
    input = input.split("\n").map(Number);
 
    return input;       
}

function insertSort(array)
{
    for (var i = 0; i < array.length; i++)
    {
        var insert = array[i];
        var j = i;

        while (j > 0 && array[j - 1] > insert)
        {
            array[j] = array[j - 1];
            j = j - 1;
        }
       
        array[j] = insert;
    }

   return array;
}


var data = loadData("100-reversed-integers.txt");
console.time("executiontime");
insertSort(data);
console.timeEnd("executiontime");
console.log(data)
