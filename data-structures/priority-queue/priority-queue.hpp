#pragma once

#include "iostream"


class Tree {
public:
	Tree(int newValue): value(newValue), left(nullptr), right(nullptr) {};
	Tree(int newValue, Tree *leftPtr ): value(newValue), left(leftPtr) {};
	Tree(int newValue, Tree *leftPtr, Tree *rightPtr): value(newValue), left(leftPtr), right(rightPtr) {};
	int value;
	Tree *left;
	Tree *right;
};

/**
 *	BINARY HEAP
 *
 * Construction: n
 * Polling: nlogn
 * Peeking: 1
 * Adding: logn
 * Removing: n
 * Advanced removing with the help of hashtable: nlogn
 * contains: n
 * contains with the help of hashtable: 1
*/
class PriorityQueue {
private:
	Tree *rootHeap = nullptr;
	Tree* getInsertionPosition(int value, Tree *heapPosition);
public:
	bool isEmpty();
	//O(1)
	void add(int value);
	//O(1)
	int peeking();
	//O(1)
	int size();
	//O(1) element with the highest priority gets removed first
	void pool();
	//O(n)
	int indexOf(int element);
	//just for testing
	void traverse();
};