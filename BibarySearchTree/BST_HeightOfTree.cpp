#include "BinarySearchTree.hpp"

size_t BinaryTree :: heightOfTree(Node *head){
    if (!head)
        return 0;
    size_t l_height = heightOfTree(head->left);
    size_t r_height = heightOfTree(head->right);
    size_t height;
    if(r_height > l_height)
        height = r_height + 1;
    else
        height = l_height + 1;
    return height;
}