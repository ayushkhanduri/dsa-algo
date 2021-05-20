//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include "iostream"
#include "vector"

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> set;
	int size = numbers.size(), i = 0, j = size - 1;
	while (i < j) {
		int num1 = numbers.at(i);
		int num2 = numbers.at(j);
		int sum = num1 + num2;
		cout << sum << endl;
		if (sum == target) {
			set.push_back(i + 1);
			set.push_back(j + 1);
			break;
		} else if (sum > target) {
			j--;
		} else {
			i++;
		}

	}
	return set;
}
int main() {
	vector<int> list{50000000, 3, 2, 4, 50000000};
	vector<int> ans = twoSum(list , 100000000);
	for (int v : ans) {
		cout << v;
	}
}