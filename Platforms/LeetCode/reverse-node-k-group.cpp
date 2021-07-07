//https://leetcode.com/problems/reverse-nodes-in-k-group/

#include "iostream"
#include "vector"
#include "./utils/LeetCode.hpp"

using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
	int i = 0;
	vector<int> cachedItems;
	ListNode *start = nullptr, *startCopy = nullptr, *partialLL = nullptr;
	while (head != nullptr) {
		i++;
		ListNode *newItem = new ListNode(head ->val);
		cachedItems.push_back(head->val);
		newItem -> next = partialLL;
		partialLL = newItem;
		if ( i % k == 0 ) {
			cachedItems.clear();
			if (start == nullptr) {
				start = partialLL;
				startCopy = start;
			} else {

				while (startCopy ->next != nullptr ) {
					startCopy = startCopy -> next;
				}
				startCopy -> next = partialLL;
			}
			partialLL = nullptr;
		}

		head = head -> next;
	}
	partialLL = nullptr;
	ListNode *copyLL = nullptr;
	for (int value : cachedItems) {
		ListNode *newItem = new ListNode(value);
		if (partialLL == nullptr ) {
			partialLL = newItem;
			copyLL = partialLL;
		} else {
			partialLL -> next = newItem;
			partialLL = partialLL-> next;
		}
	}

	while (startCopy ->next != nullptr ) {
		startCopy = startCopy -> next;
	}
	startCopy -> next = copyLL;
	return start;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	ListNode *start = Utility::createLLFromVector(v);
	ListNode *newLL = reverseKGroup(start, 1);

	Utility::travereLL(newLL);
}