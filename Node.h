#pragma once
class Node {
public:
	const int value = -1;
	Node(int value);
	Node* left;
	Node* right;
public:
	virtual void print() = 0; 
	virtual void updateValues() = 0;
};

