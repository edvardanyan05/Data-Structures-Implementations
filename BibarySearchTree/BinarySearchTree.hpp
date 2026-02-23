#pragma once

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node(){};
    Node(int){};
};

class BinaryTree{
private:
    Node *head;
public:
    BinaryTree(){};
    ~BinaryTree(){};
public:
    void insertNode(int){};
}

void deleteSubTree(Node *);