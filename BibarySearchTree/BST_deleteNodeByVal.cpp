#include "BinarySearchTree.hpp"

void BinaryTree::deleteNode(Node *&head, int val) {
    if (!head)
        return;

    Node *parent = nullptr;
    Node *current = head;

    while (current && current->value != val) {
        parent = current;
        if (val < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (!current)
        return;

    Node *needToDelete = current;
    Node *replacement = nullptr;

    if (!needToDelete->left && !needToDelete->right) {
        replacement = nullptr;
    }
    else if (!needToDelete->right) {
        replacement = needToDelete->left;
    }
    else if (!needToDelete->left) {
        replacement = needToDelete->right;
    }
    else {
        replacement = needToDelete->left;
        Node *it = replacement;
        while (it->right)
            it = it->right;
        it->right = needToDelete->right;
    }

    if (!parent) {
        head = replacement;
    } else if (parent->left == needToDelete) {
        parent->left = replacement;
    } else {
        parent->right = replacement;
    }

    delete needToDelete;
    needToDelete = nullptr;
}