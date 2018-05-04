// Project2.cpp : Defines the entry point for the console application.
// Jared Carlson
// COSC 2030
//April 26, 2018

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Helper.h"
#include <string>
#include <algorithm> //Used for testing purposes

using namespace std;

void QuickSortTest(vector<int> &vec);
void BinarySearchTest(vector<int> &vec);
void MergeSortTest(vector<int> &vec);
void HashTest();
void BloomFilterTest();

int main()
{
	//Vector for quicksort
	vector<int> myVec = { 5, 2, 7, 10, 3, 15, 80, 4, 8, 21, 45, 2 };
	//vector for binary search
	vector<int> BinarySearchVec = { 4,12,2,1,7,3,5,6,21,18,8 };
	//vector for merge sort
	vector<int> MergeSortVec = { 12,7,3,20,4,6,2,4,15,5,7,8,3,4,6 };

	/*----------Test Cases----------*/
	QuickSortTest(myVec);
	BinarySearchTest(BinarySearchVec);
	MergeSortTest(MergeSortVec);
	HashTest();
	BloomFilterTest();
	
	system("pause");
    return 0;
}
//QuickSort Test Function
void QuickSortTest(vector<int> &vec)
{
	vector<int> stlvec = vec; //test vector
	cout << "*/-----QuickSort-----/*" << endl;
	cout << "Unsorted Vector: " << endl;
	printVector(vec);
	cout << "Vector sorted with Quicksort: " << endl;	
	QuickSort(vec);
	printVector(vec);
	//Compare with stl
	cout << "Vector sorted with stl sort: " << endl;
	sort(stlvec.begin(), stlvec.end());
	printVector(stlvec);
}
//BinarySearch Test Function
void BinarySearchTest(vector<int> &vec)
{
	int n = vec.size();
	int x = 21, y = 4;
	cout << "*/-----BinarySearch-----/*" << endl;
	cout << "Vector Sorted: " << endl;
	QuickSort(vec);
	printVector(vec);

	cout << "Searching for: " << x << endl;
	int IndexLocation = binarySearch(vec, 0, n - 1, x);
	cout << "Index Location of: " << x << ": "<< IndexLocation << endl;
	

	cout << "Searching for: " << y << endl;
	IndexLocation = binarySearch(vec, 0, n - 1, y);
	cout << "Index Location of: " << y << ": " << IndexLocation << endl;
}
//MergeSort Test Function
void MergeSortTest(vector<int> &vec)
{
	vector<int> stlvec = vec; //test vector
	cout << "*/-----MergeSort-----/*" << endl;
	cout << "Unsorted Vector: " << endl;
	printVector(vec);
	mergeSort(vec, 0, vec.size() - 1);
	cout << "Vector Sorted with MergeSort: " << endl;
	printVector(vec);
	//Compare with stl
	cout << "Vector sorted with STL Sort: " << endl;
	sort(stlvec.begin(), stlvec.end());
	printVector(stlvec);
}
//HashFunction Test Function
void HashTest()
{
	string Hash1 = "Hello";
	string Hash2 = "18563748697354627601";

	cout << "*/-----Text/Int To Int Hash-----/*" << endl;
	cout << "hashing: Hello" << endl;
	cout << "Hash: " <<myHash(Hash1) << endl;
	cout << "Hashing: 18563748697354627601" << endl;
	//max int size is 20
	cout << "Hash: " << myHash(Hash2) << endl;
}
//BloomFilter Test Function
void BloomFilterTest()
{
	cout << "*/-----BloomFilter-----/*" << endl;
	 
	BloomFilter bloom(1000, 3);
	string searchWord = "Hello";
	cout << "Search Word: " << searchWord << endl;
	for (std::string::iterator iter = searchWord.begin(); iter != searchWord.end(); iter++)
	{
		bloom.add(*iter);
	}
	
	for (std::string::iterator iter = searchWord.begin(); iter != searchWord.end(); iter++)
	{
		cout << "Searching for: " << *iter << endl;

		if (bloom.possiblyContains(*iter) == false)
		{
			cout << "Character Not found" << endl;
		}
		else
		{
			cout << "Character found!" << endl;
		}
	}

	searchWord = "Batman";

	cout << "Now searcing for word not in filter: " << searchWord << endl;

	for (std::string::iterator iter = searchWord.begin(); iter != searchWord.end(); iter++)
	{
		cout << "Searching for: " << *iter << endl;

		if (bloom.possiblyContains(*iter) == false)
		{
			cout << "Character Not found" << endl;
		}
		else
		{
			cout << "Character found!" << endl;
		}
	}
}
