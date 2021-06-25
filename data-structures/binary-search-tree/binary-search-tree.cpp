#include "iostream"
#include "binary-search-tree.hpp"

using namespace std;


Tree* BinaryTree:: findClosestNode(int value, Tree *currentNode) {
	static int counter = 0;
	counter++;
	if (counter > 200) {
		exit(0);
	}
	if (currentNode -> right == nullptr && currentNode -> left == nullptr ) {
		return currentNode;
	} else {
		Tree *nextRightNode = currentNode -> right;
		Tree *nextLeftNode = currentNode -> left;
		if (currentNode-> value == value) {
			return currentNode;
		} else if (currentNode -> value > value) {
			if (nextLeftNode == nullptr) {
				return currentNode;
			} else if (nextLeftNode -> value < value) {
				return currentNode;
			} else {
				return findClosestNode(value, nextRightNode);
			}
		} else if (currentNode -> value < value) {
			if (nextRightNode == nullptr) {
				return currentNode;
			} else if (nextRightNode -> value > value) {
				return currentNode;
			} else {
				return findClosestNode(value, nextRightNode);
			}
		}
		return currentNode;
	}
}
void BinaryTree:: add(int value) {
	Tree* newNode = new Tree(value);
	if (rootNode == nullptr) {
		rootNode = newNode;
	} else {
		Tree* rootNodeCopy = rootNode;
		Tree* positionForNewNode = findClosestNode(value, rootNodeCopy);
		if (!(positionForNewNode -> right == nullptr && positionForNewNode -> left == nullptr)) {
			if (value >= positionForNewNode-> value) {
				Tree* tempRightNode = positionForNewNode->right;
				positionForNewNode -> right = newNode;

			} else if (value >= positionForNewNode-> value) {
				positionForNewNode -> left = newNode;
			}
		}
		if (positionForNewNode -> right == nullptr && positionForNewNode -> left == nullptr) {
			if (value >= positionForNewNode-> value) {
				positionForNewNode -> right = newNode;
			} else {
				positionForNewNode -> left = newNode;
			}
		} else {

		}
	}
}

int main() {

}