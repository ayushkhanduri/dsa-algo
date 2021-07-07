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


	static void swap_value(int from, int to, vector<int> &v) {
		int fromItem = v.at(from);
		v.at(from) = v.at(to);
		v.at(to) = fromItem;
	}

	static void print_vectors(vector<int> v) {
		cout << "[";
		for (int i = 0 ; i < v.size(); i ++ ) {
			cout << v.at(i);
			if (i != v.size() - 1) {
				cout << " , ";
			}
		}
		cout << "]" << endl;
	}

};