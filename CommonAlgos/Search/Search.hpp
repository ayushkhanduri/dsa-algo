#pragma once

#include "vector"

using namespace std;

class Search {
public:
	static int linearSearch(vector<int> &arr, int item);
	static int binarySearch(vector<int> &arr, int item);
};