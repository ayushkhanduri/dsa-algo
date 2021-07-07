//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "iostream"

// Good job , 100% faster of the c++ submissions
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *headCopy = head;
	ListNode *tailCopy = head;
	ListNode *previous = head;
	int i = 0, actualIndex = -1;
	while (headCopy != nullptr) {
		i++;
		if (headCopy->next == nullptr) {
			tailCopy = headCopy;
			headCopy ->next = head;
			actualIndex = i - n ;
			i = 0;
		}
		previous = headCopy;
		headCopy = headCopy->next;
		if (actualIndex != -1 && i == actualIndex) {
			break;
		}
	}
	tailCopy -> next = nullptr;
	if (previous != tailCopy) {
		previous->next = headCopy->next;
	}
	if (actualIndex == 0) {
		head = head->next;
	}
	headCopy->next = nullptr;

	delete headCopy;
	headCopy = nullptr;
	return head;
}
int main( ) {

}