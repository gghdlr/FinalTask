#pragma once
#include <vector> 
#include <iostream>
using namespace std;
template<class Node>
class Tree {
protected:
	int size;
	Node* root;
public:
	virtual Node* find(int value) const = 0;
	virtual void balance(vector<Node**> disbalanced) = 0;
	virtual void print() = 0;
	virtual void erase(int value) = 0;
	virtual void insert(int value) = 0;
};
