#include "BinarySearchTree.hpp"

bool BinaryTree::isValid(Node* head, int min, int max) {
    if (head == nullptr)
        return true;

    if (head->value <= min || head->value >= max)
        return false;

    if(isValid(head->left, min, head->value) && isValid(head->right, head->value, max))
        return true;
    else 
        return false;
}