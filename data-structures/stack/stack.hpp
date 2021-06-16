#pragma once

#include "iostream"
#include "vector"

using namespace std;
// can be implemented using linked list or dynamic array but would be an overkill
class Stack {
private:
	vector<int> stack;
	int size = 0;
public:
	void push(int item);
	void pop();
};