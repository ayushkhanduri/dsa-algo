//https://leetcode.com/problems/regular-expression-matching/

#include "iostream"
#include <string.h>

using namespace std;

bool isMatch(string s, string p) {
	int i = 0, patternSize = p.size();
	char prevChar;
	bool isMatching = true;
	while (i < patternSize) {
		if (p[i] == '.') {
			i++;
			continue;
		}


		prevChar = s[i];
	}
	return isMatching;
}

int main() {
	cout << isMatch("aa", "a*");
}