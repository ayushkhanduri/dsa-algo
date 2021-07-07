// https://leetcode.com/problems/3sum-closest/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int size = nums.size(), closest = nums.at(0) + nums.at(1) + nums.at(2) , closestDiff = closest - target;
	for (int i = 0 ; i < size - 2  ; i++) {
		int a = nums.at(i) , left = i + 1 , right = size - 1;
		while (left < right) {
			int b = nums.at(left), c = nums.at(right) , sum = a + b + c , diff = sum - target;
			if ( abs(diff) < abs(closestDiff) ) {
				closest = sum;
				closestDiff = diff;
			}
			if (sum > target) {
				right--;
			} else {
				left++;
			}

		}
	}
	return closest;
}

int main() {
	vector<int> v = { -1, 2, 1, -4}; // [-4,-1,1,2]
	cout << threeSumClosest(v, 1);
}