#include "RedBlackTree.hpp"

void RedBlackTree :: leftRotate(Node *target){
    if (target == nullptr || target->right == nullptr)
        return;
    Node *rightChild = target->right;

    target->right = rightChild->left;
    if (rightChild->left)
        rightChild->left->parent = target;

    rightChild->parent = target->parent;
    if (!target->parent)
        head = rightChild;
    else if(target->parent->left == target)
        target->parent->left = rightChild;
    else
        target->parent->right = rightChild;
    
    rightChild->left = target;
    target->parent = rightChild;
}

void RedBlackTree :: rightRotate(Node *target){
    if (target == nullptr || target->left == nullptr)
        return;
    Node *leftChild = target->left;

    target->left = leftChild->right;
    if(leftChild->right)
        leftChild->right->parent = target;

    leftChild->parent = target->parent;
    if (!target->parent)
        head = leftChild;
    else if (target->parent->left == target)
        target->parent->left = leftChild;
    else
        target->parent->right = leftChild;

    leftChild->right = target;
    target->parent = leftChild; 
}