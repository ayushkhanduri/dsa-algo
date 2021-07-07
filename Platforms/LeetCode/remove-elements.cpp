//https://leetcode.com/problems/remove-element/
// 100%
#include "iostream"
#include "vector"
#include "unordered_map"
#include "./utils/LeetCode.hpp"

using namespace std;

int removeElement(vector<int>& nums, int val) {
	int size = nums.size(), counter = 0, latestPositionToSwap = -1;
	unordered_map<int, bool> umap;
	for (int i = 0 ; i < size ; i++) {
		if (nums.at(i) == val) {
			if (latestPositionToSwap == -1) {
				latestPositionToSwap = i;
			}
			nums.at(i) = -1;
		} else {
			counter++;
			if (latestPositionToSwap != -1) {
				// cout << "i: " << i << " , latestPositionToSwap: " << latestPositionToSwap << endl;
				Utility::swap_value(i, latestPositionToSwap, nums);
				latestPositionToSwap++;
			}
		}
	}
	// Utility::print_vectors(nums);
	return counter;
}

int main() {
	vector<int> nums = {3, 2, 2, 3};
	int val = 3;
	int size = removeElement(nums, val);
	cout << size;
}
