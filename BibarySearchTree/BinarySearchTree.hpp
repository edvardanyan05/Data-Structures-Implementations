#pragma once

#include <iostream>
#include <vector>
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
    void deleteSubTree(Node *);
public:
    BinaryTree(){};
    ~BinaryTree(){};
public:
    void insertNode(int){};
    void inorderTreeWalk(Node *, vector <int> &);
    void preorderTreeWalk(Node *, vector <int> &);
    void postorderTreeWalk(Node *head, vector <int> &);
    
    size_t heightOfTree(Node *);

    Node* searching(Node *, int);
}

