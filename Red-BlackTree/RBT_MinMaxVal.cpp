#include "RedBlackTree.hpp"

Node* BinaryTree :: minVal(Node *head){
    if (head == nullptr)
        return nullptr;

    while(head->left)
        head = head->left;
    return head;
}

Node* BinaryTree :: maxVal(Node *head){
    if (head == nullptr)
        return nullptr;
    
    while(head->right)
        head = head->right;
    return head;
}