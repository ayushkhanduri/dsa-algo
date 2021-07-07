#include "iostream"
#include "priority-queue.hpp"

using namespace std;

Tree* PriorityQueue:: getInsertionPosition(int value, Tree *heapPosition) {
	if (heapPosition && heapPosition -> value < value) {
		return heapPosition;
	}

	if (heapPosition == nullptr) {
		return nullptr;
	} else {
		//moveLeft
		Tree *leftPosition = getInsertionPosition(value, heapPosition -> left);
		Tree *rightPosition = getInsertionPosition(value, heapPosition -> right);

	}
}

void PriorityQueue::add(int value) {
	if (rootHeap == nullptr) {
		rootHeap = new Tree(value);
	} else {

	}
}
int main() {

}