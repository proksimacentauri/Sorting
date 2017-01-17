// heapsort.cpp : Defines the entry point for the console application.
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

void buildMaxHeap(int* array, int length, int i)
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int largest = i;
	if (left < length && array[left] > array[i])
	{
		largest = left;
	}

	if (right < length && array[right] > array[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		buildMaxHeap(array, length, largest);
	}
}

static void heapSort( int* array, int length)
{
	int n = length / 2;

	for (int i = n - 1; i >= 0; i--)
	{
		buildMaxHeap(array, length, i);

	}

	for (int i = length - 1; i >= 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		buildMaxHeap(array, i, 0);
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
	heapSort(arr, 100000);
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	//printf("Sorted array:\n");
	printArray(arr, 100000);

}
