//https://leetcode.com/problems/implement-strstr/
// 100%
#include "iostream"
#include "string"

using namespace std;

int strStr(string haystack, string needle) {
	int hayStackSize = haystack.size(), needleSize = needle.size(), index = -1;
	if ( !needleSize ) {
		return 0;
	}
	for (int i = 0 ; i < hayStackSize ; i ++) {
		if (haystack.at(i) == needle.at(0) && (hayStackSize - i ) >= needleSize ) {
			int j = i , k = 0, matchingChars = 0;
			while (j < hayStackSize && k < needleSize) {
				if (haystack.at(j) == needle.at(k)) {
					j++;
					k++;
					matchingChars++;
				} else {
					break;
				}
			}
			if (matchingChars == needleSize) {
				index = i;
				break;
			}
		}
	}
	return index;
}
int main() {
	int position = strStr("hello", "o");
	cout << position;
}