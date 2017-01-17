#include<stdio.h>
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

const long max_arraySize = 100001;
int temp[max_arraySize];

void merge(int*data, int low, int pivot, int high)
{
	int h, i, j, k;
	h = low;
	i = low;
	j = pivot + 1;

	while ((h <= pivot) && (j <= high))
	{
		if (data[h] <= data[j])
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
	if (h > pivot)
	{
		for (k = j; k <= high; k++)
		{
			temp[i] = data[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= pivot; k++)
		{
			temp[i] = data[k];
			i++;
		}
	}
	for (k = low; k <= high; k++)
	{
		data[k] = temp[k];
	}
}

void mergeSort(int* array, int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;

		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);

		merge(array, low, mid, high);
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

string readFileToString(string filename)
{
	ifstream file;
	file.open(filename, ifstream::in);

	string content((istreambuf_iterator<char>(file)),
		(istreambuf_iterator<char>()));

	return content;
}

// should return vector<int> containing all the numbers in a given file
vector<int> readNumbersFromFile(string filename)
{
	string asString = readFileToString(filename);
	vector<string> lines;
	vector<int> numbers;

	stringstream stream(asString);
	string line;

	while (getline(stream, line)) {
		lines.push_back(line);
	}

	// convert the lines into integers and
	// push them onto the integers vector
	for (int i = 0; i < lines.size(); i++)
	{
		int converted = stoi(lines[i]);
		numbers.push_back(converted);
	}

	return numbers;
}

void main()
{
	vector<int> data = readNumbersFromFile("100000-almost-sorted-integers.txt");
	int arr[100000];
	std::copy(data.begin(), data.end(), arr);

	auto begin = std::chrono::high_resolution_clock::now();
	mergeSort(arr, 0, 100000- 1);
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	//printf("Sorted array:\n");
	printArray(arr, 100000);

}