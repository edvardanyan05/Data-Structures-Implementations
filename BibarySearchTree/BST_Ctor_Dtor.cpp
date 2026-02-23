#include "BinaryTree.hpp"

BinaryTree :: BinaryTree(){
    head = nullptr;
}

BinaryTree :: ~BinaryTree(){
    deleteSubTree(head);
}