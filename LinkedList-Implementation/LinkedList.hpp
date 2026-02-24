#pragma once

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

class List{
private:
    Node* head;
public:
    List();
    ~List();
public:
    void insert_begin(int);
    void insert_end(int);
    void deleteNodeByValue(int);
    void printList() const;
    size_t size() const;
};