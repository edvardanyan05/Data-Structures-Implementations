#include "BinarySearchTree.hpp"

Node* BinaryTree :: minVal(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->left)
        it = it->left;
    return it;
}

Node* BinaryTree :: maxVal(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->right)
        it = it->right;
    return it;
}