#include "BinaryTree.hpp"

Node* BinaryTree :: searching(Node *head , int val){
    if (!head || head->value == val)
        return head;
    if (val > head->value)
        return searching(head->right, val);
    else
        return searching(head->left, val);
}