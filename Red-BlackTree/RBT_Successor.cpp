#include "RedBlackTree.hpp"

Node* RedBlackTree :: successor(int val){
    Node* current = searching(head, val);
    if (!current)
        return nullptr;

    Node* successor = nullptr;
    if(current->right){
        successor = current->right;
        while(successor->left)
            successor = successor->left;
        return successor;
    }

    successor = current->parent;
    while(successor && current == successor->right){
        current = successor;
        successor = successor->parent;
    }
    return successor;
}