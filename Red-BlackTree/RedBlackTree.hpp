#pragma once

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node{
    int value;
    bool color; //   0 - Black  |  1 - Red
    Node *left;
    Node *right;
    Node *parent;

    Node();
    Node(int);
};

class RedBlackTree{
private:
    Node* head;
    void deleteTree(Node *);
public:
    RedBlackTree();
    ~RedBlackTree();
public:
    void leftRotate(Node *);
    void rightRotate(Node *);
};