#include "RedBlackTree.hpp"

void RedBlackTree :: insert_fixup(Node *newNode){
    while(newNode != head && newNode->parent && newNode->parent->color){
        if (newNode->parent == newNode->parent->parent->left){
            Node *uncle = newNode->parent->parent->right;
            if (uncle && uncle->color){
                newNode->parent->color = 0;
                uncle->color = 0;
                newNode->parent->parent->color = 1;
                newNode = newNode->parent->parent;
            }else{
                if (newNode == newNode->parent->right){
                    newNode = newNode->parent;
                    leftRotate(newNode);
                }
                newNode->parent->color = 0;
                newNode->parent->parent->color = 1;
                rightRotate(newNode->parent->parent);
            }
        }else{
            Node *uncle = newNode->parent->parent->left;
            if (uncle && uncle->color){
                newNode->parent->color = 0;
                uncle->color = 0;
                newNode->parent->parent->color = 1;
                newNode = newNode->parent->parent;
            }else{
                if (newNode == newNode->parent->left){
                    newNode = newNode->parent;
                    rightRotate(newNode);
                }
                newNode->parent->color = 0;
                newNode->parent->parent->color = 1;
                leftRotate(newNode->parent->parent);
            }
        }
    }
    head->color = 0;
}

void RedBlackTree :: insertNode(int val){
    if (!head){
        head = new Node(val, 0);
        return;
    }

    Node *it = head;
    while(true){
        if(val > it->value){
            if (it->right == nullptr){
                it->right = new Node(val, 1);
                it->right->parent = it;
                insert_fixup(it->right);
                return;
            }
            it = it->right;
        }
        else{
            if (it->left == nullptr){
                it->left = new Node(val, 1);
                it->left->parent = it;
                insert_fixup(it->left);
                return;
            }
            it = it->left;
        }
    }
}