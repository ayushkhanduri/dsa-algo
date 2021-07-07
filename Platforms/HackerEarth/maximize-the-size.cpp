//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-sum-0423b95e/

#include "iostream"
#include "unordered_map"
using namespace std;

int main() {
	int n, t;
	cin >> t;
	for (int i = 0 ; i < t ; i++) {
		int k ;
		cin >> n;
		cin >> k;
		int arr[n];
		unordered_map<int, int> traversedItems;
		for (int j = 0; j < n ; j++) {
			cin >> arr[j];
			if (traversedItems.find(arr[j]) == traversedItems.end()) {
				traversedItems.insert({ arr[j], 1 });
			} else {
				int count = ++traversedItems.at(arr[j]);
				traversedItems.insert({ arr[j], count });
			}
		}
		int largestIndex = 0 , sum = 0, previousLargest = arr[0], sortedArrIndex = 0 ;
		while (sortedArrIndex < k) {
			int largest = arr[0];
			for (int j = 0; j < n ; j++) {
				if (arr[j] > largest) {
					if (sortedArrIndex > 0) {
						if (previousLargest != arr[j]) {
							largest = arr[j];
							largestIndex = j;
						} else {
							arr[j] = INT8_MIN;
						}
					} else {
						largest = arr[j];
						largestIndex = j;
					}
				}
			}
			// if ( traversedItems.find(largest) != traversedItems.end() ) {
			cout << "largest : " << largest << ", count: " << traversedItems.at(largest) << endl;
			sum += traversedItems.at(largest) * largest;
			previousLargest = largest;
			arr[largestIndex] = INT32_MIN;
			sortedArrIndex++;
			// } else {
			// cout << "Gadbad bc: " << largest << endl;
			// }

		}
		cout << sum << endl;
	}

}