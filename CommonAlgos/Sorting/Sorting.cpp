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

vector<int> Sorting:: sliceVector(vector<int> v, int start, int end) {
	vector<int> slicedVector;
	for (int i = start; i < end; i++) {
		slicedVector.push_back(v.at(i));
	}
	return slicedVector;
}

vector<int> Sorting:: merge_vectors(vector<int> vectorLeft, vector<int> vectorRight) {
	vector<int> mergedVector ;
	int left_size = vectorLeft.size(), right_size = vectorRight.size();
	int left = 0, right = 0;
	while (left != left_size || right != right_size) {
		int leftValue = INT_MAX, rightValue = INT_MAX ;
		if (left < left_size) {
			leftValue = vectorLeft.at(left);
		}
		if (right < right_size ) {
			rightValue = vectorRight.at(right);
		}
		int value = 0;
		if (leftValue < rightValue) {
			value = leftValue;
			left++;
		} else {
			value = rightValue;
			right++;
		}
		mergedVector.push_back(value);
	}
	return mergedVector;
}

vector<int> Sorting:: merge_sort_recursion(vector<int> &v) {
	if (v.size() == 1) {
		return v;
	} else {
		int end = v.size(), start = 0 , mid = end / 2 ;
		vector<int> leftArr = sliceVector(v, start, mid);
		vector<int> rightArr = sliceVector(v, mid, end);
		vector<int> leftSorted = merge_sort_recursion(leftArr);
		vector<int> rightSorted = merge_sort_recursion(rightArr);
		return merge_vectors(leftSorted, rightSorted);
	}
}

vector<int> Sorting:: merge_sort(vector<int> &v) {
	vector<int> mergedSortedArr;
	return merge_sort_recursion(v);
}



int main() {
	vector<int> arrSorted = {1, 2, 3, 4, 5};
	vector<int> other = {4, 3, 2, 10, 12, 1, 5, 6};
	vector<int> arr = { 31, 2, 142, 45, 32, -2, 0, 12, 5, 99, 7, 47, 23};
	vector<int> sampled = {7, 218 , 49, 32, 540, 525, 808, 293};
	Sorting s;
	vector<int> sortedVector = s.merge_sort(other);
	s.print_vectors(sortedVector);
}