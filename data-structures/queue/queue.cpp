#include "iostream"
#include "queue.hpp"

using namespace std;

void Queue::enqueue(int value) {
	if (front == nullptr && length == 0) {
		front = new SinglyLL(value);
		back = front;
	} else {
		SinglyLL *newItem = new SinglyLL(value);
		back->next = newItem;
		back = newItem;
	}
	length++;
}


void Queue::dequeue() {
	if (front == nullptr && length == 0) {
		cout << "Can not dequeue, queue is empty" << endl;
		return;
	}
	SinglyLL *frontCopy = front;
	front = front-> next;

	if (front == nullptr) {
		back = nullptr;
	}
	delete frontCopy;
	length--;
}

int Queue::peeking() {
	return front->value;
}

int Queue:: size() {
	return length;
}

void Queue:: traverse() {
	SinglyLL *frontCopy = front;
	while (frontCopy != nullptr) {
		cout << frontCopy->value << endl;
		frontCopy = frontCopy -> next;
	}
}

int Queue:: indexOf(int element) {
	int position = 1;
	bool found = false;
	SinglyLL *frontCopy = front;
	while (frontCopy != nullptr ) {
		if (frontCopy->value == element) {
			found = true;
			break;
		}
		frontCopy = frontCopy-> next;
		position++;
	}
	if (!found)
		position = -1;
	return position;
}

int main() {
	Queue queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(50);
	queue.dequeue();
	queue.enqueue(5);
	queue.enqueue(39);
	queue.dequeue();
	cout << queue.indexOf(39);
	// queue.traverse();
}