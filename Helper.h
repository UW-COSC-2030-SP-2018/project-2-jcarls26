//Helper.h
//Jared Carlson
//COSC 2030
//April 26, 2018
#ifndef INCLUDE_HELPER_CPP_H
#define INCLUDE_HELPER_CPP_H

#include <vector>

std::vector<int> QuickSort(std::vector<int>& vec1);
void printVector(std::vector <int> myVector);
int binarySearch(std::vector<int> &vec1, int l, int r, int x);
void mergeSort(std::vector<int> &mergevec , int leftIndex, int rightIndex);
unsigned int myHash(std::string input);
unsigned int myHash(int input);

struct BloomFilter {
	BloomFilter(uint64_t size, uint8_t numHashes);

	void add(char data);
	bool possiblyContains(char data);

private:
	uint64_t nthHash(uint8_t n, char data, uint64_t filterSize);
	uint8_t m_numHashes;
	std::vector<bool> m_bits;
};

#endif;
