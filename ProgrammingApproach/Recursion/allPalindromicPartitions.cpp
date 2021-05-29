//https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool isAPalidrome(string s, int starting, int ending ) {
	bool isPalindrome = true;
	while (starting < ending) {
		if (s.at(starting) != s.at(ending)) {
			isPalindrome = false;
			break;
		}
		starting++;
		ending--;
	}
	return isPalindrome;
}

void insertString(vector<string> &stringVector, string inputStr, int starting, int ending) {
	string str = "";
	int size = inputStr.size();
	for (int i = 0; i < size ; i++) {
		str += inputStr.at(i);
		if ( !(i >= starting && i < ending)) {
			str += " ";
		}
	}
	stringVector.push_back(str);
}

void allPalidromeRecursive(vector<string> &stringVector,  string input, int starting) {
	static int outcomes = 1;
	int size = input.size();
	if (starting == size - 1) {
		return ;
	}
	for (int i = starting + 1 ; i < size ; i++ ) {
		if (isAPalidrome(input, starting, i)) {
			insertString(stringVector, input, starting, i);
		}
	}
	allPalidromeRecursive(stringVector, input , starting + 1);
}

vector<string> allPalidromicPartitions (string input) {
	vector<string> v;
	int size = input.size();
	insertString(v, input, 0, 0);
	allPalidromeRecursive(v, input, 0);
	return v;
}

int main() {
	vector<string> v = allPalidromicPartitions("nitin");
	for (string s : v) {
		cout << s << endl;
	}
}