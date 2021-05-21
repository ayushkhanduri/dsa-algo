#include "iostream"
#include "vector"
#include "algorithm"
#include "Search.hpp"

using namespace std;

int Search::linearSearch(vector<int> &arr, int item) {
	int index = -1 ;
	for (int i = 0 ; i < arr.size(); i++) {
		if (arr.at(i) == item) {
			index = i;
			break;
		}
	}
	return index;
}

int Search::binarySearch(vector<int> &arr, int item) {
	int index = -1, left = 0 , right = arr.size() - 1;
	int iterations = 0;
	while (left <= right) {
		int center = left + (right - left) / 2;
		int value = arr.at(center);
		if (value == item ) {
			index = center;
			break;
		} else if (value < item) {
			left = center + 1;
		} else {
			right = center - 1;
		}
	}
	return index;
}


int main() {
	vector<int> v = { 1, 23, 42, 49, 82, 99, 201, 492, 1029};

	cout << Search::binarySearch(v, 1029);
}