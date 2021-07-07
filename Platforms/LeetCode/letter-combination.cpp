//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include "iostream"
#include "vector"
#include "unordered_map"
#include "string"

using namespace std;


void backtracking(int i,  string str, string digits , unordered_map<char, string> &map, vector<string> &v) {
	if (str.size() == digits.size()) {
		v.push_back(str);
		return;
	}

	for (char c : map.at(digits.at(i))) {
		backtracking(i + 1, str + c, digits, map, v);
	}
}

vector<string> letterCombinations(string digits) {
	vector<string> v;
	unordered_map<char, string> map = {
		{ '2', "abc" },
		{ '3', "def"},
		{ '4', "ghi"},
		{ '5', "jkl"},
		{ '6', "mno"},
		{ '7', "pqrs"},
		{ '8', "tuv"},
		{ '9', "wxyz"}
	};
	int size = digits.size();
	vector<int> arr;
	if (size == 0) {
		return v;
	}
	if (size == 1) {
		string singleString = map.at(digits.at(0));
		int singleStringSize = singleString.size();
		for (int i = 0; i < singleStringSize ; i++) {
			string str = string(1, singleString.at(i));
			v.push_back(str);
		}
	} else {
		backtracking(0, "", digits, map, v);
	}
	return v;
}

int main() {
	string digits = "2345";
	vector<string> s = letterCombinations(digits);
	cout << endl << endl;
	for (string str : s) {
		cout << str << endl;
	}
}