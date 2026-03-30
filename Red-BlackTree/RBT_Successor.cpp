#include "RedBlackTree.hpp"

Node* RedBlackTree :: successor(int val){
    Node* current = searching(head, val);
    if (!current)
        return nullptr;

    Node* succ = nullptr;
    if(current->right){
        succ = current->right;
        while(succ->left)
            succ = succ->left;
        return succ;
    }

    succ = current->parent;
    while(succ && current == succ->right){
        current = succ;
        succ = succ->parent;
    }
    return succ;
}