//https://leetcode.com/problems/merge-k-sorted-lists/

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void travereLL (ListNode *node) {
	ListNode *startCopy = node;
	while (startCopy != nullptr) {
		cout << startCopy->val;
		startCopy = startCopy->next;
	}
}
ListNode* createLLFromVector(vector<int> v) {
	int size = v.size();
	if (!size) {
		ListNode* start = nullptr;
		return start;
	}
	ListNode* start =  new ListNode(v.at(0));
	ListNode* startCopy = start;
	for (int i = 1 ; i < v.size() ; i++) {
		ListNode* newNode = new ListNode(v.at(i));
		startCopy -> next = newNode;
		startCopy = startCopy -> next;

	}
	return start;
}


// brute force also got accepted
ListNode* mergeKListsBruteForce(vector<ListNode*>& lists) {
	int size = lists.size();
	vector<int> wholeArr;
	for (int i = 0 ; i < size ; i++) {
		ListNode* list = lists.at(i);
		while (list != nullptr) {
			wholeArr.push_back(list->val);
			list = list->next;
		}
	}
	sort(wholeArr.begin(), wholeArr.end());
	return createLLFromVector(wholeArr);
}

int main() {
	vector<int> v1 = {1, 4, 5};
	vector<int> v2 = {1, 3, 4};
	vector<int> v3 = {2, 6};
	vector<ListNode*> listOfLL = {createLLFromVector(v1), createLLFromVector(v2)};
	ListNode* l = mergeKListsBruteForce(listOfLL);
	travereLL(l);
}