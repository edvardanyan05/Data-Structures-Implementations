#pragma once

#include <iostream>
#include <cstddef>
#include <cstdarg>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node();
    Node(int);
};


class List{
private:
    Node* head;
public:
    List();
    List(size_t, ...);
    List(const List &);
    List(List &&);
    ~List();
    List& operator=(const List&);
    List& operator=(List&& other);
    List  operator+(const List& other) const;
    List& operator+=(const List& other);
public:
    void insert_begin(int);
    void insert_end(int);
    void deleteNodeByValue(int);
    void printList() const;
    size_t size() const;
};