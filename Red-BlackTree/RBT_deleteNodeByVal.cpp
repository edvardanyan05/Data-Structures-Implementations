#include "RedBlackTree.hpp"

// Helper to safely check color (treats nullptr as BLACK)
static bool isBlack(Node* n) {
    return !n || n->color == 0;
}

void RedBlackTree :: delete_fixup(Node* doubleBlack){
    
    while(doubleBlack != head){

        // doubleBlack is left child
        if (doubleBlack == doubleBlack->parent->left){
            Node* sibling = doubleBlack->parent->right;

            // Case 1: Sibling is RED
            if (sibling->color){
                sibling->color = 0;
                doubleBlack->parent->color = 1;
                leftRotate(doubleBlack->parent);
                sibling = doubleBlack->parent->right;
            }

            // Case 2: Both sibling's children are BLACK
            if(isBlack(sibling->left) && isBlack(sibling->right)){
                sibling->color = 1;
                if (doubleBlack->parent->color){
                    doubleBlack->parent->color = 0;
                    return;
                }
                doubleBlack = doubleBlack->parent;
            }else{
                // Case 3: Sibling's left is RED, right is BLACK
                if(isBlack(sibling->right)){
                    if (sibling->left)
                        sibling->left->color = 0;
                    sibling->color = 1;
                    rightRotate(sibling);
                    sibling = doubleBlack->parent->right;
                }

                // Case 4: Sibling's right is RED
                sibling->color = doubleBlack->parent->color;
                doubleBlack->parent->color = 0;
                if (sibling->right)
                    sibling->right->color = 0;
                leftRotate(doubleBlack->parent);
                return;
            }
            
        // doubleBlack is right child
        }else{
            Node* sibling = doubleBlack->parent->left;

            // Case 1: Sibling is RED
            if (sibling->color){
                sibling->color = 0;
                doubleBlack->parent->color = 1;
                rightRotate(doubleBlack->parent);
                sibling = doubleBlack->parent->left;
            }

            // Case 2: Both sibling's children are BLACK
            if(isBlack(sibling->left) && isBlack(sibling->right)){
                sibling->color = 1;
                if (doubleBlack->parent->color){
                    doubleBlack->parent->color = 0;
                    return;
                }
                doubleBlack = doubleBlack->parent;
            }else{
                // Case 3: Sibling's right is RED, left is BLACK
                if(isBlack(sibling->left)){
                    sibling->right->color = 0;
                    sibling->color = 1;
                    leftRotate(sibling);
                    sibling = doubleBlack->parent->left;
                }

                //case 4
                sibling->color = doubleBlack->parent->color;
                doubleBlack->parent->color = 0;
                if (sibling->left)
                    sibling->left->color = 0;
                rightRotate(doubleBlack->parent);
                return;
            }
        }
    }

    // Head color making black (safe)
    head->color = 0;
}

void RedBlackTree :: deleteNode(int val){
    Node* needToDelete = searching(head, val);
    if (!needToDelete)
        return;
    
    Node* succ = successor(val);
    if (needToDelete->color){
        // === The Node we want to delete is RED ===

        // needToDelete is a LEAF node
        if (!needToDelete->left && !needToDelete->right){
            if(needToDelete == needToDelete->parent->left)
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return ;
        }
        // successor is RED
        // If needToDelete is red and the successor is red, then the successor is a LEAF Node.
        if (succ->color){
            needToDelete->value = succ->value;
            needToDelete = succ;
            if (needToDelete == needToDelete->parent->left) 
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return ;
        }else{
            // successor is Black
            // If needToDelete is red and the succ is black,
            // then the successor can either has only a RED RIGHT child or has NO child at all.
            
            // successor have only a RIGHT child
            if (succ->right){
                needToDelete->value = succ->value;
                succ->value = succ->right->value;
                needToDelete = succ->right;
                needToDelete->parent->right = nullptr;
                delete needToDelete;
                needToDelete = nullptr;
                return ;
            }

            // successor doesn't have child
            // need double black fixup
            needToDelete->value = succ->value;
            needToDelete = succ;
            delete_fixup(needToDelete);  
            if (needToDelete == needToDelete->parent->left)
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return;
        }
    }else{
        // === The Node we want to delete is BLACK ===

        // needToDelete is a LEAF node
        // need double black fixup
        if (!needToDelete->left && !needToDelete->right){
            delete_fixup(needToDelete);
            if(needToDelete == needToDelete->parent->left)
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return;
        }

        // needToDelete has one RED child

        //      left
        if (needToDelete->left && needToDelete->left->color && !needToDelete->right){
            needToDelete->value = needToDelete->left->value;
            needToDelete = needToDelete->left;
            needToDelete->parent->left = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return;
        }
        //      right
        if (needToDelete->right && needToDelete->right->color && !needToDelete->left){
            needToDelete->value = needToDelete->right->value;
            needToDelete = needToDelete->right;
            needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return;
        }

        // needToDelete has 2 children

        needToDelete->value = succ->value;
        needToDelete = succ;
        // successor does not have children
        if (!needToDelete->right){
            if (!needToDelete->color)
                delete_fixup(needToDelete);

            if(needToDelete == needToDelete->parent->left)
                needToDelete->parent->left = nullptr;
            else
                needToDelete->parent->right = nullptr;
            delete needToDelete;
            needToDelete = nullptr;
            return;
        }

        // succ has RED Right child
        needToDelete->value = needToDelete->right->value;
        needToDelete = needToDelete->right;
        needToDelete->parent->right = nullptr;
        delete needToDelete;
        needToDelete = nullptr;
    }


}