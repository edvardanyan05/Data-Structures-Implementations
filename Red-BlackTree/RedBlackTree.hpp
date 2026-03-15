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
    Node(int, bool);
};

class RedBlackTree{
private:
    Node* head;
    void deleteTree(Node *);
    void fixup(Node *);
public:
    RedBlackTree();
    ~RedBlackTree();
public:
    void leftRotate(Node *);
    void rightRotate(Node *);
    void insertNode(int);

    Node*  minVal(Node *);
    Node*  maxVal(Node *);
    Node*& getRoot();

    size_t heightOfTree(Node *);
};