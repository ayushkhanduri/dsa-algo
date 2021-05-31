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
	cout << endl << "{";
	for (int i : v) {
		cout << i << ",";
	}
	cout << "}";
}

void Sorting:: shift_array(int from, int to, vector<int> &v) {


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

void Sorting:: insertion_sort(vector<int> &v) {
	int size = v.size();
	for (int i = 0 ; i < size ; i++) {
		if (i > 0 && v.at(i) < v.at(i - 1)) {
			int j = i - 1;
			while ( j >= 0 && v.at(j) > v.at(j + 1)) {
				swap_value(j + 1, j , v);
				j =  j - 1;
			}
		}

	}
}

void Sorting:: merge_sort(vector<int> &v) {

}



int main() {
	// vector<int> arrSorted = {1, 2, 3, 4, 5};
	vector<int> other = {4, 3, 2, 10, 12, 1, 5, 6};
	vector<int> arr = { 31, 2, 142, 45, 32, -2, 0, 12, 5, 99, 7, 47, 23};
	Sorting s;
	s.insertion_sort(arr);
	s.print_vectors(arr);
}