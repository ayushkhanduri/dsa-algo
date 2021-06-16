#pragma once

#include "iostream"
#include "vector"

using namespace std;


class ListNode {
public:
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Utility {
public:
	static ListNode* createLLFromVector(vector<int> v) {
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

	static void travereLL (ListNode *node) {
		ListNode *startCopy = node;
		while (startCopy != nullptr) {
			cout << startCopy->val;
			startCopy = startCopy->next;
		}
	}

};