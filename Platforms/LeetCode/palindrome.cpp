//https://leetcode.com/problems/palindrome-number/
#include"iostream"
using namespace std;

bool isPalidrome(int x) {
    int xCopy = abs(x);
    bool isPalidrome = false;
    if ( xCopy != x ) {
        return isPalidrome;
    }
    int palNumber = 0;
    while (xCopy != 0) {
        int mod = xCopy % 10;
        if (!((INT_MAX / (float)palNumber ) >= 10 && (INT_MAX - (palNumber * 10) > mod)) ) {
            break;
        }
        palNumber = (palNumber * 10) + mod;
        xCopy = xCopy / 10;
    }
    isPalidrome = x == palNumber;
    return isPalidrome;
}

int main() {
    int x;
    cin >> x;
    cout << isPalidrome(x);
}
