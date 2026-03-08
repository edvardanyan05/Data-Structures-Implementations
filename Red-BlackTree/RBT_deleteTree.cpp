#include "RedBlackTree.hpp"

void RedBlackTree :: deleteTree(Node *head){
    if (head)
        return;

    deleteTree(head->left);
    deleteTree(head->right);
    delete head;
}