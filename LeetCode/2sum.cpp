//https://leetcode.com/problems/two-sum/

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "unordered_map"

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> set;
	int size = nums.size();
	unordered_map<int, int> map;
	for (int i = 0; i <= (size / 2 + 1) ; i++ ) {
		map.insert({ nums.at(i) , i} );
		map.insert({nums.at(size - 1 - i), (size - 1 - i)});
		int diff = target - nums.at(i);
		cout << "diff:" << diff << endl;
		cout << "map:" << map.at(diff) << endl;
		try {
			int index = map.at(diff);
			if (index != i) {
				set.push_back(i);
				set.push_back(index);
				break;
			}
		} catch (const out_of_range& oor) {
			continue;
		}
	}
	return set;
}

int main() {
	unordered_map<int, int> map;
	map.insert({10, 100});
	map.insert({10, 200});

	for (auto i : map) {
		cout << i.first << ": " << i.second << endl;
	}
	// vector<int> list{50000000, 3, 2, 4, 50000000};
	// vector<int> ans = twoSum(list , 100000000);
	// for (int v : ans) {
	// 	cout << v;
	// }
}