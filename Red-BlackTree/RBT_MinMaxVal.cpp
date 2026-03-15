#include "RedBlackTree.hpp"

Node* RedBlackTree :: minValNode(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->left)
        it = it->left;
    return it;
}

Node* RedBlackTree :: maxValNode(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->right)
        it = it->right;
    return it;
}
