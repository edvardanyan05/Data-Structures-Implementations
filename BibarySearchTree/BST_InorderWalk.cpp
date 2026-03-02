#include "BinarySearchTree.hpp"

void BinaryTree :: inorderTreeWalk(Node *head, vector <int> &tree_elements){
    if (!head)
        return;
    inorderTreeWalk(head->left, tree_elements);
    tree_elements.push_back(head->value);
    inorderTreeWalk(head->right, tree_elements);
}