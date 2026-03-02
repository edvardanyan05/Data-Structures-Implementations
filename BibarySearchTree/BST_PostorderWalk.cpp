#include "BinarySearchTree.hpp"

void BinaryTree :: postorderTreeWalk(Node *head, vector <int> &tree_elements){
    if (!head)
        return;
    postorderTreeWalk(head->left, tree_elements);
    postorderTreeWalk(head->right, tree_elements);
    tree_elements.push_back(head->value);
}