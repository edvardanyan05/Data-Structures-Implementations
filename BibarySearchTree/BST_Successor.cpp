#include "BinarySearchTree.hpp"

Node* BinaryTree :: successor(int val){
    if (!head)
        return nullptr;

    Node *parent = nullptr;
    Node *current = head;
    while (current && current->value != val) {
        parent = current;
        if (val < current->value)
            current = current->left;
        else
            current = current->right;
    }
    if (!current)
        return nullptr;

    Node* successor = nullptr;
    if (current->right){
        successor = current->right;
        while(successor->left)
            successor = successor->left;
        return successor;
    }
    Node* ancestor = head;

    while (ancestor != current) {
        if (current->value < ancestor->value) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    return successor;
}