//https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include <string.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int strLength = s.length(), longestSubstringLength = 0 , startingPoint = 0 ;
	while(startingPoint  < strLength ) {
		int localLongest = 1;
		int arr[255] = {0};
		int pos = int(s[startingPoint]);
		arr[pos] = 1;
		for(int j = 0 ; j< strLength ; j++) {
			int position = int(s[j]) ;
			int doesArrayContain = arr[position];
			if (doesArrayContain == 1) {
				break;
			}else {
				arr[position] = 1;
				localLongest = localLongest + 1;
			}
		}
		if(localLongest > longestSubstringLength) {
			longestSubstringLength = localLongest;
		}
		startingPoint++;
	}
	return longestSubstringLength;
}

int main() {
	int longest = lengthOfLongestSubstring("abcad");
  std::cout << longest;
}
