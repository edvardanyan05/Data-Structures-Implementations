#pragma once

#include <iostream>
#include <cstddef>
using namespace std;

class Vector {
private:
    int m_capacity;
    int m_size;
    int* ptr_arr;

public:
    Vector();
    Vector(size_t);
    Vector(const Vector&);
    Vector(Vector&&);
    ~Vector();
    Vector  operator+(const Vector&) const;
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);
    Vector& operator+=(const Vector&);

public:
    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    int size() const;
    void printArr() const;
};