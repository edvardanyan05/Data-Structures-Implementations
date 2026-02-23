#include "vectorIplement.hpp"

Vector& Vector :: operator=(const Vector& other){
    if (this == &other)
        return *this;
    delete[] ptr_arr;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    ptr_arr = new int[m_capacity];
    for(int i = 0; i < m_size; i++)
        ptr_arr[i] = other.ptr_arr[i];
    return *this;
}

Vector Vector :: operator+(const Vector& other) const{
    cout << "op+" << endl;
    Vector tmp(m_size + other.m_size);
    for (int i = 0; i < m_size; ++i)
        tmp.push_back(ptr_arr[i]);
    for (int i = 0; i < other.m_size; ++i)
        tmp.push_back(other.ptr_arr[i]);

    return tmp;
}