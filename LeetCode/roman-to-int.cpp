//https://leetcode.com/problems/roman-to-integer/

#include "iostream"
#include "unordered_map"
#include "string"

using namespace std;

int romanToInt(string s) {
	int number = 0, size = s.size();
	unordered_map<char, int> umap = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	for ( int i = 0; i < size  ; i++ ) {
		bool atLast = ((size - i) == 1);
		int currentValue = umap.at(s.at(i));

		if ( !atLast ) {
			int nextValue = umap.at(s.at(i + 1));
			if (nextValue > currentValue) {
				number += nextValue - currentValue;
				i++;
				continue;
			}
		}

		number += currentValue;
	}
	return number;
}

int main() {
	cout << romanToInt("IV");
}