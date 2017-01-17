// qu// quicksortcpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int* array, int index, int swapIndex)
{
	int temporary = array[index];
	array[index] = array[swapIndex];
	array[swapIndex] = temporary;
}

void qsort(int* array, int low, int high)
{	
	int pivot = array[(low+high)/2];
	int i = low;
	int j = high;
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
	vector<int> data = readNumbersFromFile("100000-reversed-integers.txt");
	int arr[100000];
	std::copy(data.begin(), data.end(), arr);
	
	
	auto begin = std::chrono::high_resolution_clock::now();
	qsort(arr, 0, 100000 - 1);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	//printf("Sorted array:\n");
	printArray(arr, 100000);
	
}