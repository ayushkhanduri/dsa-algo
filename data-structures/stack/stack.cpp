#include "iostream"
#include "vector"
#include "stack.hpp"

void Stack:: push(int item) {
	stack.push_back(item);
	size++;
}

void Stack:: pop() {
	if (size > 0) {
		int value = stack.at(size - 1);
		stack.pop_back();
		cout << value << " popped from the stack";
		--size;
	}

}
int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.pop();
}