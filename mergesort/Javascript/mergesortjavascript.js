var temp = [];

 function loadData(textfile)
{
    var fs = require("fs");
    var input = fs.readFileSync(textfile,"utf8");
    input = input.split("\n").map(Number);
 
    return input;       
}

function merge(data, low, pivot, high)
{

    var h,i,j,k;
    h = low;
    i = low;
    j = pivot+1;

    while((h <= pivot)&&(j <= high))
    {
        if(data[h] <= data[j])
        {
            temp[i] = data[h];
            h++;
        }
        else
        {
            temp[i] = data[j];
            j++;
        }
        i++;
    }
    if(h > pivot)
    {
        for(k = j; k <= high; k++)
        {
            temp[i] = data[k];
            i++;
        }
    }
    else
    {
        for(k = h; k <= pivot; k++)
        {
            temp[i] = data[k];
            i++;
        }
    }
    for(k = low; k<=high; k++)
    {
        data[k] = temp[k];
    }

}

 function mergeSort(array,low,high)
 {
    if(high > low)
    {
        var midPoint = Math.floor((low+high)/2);
        mergeSort(array, low, midPoint);
        mergeSort(array, midPoint+1, high);
        merge(array, low, midPoint, high);
    }
    return array;  
}

var data = loadData("100000-reversed-integers.txt");
console.time("executiontime");
mergeSort(data, 0, data.length - 1);
console.timeEnd("executiontime");
console.log(data)