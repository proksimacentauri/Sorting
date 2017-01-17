// selectionsortcpp.cpp : Defines the entry point for the console application.
//

#include<stdio.h>
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;

void selectionSort(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		int minIndex = i;
		for (int a = i + 1; a < length; a++)
		{
			if (array[a] < array[minIndex])
			{
				minIndex = a;
			}
		}

		if (minIndex != i)
		{
			int temporary = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temporary;
		}
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
	vector<int> data = readNumbersFromFile("100-reversed-integers.txt");
	int arr[100];
	std::copy(data.begin(), data.end(), arr);

	auto begin = std::chrono::high_resolution_clock::now();
	selectionSort(arr, 100);
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	//printf("Sorted array:\n");
	printArray(arr, 100);

}