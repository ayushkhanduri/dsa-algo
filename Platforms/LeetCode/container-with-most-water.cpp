//https://leetcode.com/problems/container-with-most-water/
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


int maxArea(vector<int>& height) {
	int i = 0, size = height.size() , j = size - 1;
	int max_size = 0;
	while (i < j) {
		int size = (j - i) * min(height[i], height[j]);
		if (size > max_size) {
			max_size = size;
		}
		if (height[i] > height[j]) {
			j--;
		} else if (height[i] <= height[j])  {
			i++;
		}
	}
	return max_size;
}

int maxAreaBrute(vector<int>& height) {
	int size = height.size();
	int max_size = 0;
	for (int i = 0; i < size ; i++ ) {
		for (int j = size - 1 ; j > i ; j--) {
			int newSize = (j - i) * min(height[i], height[j]);
			if (max_size < newSize) {
				max_size = newSize;
			}
		}
	}
	return max_size;
}

int main () {
	static const int arr[] = {4, 3, 2, 1, 4};
	vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	cout << endl << "answer: " <<  maxArea(v);
}