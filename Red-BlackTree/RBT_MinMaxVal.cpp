#include "RedBlackTree.hpp"

Node* RedBlackTree :: minVal(Node *head){
    if (head == nullptr)
        return nullptr;

    while(head->left)
        head = head->left;
    return head;
}

Node* RedBlackTree :: maxVal(Node *head){
    if (head == nullptr)
        return nullptr;
    
    while(head->right)
        head = head->right;
    return head;
}
