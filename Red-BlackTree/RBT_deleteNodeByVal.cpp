#include "RedBlackTree.hpp"

void RedBlackTree :: deleteNode(int val){
    Node* needToDelete = searching(head, val);
    if (!needToDelete)
        return;
    
    Node* successor = successor(val);
    if (needToDelete->color){
        
        if (!needToDelete->left && !needToDelete->right){
            if(needToDelete == needToDelete->parent->left)
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return ;
        }

        if (successor->color){
            needToDelete->value = successor->value;
            needToDelete = successor;
            if(needToDelete == needToDelete->parent->left)
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return ;
        }else{
            if (successor->right){
                needToDelete->value = successor->value;
                successor->value = successor->right->value;
                needToDelete = successor->right;
                needToDelete->parent->right = nullptr;
                delete needToDelete;
                needToDelete = nullptr;
                return ;
            }


        }
    }


}