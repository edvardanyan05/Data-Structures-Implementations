#include "BinarySearchTree.hpp"

Node* BinaryTree :: minValNode(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->left)
        it = it->left;
    return it;
}

Node* BinaryTree :: maxValNode(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->right)
        it = it->right;
    return it;
}