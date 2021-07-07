//https://leetcode.com/problems/generate-parentheses/
#include "iostream"
#include "string"
#include "vector"

using namespace std;

bool valid(string arr) {
	int balance = 0;
	bool isValid = true;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == '(')
			balance++;
		else
			balance--;
		if (balance < 0) {
			isValid = false;
			break;
		}
	}
	if (isValid) {
		isValid = balance == 0;
	}
	return isValid;
}

void generateAll(string s, int position, int size, vector<string> &v) {
	if (position == size) {
		if (valid(s)) {
			string str(s);
			v.push_back(str);
		}
	} else {
		s += '(';
		generateAll(s, position + 1, size, v);
		s[position] = ')';
		generateAll(s, position + 1, size, v);
	}
}

vector<string> generateParenthesisBruteForce(int n) {
	vector<string> v;
	string str;
	int charLength = n * 2;
	// char s[charLength];
	generateAll(str, 0, charLength, v);
	return v;
}




int main() {

	vector<string> str = generateParenthesisBruteForce(3);
	cout << "Printing result" << endl << endl;
	for (string s : str) {
		cout << s << endl;
	}
}