//https://leetcode.com/problems/add-two-numbers/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next = NULL;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;
	bool firstCount = true; 
	ListNode *sumList = new ListNode(0);
	ListNode *sumListCopy = sumList;
	while(l1 != NULL || l2 != NULL) {
		int v1 = l1 != NULL ? l1->val : 0  , v2 = l2 != NULL ? l2->val : 0 ;
		int sum = v1 + v2 + carry;
		int singleDigit = sum % 10;
		if(firstCount) {
			sumListCopy->val = singleDigit;
		}else {
			ListNode *newItem = new ListNode(singleDigit);
			newItem -> next = NULL;
			sumListCopy -> next = newItem;
			sumListCopy = sumListCopy -> next;
		}
		carry = (sum/10) % 10;
		if(l1) {
			l1 = l1->next;
		}
		if(l2) {
			l2 = l2->next;
		}
		firstCount = false;
	}
	if(carry != 0){
		ListNode *carryNode = new ListNode(carry);
		sumListCopy-> next = carryNode;
	}
	return sumList;
}

int getNumberPlaces(int num) {
	int base = 10, numCopy = num;
	while(numCopy != 0) {
		numCopy = numCopy/base;
		base *= 10;
	}
	return base/10;
}
ListNode* createLinkLinkFromNumber(int number) {
	ListNode *l1 = new ListNode(0);
	ListNode *l1Copy = l1;
	int numberCopy = number;
	int places = getNumberPlaces(number);
	while(places != 0){
		int val = (numberCopy/places) % 10;
		if(l1->val == 0){
			l1->val = val;
		}else{
			ListNode *l2 = new ListNode(0);
			l1 -> next = l2;
			l2 -> val = val;
			l1 = l1 -> next;
		}
		places = places / 10;
	}
	return l1Copy;
}



void iterateLinkedList(ListNode* l) {
	ListNode* linkCopy = l;
	while(linkCopy != NULL) {
		cout << linkCopy -> val;
		linkCopy = linkCopy -> next;
	}
};

int main() {
	ListNode *l1 = createLinkLinkFromNumber(243);
	ListNode *l2 = createLinkLinkFromNumber(564);
	ListNode *sumPointer = addTwoNumbers(l1, l2);
	iterateLinkedList(sumPointer);
}
