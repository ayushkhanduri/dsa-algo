#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"

using namespace std;

char getOpeningBraces(char ch) {
	char closing = '\0';
	unordered_map<char, char> umap = {
		{ '}' , '{'   },
		{ ']' , '['   },
		{ ')' , '('   }
	};
	try {
		closing = umap.at(ch);
	} catch (const out_of_range& oor) {

	}
	return closing;
}

bool balanceBraces(string str) {
	int size = str.size();
	int isBalanced = true;
	vector <char> bracesStack;
	for (int i = 0 ; i < size ; i++) {
		char openingBraces = getOpeningBraces(str.at(i));
		if (openingBraces == '\0') {
			bracesStack.push_back(str.at(i));
		} else {
			if (bracesStack.size() != 0) {
				char value = bracesStack.back();
				if (openingBraces == value) {
					bracesStack.pop_back();
				} else {
					isBalanced = false;
					break;
				}
			} else {
				isBalanced = false;
				break;
			}
		}
	}
	if (isBalanced && bracesStack.size() == 0) {
		isBalanced = true;
	} else {
		isBalanced = false;
	}
	return isBalanced;
}

int main() {
	cout << balanceBraces("[{})[]");
}