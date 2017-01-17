// radixsort.cpp : Defines the entry point for the console application.
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

int getMax(int* array, int length)
{
	int max = 0;
	for (int i = 1; i < length; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

void radixSort(int* array, int length)
{
	int high = getMax(array,length);
	for (int exp = 1; (high / exp) > 0; exp *= 10)
	{
		int c[10] = { 0 };
		int* result = new int[length];
		int index;

		for (int b = 0; b < length; b++)
		{
			index = array[b] / exp;
			c[index % 10]++;
		}

		for (int a = 1; a < 10; a++)
		{
			c[a] += c[a - 1];
		}


		for (int j = length - 1; j >= 0; j--)
		{
			index = array[j] / exp;
			result[c[index % 10] - 1] = array[j];
			c[index % 10] -= 1;

		}

		for (int i = 0; i < length; i++)
		{
			array[i] = result[i];
		}
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
	vector<int> data = readNumbersFromFile("100000-unsorted-integers.txt");
	int arr[100000];
	std::copy(data.begin(), data.end(), arr);
	auto begin = std::chrono::high_resolution_clock::now();
	radixSort(arr, 100000);
    auto end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
	//printf("Sorted array:\n");
	printArray(arr, 100000);

}
