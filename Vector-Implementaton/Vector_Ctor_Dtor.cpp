#include "vectorIplement.hpp"

Vector :: Vector(){
    m_capacity = 1;
    m_size = 0;
    ptr_arr = new int[m_capacity];
}

Vector :: Vector(size_t n){
    m_capacity = n;
    m_size = 0;
    ptr_arr = new int[m_capacity];
}

Vector :: Vector(const Vector& other){
    cout << "cpy ctor" << endl;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    ptr_arr = new int[m_capacity];
    for(int i = 0 ; i < m_size ; i++)
    ptr_arr[i] = other.ptr_arr[i];
}
    
Vector :: Vector(Vector&& other){
    cout << "mv ctor" << endl;
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    ptr_arr = other.ptr_arr;
    other.ptr_arr = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

Vector :: ~Vector(){
    delete[] ptr_arr;
    ptr_arr = nullptr;
}