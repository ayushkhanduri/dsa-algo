//https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-operations-2-8000e855/

#include "iostream"
#include "vector"

using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	int i = 0;
	vector<vector<int>> groupedItem;
	while (i < n ) {
		int current = arr[i], j = i + 1;
		vector<int> collection;
		collection.push_back(current);
		while (j < n && arr[j] == current) {
			collection.push_back(arr[j]);
			j++;
		}
		groupedItem.push_back(collection);
		i = j;
	}
	cout << groupedItem.size();

	// cout << groupedItem.size() << endl;
	// for (vector<int> item : groupedItem) {
	// 	for (int x : item) {
	// 		cout << x << ",";
	// 	}

}