#include "iostream"
#include <climits>

using namespace std;

int myAtoi(string s) {
    int number =0;
    int multiplier = 1;
    bool explicitMultiplier = false;
    for (char c: s) {
        if (c == ' ' && !explicitMultiplier) {
            continue;
        }
        if ( number == 0 && multiplier == 1 && !explicitMultiplier) {
            if (c == '-') {
                multiplier = -1;

                explicitMultiplier = true;
                number *= multiplier;
                continue;
            }

            if (c == '+') {
                explicitMultiplier = true;
                continue;
            }
        }

        int ascii = (int) c;
        if (ascii >= 48 && ascii <=57) {
            int charToNumber = c - '0';
            if ( number != 0 ) {
                if (multiplier == 1) {
                    if (!(( INT_MAX/number >= 10) && ((INT_MAX - (number * 10 )) > charToNumber))) {
                        number = INT_MAX;
                        break;
                    }
                } else {
                    if (!(( INT_MIN/(float)number >= 10) && ((INT_MIN - (number * 10 )) < -charToNumber))) {
                        number = INT_MIN;
                        break;
                    }
                }
            } 
            number = (number * 10) +  (multiplier * charToNumber);
            explicitMultiplier = true;
        } else {
            break;
        }
    }

    return number ;
}
int main() {
    string s;
    cin >> s;
    int result = myAtoi(s);
    cout << result;
}
