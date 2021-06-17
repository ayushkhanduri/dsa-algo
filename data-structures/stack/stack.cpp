#include "iostream"
#include "vector"
#include "stack.hpp"

using namespace std;

void Stack:: push(int item) {
	SinglyLL *newItem = new SinglyLL(item);
	if (top == nullptr && length == 0) {
		top = newItem;
	} else {
		newItem ->next = top;
		top = newItem;
	}
	length++;

}

void Stack:: pop() {
	if (top == nullptr && length == 0) {
		cout << "Can not pop item as stack is already empty";
		return;
	}
	SinglyLL *topCopy = top;
	top = top -> next;
	delete topCopy;
	length--;
}

void Stack:: traverse() {
	SinglyLL *topCopy = top;
	while (topCopy != nullptr) {
		cout << topCopy -> value << endl;
		topCopy = topCopy -> next;
	}
}

bool Stack:: isEmpty() {
	return length == 0 ;
}

int Stack::size() {
	return length;
}

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(100);
	s.pop();
	s.traverse();
	cout << s.size() << endl;
}