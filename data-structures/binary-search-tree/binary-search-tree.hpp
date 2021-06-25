#pragma once


class Tree {
public:
	Tree(int newValue): value(newValue), left(nullptr), right(nullptr) {};
	Tree(int newValue, Tree *leftPtr ): value(newValue), left(leftPtr) {};
	Tree(int newValue, Tree *leftPtr, Tree *rightPtr): value(newValue), left(leftPtr), right(rightPtr) {};
	int value;
	Tree *left;
	Tree *right;
};

class BinaryTree {
private:
	Tree *rootNode = nullptr;
	Tree *findClosestNode(int value, Tree *currentNode );

public:
	void add(int value);
	void remove(int value);
};