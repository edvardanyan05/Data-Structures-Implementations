#include "RedBlackTree.hpp"

Node :: Node(){
    value = 0;
    color = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node :: Node(int v, bool c){
    value = v;
    color = c;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}