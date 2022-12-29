#include "AVLTree.h"
using namespace std;
AVLTree::AVLTree() {
}
AVLTree::~AVLTree() {
    //clear();
}
//поиск одинаковых элементов
AVLNode* AVLTree::find(int value) const { 
    auto fNode = root;
    while (fNode != nullptr && fNode->value != value) {
        if (fNode->value < value) {
            fNode = fNode->right;
        }
        else {
            fNode = fNode->left;
        }
    }
    return fNode;
}
//вставка элементов
void AVLTree::insert(int value) {
    auto newNode = &root;
    vector<AVLNode**> disbalance;

    while (*newNode != nullptr) {
        disbalance.push_back(newNode);

        if (value > (*newNode)->value) {
            newNode = &((*newNode)->right);
        }
        else {
            newNode = &((*newNode)->left);
        }
    }
    *newNode = new AVLNode(value);
    disbalance.push_back(newNode);
    balance(disbalance);
    size++;
}

void AVLTree::erase(int value) {
    auto del = &root;
    vector<AVLNode**> disbalance;
    while (*del != nullptr && (*del)->value != value) {
        disbalance.push_back(del);

        if ((*del)->value > value) {
            del = &((*del)->left);
        }
        else {
            del = &((*del)->right);
        }
    }
    if (*del == nullptr) {
        return;
    }
    if ((*del)->left == nullptr && (*del)->right == nullptr) {
        delete* del;
        *del = nullptr;
    }
    else if ((*del)->right == nullptr) {
        auto badValue = *del;
        (*del) = (*del)->left;
        delete badValue;
    }
    else {
        disbalance.push_back(del);
        auto delIndex = disbalance.size();
        auto RightChild = &((*del)->right);
        while ((*RightChild)->left != nullptr) {
            disbalance.push_back(RightChild);
            RightChild = &((*RightChild)->left);
        }
        if (*RightChild != (*del)->right) {
            auto erasingRightChild = *disbalance.back(), erasingRight = *RightChild;
            erasingRightChild->left = (*RightChild)->right;
            erasingRightChild->left = (*del)->left;
            erasingRightChild->right = (*del)->right;

            delete* del;
            *del = erasingRightChild;
            disbalance[delIndex] = &(erasingRightChild->right);
        }
        else {
            (*RightChild)->left = (*del)->left;
            auto remov = *del;
            *del = *RightChild;
            delete remov;
        }
    }
    balance(disbalance);
    size--;
}

void AVLTree::balance(vector<AVLNode**> path) { //балансировка узла
    for (auto node : path) {
        (*node)->updateValues();
        // left - left
        if ((*node)->balanceFunction() >= 2 && (*node)->left->balanceFunction() >= 1) {
            *node = (*node)->rightRotate();
        }
        // left - right
        else if ((*node)->balanceFunction() >= 2) {
            (*node)->left = (*node)->left->leftRotate();
            *node = (*node)->rightRotate();
        }
        // right - right
        else if ((*node)->balanceFunction() <= -2 && (*node)->right->balanceFunction() <= -1) {
            *node = (*node)->leftRotate();
        }
        // right - left
        else if ((*node)->balanceFunction() <= -2) {
            (*node)->right = ((*node)->right)->rightRotate();
            *node = (*node)->leftRotate();
        }
    }
}

void AVLTree::print() {
    if (root != nullptr) {
        print(root);
    }
    else {
        cout << "Пусто";
    }
}
// отобразить дерево
void AVLTree::print(AVLNode* node, int depth, int state) {
    if (node->right) {
        print(node->right, depth + 1, 2);
    }

    for (int i = 0; i < depth; i++) {
        cout << "     ";
    }
    cout << "-----";
    cout << node->value << endl;

    if (node->left) {
        print(node->left, depth + 1, 1);
    }
}
//сбалансированный порядок
void AVLTree::printBalanced() {
   vector<AVLNode*> order;
    order.push_back(root);
    for (int i = 0; i < size; i++) {
        if (order[i]->left != nullptr) {
            order.push_back(order[i]->left);
        }
        if (order[i]->right != nullptr) {
            order.push_back(order[i]->right);
        }
    }

    for (auto node : order) {
        cout << node->value << " ";
    }
}