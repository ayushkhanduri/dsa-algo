//https://leetcode.com/problems/zigzag-conversion/
#include "iostream"
#include "string"

using namespace std;


string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    string newConverted = "";
    int size = s.size();
    bool downwards = true;
    string arr[numRows];
    int row = 0;
    for (int i = 0; i < size ; i++) {
        arr[row] += s.at(i);
        if (downwards) {
            ++row;
            if (row == (numRows - 1)) {
                downwards = false;
            }
        } else {
            --row;
            if (row == 0) {
                downwards = true;
            }
        }
    }

    for ( int i = 0 ; i < numRows; i++ ) {
        newConverted += arr[i];
    }

    return newConverted;
}

int main() {
    cout << endl << endl << convert("PAYPALISHIRING", 3);
}

