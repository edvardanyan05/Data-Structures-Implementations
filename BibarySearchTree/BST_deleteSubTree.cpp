#include "BinaryTree.hpp"

void deleteSubTree(Node *head){
    if (!head)
        return;
    deleteSubTree(head->left);
    deleteSubTree(head->right);
    delete head;
}