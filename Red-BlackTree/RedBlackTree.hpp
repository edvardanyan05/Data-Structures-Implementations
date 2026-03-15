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
    void leftRotate(Node *);
    void rightRotate(Node *);
public:
    RedBlackTree();
    ~RedBlackTree();
public:
    void insertNode(int);

    Node*  searching(Node *, int);
    Node*  minVal();
    Node*  maxVal();
    Node*& getRoot();

    size_t heightOfTree(Node *);
};