//https://leetcode.com/problems/merge-two-sorted-lists/

#define MIN_VALUE -101

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *newStart = nullptr, *startCopy = nullptr;
	while (l1 != nullptr || l2 != nullptr) {
		int value1 = -MIN_VALUE, value2 = -MIN_VALUE ;
		if (l1 != nullptr ) {
			value1 = l1->val;
		}
		if (l2 != nullptr) {
			value2 = l2-> val;
		}

		int value = 0;

		if (value1 < value2) {
			value = value1;
			l1 = l1->next;
		} else {
			value = value2;
			l2 = l2 -> next;
		}

		if (startCopy == nullptr) {
			newStart = new ListNode(value);
			startCopy = newStart;
		} else {
			ListNode* node = new ListNode(value);
			startCopy -> next = node;
			startCopy = startCopy -> next;
		}

	}
	return newStart;

}