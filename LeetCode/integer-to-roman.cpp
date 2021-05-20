//https://leetcode.com/problems/integer-to-roman/

#include "iostream"
#include "string"
#include "unordered_map"

using namespace std;

string getValue(unordered_map<int, char>& umap, int value) {
	string s = "";
	try {
		s = umap.at(value);
	} catch (const out_of_range& oor ) {
		s = "";
	}
	return s;
}

int getBenchmarkIndex(int remainder) {
	if (remainder < 5) {
		return 1;
	} else if (remainder < 10) {
		return 2;
	} else if (remainder < 50) {
		return 3;
	} else if (remainder < 100) {
		return 4;
	} else if (remainder < 500) {
		return 5;
	} else if (remainder < 1000) {
		return 6;
	} else {
		return 7;
	}
}

string intToRoman(int num) {
	string roman = "";
	int milestones[] = { 1, 5, 10, 50, 100, 500, 1000, 1000} ;
	unordered_map<int, char> umap = {
		{ 1,	'I'},
		{ 5,	'V'},
		{ 10,	'X'},
		{ 50,	'L'},
		{ 100,	'C'},
		{ 500,	'D'},
		{ 1000,	'M'}
	};
	int copyNum = num, multiplier = 1 ;
	while (copyNum != 0) {
		int remainder = (copyNum % 10) * multiplier;
		multiplier *= 10;
		copyNum /= 10;
		if ( remainder == 0) {
			continue;
		}
		string s = getValue(umap, remainder);
		if (!s.empty()) {
			roman = s + roman;
			continue;
		}
		int benchmark_index = getBenchmarkIndex(remainder);
		int benchmark = milestones[benchmark_index];
		int difference = benchmark - remainder;
		s = getValue(umap, difference);
		if (!s.empty()) {
			roman = s + getValue(umap, benchmark) + roman;
			continue;
		} else {
			int remainderCopy = remainder;
			benchmark_index--;
			benchmark = milestones[benchmark_index];
			while (remainderCopy != 0) {
				benchmark_index = getBenchmarkIndex(remainderCopy);
				benchmark_index--;
				benchmark = milestones[benchmark_index];
				string charForBenchmark = getValue(umap, benchmark);
				s += charForBenchmark;
				remainderCopy -= benchmark;
			}
			roman = s + roman;
		}
	}
	return roman;
}

int main() {
	for (int i = 1; i <= 10 ; i++) {
		cout << intToRoman(i) << endl;
	}

}

// 910 = >  cmx