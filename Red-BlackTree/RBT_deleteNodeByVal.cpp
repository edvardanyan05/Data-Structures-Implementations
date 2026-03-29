#include "RedBlackTree.hpp"

void RedBlackTree :: delete_fixup(Node* doubleBlack){
    
    while(doubleBlack != head){

        // doubleBlack is left child
        if (doubleBlack == doubleBlack->parent->left){
            Node* sibling = doubleBlack->parent->right;
            
            //case 1
            if (sibling->color){
                sibling->color = 0;
                doubleBlack->parent->color = 1;
                leftRotate(doubleBlack->parent);
                sibling = doubleBlack->parent->right;
            }

            //case 2
            if((!sibling->left || !sibling->left->color) && (!sibling->right || !sibling->right->color)){
                sibling->color = 1;
                if (doubleBlack->parent->color){
                    doubleBlack->parent->color = 0;
                    return;
                }
                doubleBlack = doubleBlack->parent;
            }else{
                //case 3
                if((sibling->left && sibling->left->color) && (!sibling->right || !sibling->right->color)){
                    sibling->left->color = 0;
                    sibling->color = 1;
                    rightRotate(sibling);
                    sibling = doubleBlack->parent->right;
                }

                //case 4
                sibling->color = doubleBlack->parent->color;
                doubleBlack->parent->color = 0;
                sibling->right->color = 0;
                leftRotate(doubleBlack->parent);
                return;
            }
            
        // doubleBlack is right child
        }else{
            Node* sibling = doubleBlack->parent->left;

            //case 1
            if (sibling->color){
                sibling->color = 0;
                doubleBlack->parent->color = 1;
                rightRotate(doubleBlack->parent);
                sibling = doubleBlack->parent->left;
            }

            //case 2
            if((!sibling->left || !sibling->left->color) && (!sibling->right || !sibling->right->color)){
                sibling->color = 1;
                if (doubleBlack->parent->color){
                    doubleBlack->parent->color = 0;
                    return;
                }
                doubleBlack = doubleBlack->parent;
            }else{
                //case 3
                if((!sibling->left || !sibling->left->color) && (sibling->right && sibling->right->color)){
                    sibling->right->color = 0;
                    sibling->color = 1;
                    leftRotate(sibling);
                    sibling = doubleBlack->parent->left;
                }

                //case 4
                sibling->color = doubleBlack->parent->color;
                doubleBlack->parent->color = 0;
                sibling->left->color = 0;
                rightRotate(doubleBlack->parent);
                return;
            }
        }
    }

}

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

            needToDelete->value = successor->value;
            needToDelete = successor;
            delete_fixup(needToDelete);  
            if (needToDelete == needToDelete->parent->left)
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;

            delete needToDelete;
            needToDelete = nullptr;
            return;
        }
    }


}