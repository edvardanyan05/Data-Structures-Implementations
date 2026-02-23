#include "BinaryTree.hpp"

void BinaryTree :: insertNode(int val){
    if (!head){
        head = new Node(val);
        return;
    }
    Node *it = head;
    while(true){
        if (val > it->value){
            if (it->right == nullptr){
                it->right = new Node(val);
                return;
            }
            it = it->right;
        }
        else{
            if (it->left == nullptr){
                    it->left = new Node(val);
                    return;
            }
            it = it->left;
        }
    }
}