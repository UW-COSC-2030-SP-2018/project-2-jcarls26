//Helper.cpp
//Jared Carlson
//COSC 2030
//April 26, 2018
#include "stdafx.h"
#include "Helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void mySwap(int *ptr1, int *ptr2);
void partitionAndsort(vector<int> & myVec, int low, int high);
void mergeNumbers(std::vector<int> &mergevec, int left, int middle, int right);


//Quicksort
vector<int> QuickSort(vector<int>& vec1)
{
	partitionAndsort(vec1, 0, vec1.size() - 1);
	return vec1;
}
//Binary Search
int binarySearch(vector<int> &vec1, int startPoint, int endPoint, int x)
{
	vector<int> SortedVec = QuickSort(vec1);

	if (endPoint >= startPoint)
	{
		int mid = (endPoint + startPoint) / 2;
		cout << "value at mid: " << SortedVec.at(mid) << endl;

		if (SortedVec.at(mid) == x)
		{
			return mid;
		}
		if (SortedVec.at(mid) > x)
		{
			return binarySearch(SortedVec, startPoint, mid - 1, x);
		}
		
		return binarySearch(SortedVec, mid + 1, endPoint, x);
	}
	
	return -1;
}
//Merge Sort
void mergeSort(std::vector<int> &mergevec, int leftIndex, int rightIndex)
{
	if (rightIndex > leftIndex)
	{
		int middleIndex = (leftIndex + rightIndex) / 2;
		mergeSort(mergevec, leftIndex, middleIndex);
		mergeSort(mergevec, middleIndex + 1, rightIndex);
		mergeNumbers(mergevec, leftIndex, middleIndex, rightIndex);
	}


}
void mergeNumbers(std::vector<int> &mergevec, int left, int middle, int right)
{
	//Temp Vectors
	std::vector<int> Vl, Vr;
	int sizeleft = middle - left + 1;
	int sizeright = right - middle;
	for (int i = 0; i < sizeleft; i++)
	{
		Vl.push_back(mergevec.at(left + i));
	}
	for (int j = 0; j < sizeright; j++)
	{
		Vr.push_back(mergevec.at(middle + 1 + j));
	}

	int leftcounter = 0, rightcounter = 0, k = left;

	while (leftcounter < Vl.size() && rightcounter < Vr.size())
	{
		if (Vl.at(leftcounter) <= Vr.at(rightcounter))
		{
			mergevec.at(k) = Vl.at(leftcounter);
			leftcounter++;
		}
		else
		{
			mergevec.at(k) = Vr.at(rightcounter);
			rightcounter++;
		}
		k++;
	}
	while (leftcounter < Vl.size())
	{
		mergevec.at(k) = Vl.at(leftcounter);
		leftcounter++;
		k++;
	}

	while (rightcounter < Vr.size())
	{
		mergevec.at(k) = Vr.at(rightcounter);
		rightcounter++;
		k++;
	}
}
//My hash 
unsigned int myHash(string input)
{
	srand(45);
	unsigned int seed = rand();
	unsigned int hash = 5;

	for (std::size_t i = 0; i < input.length(); i++)
	{
		hash = (hash * seed) + input[i];
	}

	return hash;
}
unsigned int myHash(int input)
{
	string convertedInt = std::to_string(input);
	return myHash(convertedInt);
}
//Bloom Filter
BloomFilter::BloomFilter(uint64_t size, uint8_t numHashes)
{
	m_bits.resize(size);
	m_numHashes = numHashes;
}
uint64_t BloomFilter::nthHash(uint8_t n, char data, uint64_t filterSize) 
{
	std::hash<uint8_t> stlHash;
	return (myHash(data) + n * stlHash(data)) % filterSize;
}
void BloomFilter::add(char data) 
{
	for (int n = 0; n < m_numHashes; n++) 
	{
		m_bits[nthHash(n, data, m_bits.size())] = true;
	}
}
bool BloomFilter::possiblyContains(char data)
{
	for (int n = 0; n < m_numHashes; n++)
	{
		if (m_bits[nthHash(n, data, m_bits.size())] == false)
		{
			return false;
		}
	}
	
	return true;
}

//print function used for program
void printVector(vector <int> myVector)
{
	vector <int>::iterator it = myVector.begin();
	for (it = myVector.begin(); it != myVector.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void partitionAndsort(vector<int> & myVec, int low, int high)
{
	int i = low, j = high;
	int tmp;
	int elementPivot = floor((low + high) / 2);
	double pivot = myVec.at(elementPivot);

	/* partition */
	while (i <= j)
	{
		while (myVec.at(i) < pivot)
			i++;
		while (myVec.at(j) > pivot)
			j--;
		if (i <= j)
		{
			mySwap(&myVec.at(i), &myVec.at(j));
			i++;
			j--;
		}
	}

	/* recursion */
	if (low < j)
		partitionAndsort(myVec, low, j);
	if (i < high)
		partitionAndsort(myVec, i, high);
}

//swap used in quicksort function
void mySwap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
