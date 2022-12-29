#pragma once  
#include "Tree.h"
#include "AVLNode.h"
using namespace std;
class AVLTree : public Tree<AVLNode> {
public:
	AVLTree();
	~AVLTree();

public:
	AVLNode* find(int value) const override;
	void insert(int value) override;
	void erase(int value) override;
	void balance(vector<AVLNode**> disbalanced); //не сбалансированный
	void print() override;
	void print(AVLNode* node, int depth = 0, int state = 0);
public:
	void printBalanced(); //сбалансированный
};