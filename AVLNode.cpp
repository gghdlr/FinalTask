#include "AVLNode.h"
#include <iostream>
using namespace std;
AVLNode::AVLNode(int value) : Node(value){}
void AVLNode::print() {}

void AVLNode::updateValues() {
    auto leftCount = 0;
    auto leftHeight = 0;
    if (left != nullptr) {
        leftHeight = left->height;
    }
    auto rightCount = 0;
    auto rightHeight = 0;
    if (right != nullptr) {
        rightHeight = right->height;
    }
    height = max(leftHeight, rightHeight) + 1;
}
//балансировка
int AVLNode::balanceFunction() {
    auto leftHeight = left != nullptr ? left->height : 0;
    auto rightHeight = right != nullptr ? right->height : 0;
    return leftHeight - rightHeight;
}
// правый поворт
AVLNode* AVLNode::rightRotate() {
    AVLNode* leftTmp = left;
    left = left->right;
    leftTmp->right = this;
    this->updateValues();
    leftTmp->updateValues();
    return leftTmp;
}
//левый поворот
AVLNode* AVLNode::leftRotate() {
    AVLNode* rightTmp = right;
    right = right->left;
    rightTmp->left = this;
    this->updateValues();
    rightTmp->updateValues();
    return rightTmp;
}
