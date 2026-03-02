#include "BinarySearchTree.hpp"

void BinaryTree :: preorderTreeWalk(Node *head, vector <int> &tree_elements){
    if (!head)
        return;
    tree_elements.push_back(head->value);
    preorderTreeWalk(head->left, tree_elements);
    preorderTreeWalk(head->right, tree_elements);
}