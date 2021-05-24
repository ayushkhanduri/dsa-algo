//https://leetcode.com/problems/valid-parentheses/submissions/ -> good job 100% faster

#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

bool isValid(string s) {
	int size = s.size();
	bool isParenthesisValid = true;
	vector<char> v;
	unordered_map<char, char> umap  = {
		{ '}', '{' },
		{ ']', '[' },
		{ ')', '(' },
		{ '{', '\0'},
		{ '(', '\0'},
		{ '[', '\0'}
	};
	int j = 0;
	for (int i = 0 ; i < size ; i++) {
		char ch = s.at(i);
		char counterPart = umap.at(ch);
		if ( counterPart != '\0') {
			if (v.size() == 0) {
				isParenthesisValid = false;
				break;
			} else {
				if (v.at(j - 1) != counterPart) {
					isParenthesisValid = false;
					break;
				} else {
					v.pop_back();
					j--;
				}
			}
		} else {
			v.push_back(ch);
			j++;
		}
	}

	return isParenthesisValid && (v.size() == 0);
}
int main() {

	cout << isValid("(){}}{");

}