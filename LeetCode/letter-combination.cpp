#include "iostream"
#include "vector"
#include "unordered_map"
#include "string"

using namespace std;


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
	if (size == 1) {
		string singleString = map.at(digits.at(0));
		int singleStringSize = singleString.size();
		for (int i = 0; i < singleStringSize ; i++) {
			string str = string(1, singleString.at(i));
			v.push_back(str);
		}
	} else {
		vector<string> collection;
		int collection_size = 0;
		for (int i = 0 ; i < size ; i++) {
			collection.push_back(map.at(i));
			arr.push_back(0);
			size++;
			for (int j = 0; j < size  ; j++) {
				for (int k = size - 1 ; k <= 0 ; k++) {
					for (int l = 0 ; l < collection.at(k).size(); l++) {
						// string st =
					}
				}
			}
		}
	}

	return v;
}

int main() {
	string digits = "2";
	vector<string> s = letterCombinations(digits);
	for (string str : s) {
		cout << str << endl;
	}
}