#include "iostream"
#include "vector"
#include "Sorting.hpp"

using namespace std;

void Sorting::swap_value(int from, int to, vector<int> &v) {
	int fromItem = v.at(from);
	v.at(from) = v.at(to);
	v.at(to) = fromItem;
}

void Sorting::print_vectors(vector<int> &v) {
	cout << "{";
	for (int i : v) {
		cout << i << ",";
	}
	cout << "}";
}

void Sorting:: selection_sort(vector<int> &v) {
	int size = v.size();
	for (int i = 0 ; i < size ; i++) {
		int smallestIndex = i;
		for (int j = i + 1; j < size ; j ++ ) {
			if (v.at(j) < v.at(smallestIndex)) {
				smallestIndex = j;
			}
		}
		swap_value(i, smallestIndex, v);
	}
}

void Sorting:: bubble_sort(vector<int> &v) {
	int size = v.size();
	for (int i = 0; i < size ; i++) {
		int passes = 0;
		for (int j = 0; j < size - 1 ; j++) {
			if (v.at(j) > v.at(j + 1)) {
				passes++;
				swap_value(j, j + 1, v);
			}
		}
		if (passes == 0) {
			break;
		}
	}
}
int main() {
	// vector<int> arrSorted = {1, 2, 3, 4, 5};
	vector<int> arr = { 31, 2, 142, 45, 32, -2, 0, 12, 5, 99, 7, 99, 47, 23};
	Sorting s;
	s.bubble_sort(arr);
	s.print_vectors(arr);
}