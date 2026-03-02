#include "BinarySearchTree.hpp"

BinaryTree :: BinaryTree(){
    head = nullptr;
}

BinaryTree :: ~BinaryTree(){
    deleteSubTree(head);
    head = nullptr;
}