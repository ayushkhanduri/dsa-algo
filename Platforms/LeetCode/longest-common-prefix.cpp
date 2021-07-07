//https://leetcode.com/problems/longest-common-prefix/

#include "iostream"
#include "vector"

#define ALPHABET_SIZE 26

using namespace std;


string longestCommonPrefix(vector<string>& strs) {
	int size = strs.size() ;
	string s = "";
	int arr[200] = {0} ;
	if (size == 1) {
		return strs[0];
	}
	for (int i = 1 ; i < size; i++ ) {
		int previous_size = strs[i - 1].size();
		int selected_string_size = strs[i].size();
		int real_size = previous_size < selected_string_size ? previous_size : selected_string_size;
		for (int j = 0; j < real_size; j++) {
			if (strs[i - 1][j] == strs[i][j]) {
				++arr[j];
				if (arr[j] == (size - 1)) {
					s += strs[i][j];
				}
			} else {
				break;
			}
		}
	}
	return s;
}


int main() {
	vector<string> list{"a"};
	cout << longestCommonPrefix(list);
}