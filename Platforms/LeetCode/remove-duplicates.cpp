//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;


int removeDuplicates(vector<int>& nums) {
	int size = nums.size(), start = 0 , lastIndex = size - 1;
	unordered_map<int, bool> mapping;
	for (int i = 0 ; i < size ; i++) {
		if ( mapping.find(nums.at(i)) == mapping.end() ) {
			mapping.insert({nums.at(i), true});
			nums.at(start) = nums.at(i);
			start++;
		}
	}
	return start;
}

int main() {
	vector<int> v = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int unique = removeDuplicates(v);
	cout << unique;
}


