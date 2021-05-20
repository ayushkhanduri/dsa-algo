#include "iostream"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "sstream"

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	int size = nums.size();
	vector<vector<int>> set;
	if (size < 3 ) {
		return set;
	}
	sort(nums.begin(), nums.end());
	for ( int i = 0 ; i < size  ; i++) {
		int a = nums.at(i);
		int k = size - 1;
		if ( i > 0 && nums.at(i) == nums.at(i - 1)) {
			continue;
		}
		if ((a > 0) || (size < 5 & set.size() == 1)) {
			break;
		}
		int j = i + 1;
		while (j < k) {
			int b = nums.at(j);
			int c = nums.at(k);
			int sum = a + b + c;
			if (size < 5 & set.size() == 1) {
				break;
			}
			if (sum > 0) {
				k--;
			} else if (sum < 0) {
				j++;
			} else {
				vector<int> group;
				group.insert(group.end(), {a, b, c});
				set.push_back(group);
				j++;
				while ( nums.at(j) == nums.at(j - 1) && j < k) {
					j++;
				}
			}
		}

	}
	return set;
}

int main() {
	vector<int> nums = { -1, 0, 1, 2, -1, -4}; // [-4,-1,-1,0,1,2]
	vector<vector<int>> sum = threeSum(nums);
	cout << "[";
	for (int i = 0 ; i < sum.size(); i++) {
		cout << " [";
		for (int j = 0 ; j < sum.at(i).size(); j++) {
			cout << sum.at(i).at(j) << ",";
		}
		cout << "]";
	}
	cout << " ]";
}