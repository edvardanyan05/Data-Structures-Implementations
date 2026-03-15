#include "RedBlackTree.hpp"

Node* RedBlackTree :: minVal(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->left)
        it = it->left;
    return it;
}

Node* RedBlackTree :: maxVal(){
    if (head == nullptr)
        return nullptr;

    Node *it = head;
    while(it->right)
        it = it->right;
    return it;
}
