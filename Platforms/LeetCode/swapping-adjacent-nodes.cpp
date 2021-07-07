//https://leetcode.com/problems/swap-nodes-in-pairs/
#include "iostream"
#include "./utils/LeetCode.hpp"

using namespace std;



ListNode* swapPairs(ListNode* head) {
	vector<ListNode*> nodeList;
	int index = 0;
	while (head != nullptr) {
		int vectorIndex = (index ) / 2;
		ListNode* newNode = new ListNode(head ->val);
		if (index % 2 == 0) {
			nodeList.push_back( newNode);
		} else {
			ListNode *nodeAtPos = nodeList.at(vectorIndex);
			newNode->next = nodeAtPos;
			nodeList.at(vectorIndex) = newNode;
		}
		head = head -> next;
		index++;
	}

	ListNode *node = nullptr ;
	if (nodeList.size() == 0) {
		return node;
	}
	for (ListNode *nodeItem : nodeList ) {
		if (node == nullptr) {
			node = nodeItem;
		} else {
			node ->next = nodeItem;
		}
		while (node ->next != nullptr) {
			node = node -> next;
		}
	}
	return nodeList.at(0);
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	ListNode *head = Utility::createLLFromVector(v);
	ListNode *swapped = swapPairs(head);
	Utility::travereLL(swapped);
}