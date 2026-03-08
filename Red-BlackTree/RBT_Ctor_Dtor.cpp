#include "RedBlackTree.hpp"

RedBlackTree :: RedBlackTree(){
    head = nullptr;
}

RedBlackTree :: ~RedBlackTree(){
    deleteTree(head);
    head = nullptr;
}