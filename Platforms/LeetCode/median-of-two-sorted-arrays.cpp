//https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <iostream>
#include <vector>

using namespace std; 

void debugVector (vector<int>& v1) {
	for (int x: v1) {
		cout << x;
	}
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	double median = 0;
	vector<int> accumulation;
	int num1Size = nums1.size(), num2Size = nums2.size(), num1Counter = 0 , num2Counter = 0;
	int accumulationSize = num1Size + num2Size;
	int largestValue = 0;
	if (num1Size != 0 && num2Size != 0) {
		largestValue = nums1.at(num1Size - 1) > nums2.at(num2Size - 1) ? nums1.at(num1Size - 1) + 1: nums2.at(num2Size - 1) + 1;
	} else if(num1Size == 0) {
		largestValue = nums2.at(num2Size -1);
	} else if(num2Size == 0) {
		largestValue = nums1.at(num1Size - 1);
	}
	while(num1Counter < num1Size || num2Counter < num2Size) {
		int num1Value = num1Counter < num1Size ? nums1.at(num1Counter) : largestValue; 
		int num2Value = num2Counter < num2Size ? nums2.at(num2Counter) : largestValue;
		if (num1Value > num2Value) {
			accumulation.push_back(num2Value);
			num2Counter++;
		} else if (num1Value < num2Value) {
			accumulation.push_back(num1Value);
			num1Counter++;
		} else if (num1Value == num2Value){
			accumulation.push_back(num1Value);
			accumulation.push_back(num2Value);
			num1Counter++;
			num2Counter++;
		}
	}
	// debugVector(accumulation);
 	int half = accumulationSize / 2;
	if((accumulationSize % 2) == 0) {
		median = (accumulation.at(half-1) + accumulation.at(half))/2.0;
	} else {
		median = accumulation.at(half);
	}
	return median;
}

int main() {
	vector<int> v1{};
	vector<int> v2{1};
	// findMedianSortedArrays(v1,v2);
	cout << findMedianSortedArrays(v1,v2);
}
