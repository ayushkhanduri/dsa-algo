//https://leetcode.com/problems/divide-two-integers/

#include "iostream"

using namespace std;


int divide(int dividend, int divisor) {
	double dividendCopy = (double)abs(dividend);
	double divisorCopy = (double)abs(divisor);
	int sign = 1, quotient = 0, tempDecrementor = divisor;
	if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) {
		sign = -1;
	}
	while (dividendCopy >= divisorCopy) {
		quotient++;
		dividendCopy = dividendCopy - divisorCopy;
	}

	if (sign == -1) {
		return -quotient;
	}
	return quotient;
}
// int divide(int dividend, int divisor) {
// 	int dividendCopy = dividend, sign = 1, temp = 1, divisorCopy = divisor, quotient = 0;
// 	if (divisor == 1 || divisor == -1 ) {
// 		int answer = dividend;
// 		if (dividend == INT_MIN && divisor == -1) {
// 			return INT_MAX;
// 		}
// 		if (divisor == -1) {
// 			return -(answer);
// 		}

// 		return answer;
// 	}
// 	if (dividendCopy < 0 ) {
// 		sign = -(sign);
// 	}
// 	if (divisor < 0) {
// 		sign = -(sign);
// 	}

// 	if (dividendCopy == INT_MIN) {
// 		quotient++;
// 		dividendCopy = dividendCopy - (sign) * (divisorCopy);
// 	}

// 	int counter = 0 ;

// 	while (dividendCopy >= divisor) {
// 		if (counter > 100) {
// 			exit(0);
// 		}
// 		counter++;
// 		quotient = quotient + temp;
// 		dividendCopy = dividendCopy - (sign) * (divisor);
// 		divisor += divisor;
// 		temp = temp + temp;
// 	}
// 	if (sign == -1) {
// 		return -(quotient);
// 	}
// 	return quotient;
// }
int main() {
	int quotient = divide(-10, 5);
	cout << quotient;
}