#include "iostream"
#include <climits>
using namespace std;

int reverse(int x) {
    int xCopy = x;
    int reverseNum = 0;
    if(x == INT_MAX) {
        return reverseNum;
    }
    while(xCopy != 0) {
        int mod = xCopy % 10;
         if (reverseNum > INT_MAX/10 || reverseNum < INT_MIN/10) {
            reverseNum = 0;
            break;
        }
        reverseNum = reverseNum * 10 + mod;
        cout << reverseNum << endl;
        xCopy = xCopy/10;
    }
    return reverseNum;
}

int main() {
    int x;
    cin >> x;
    cout << reverse(x);
}
