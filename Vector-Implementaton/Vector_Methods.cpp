#include "VectorImplement.hpp"

void Vector :: push_back(int elem){
    if(m_capacity == m_size){
        m_capacity *= 2;
        int *cpyPtr = new int[m_capacity];
        for(int i = 0 ; i < m_size ; ++i)
            cpyPtr[i] = ptr_arr[i];
        delete[] ptr_arr;
        ptr_arr = cpyPtr;
    }
    ptr_arr[m_size] = elem;
    m_size++;
}

void Vector :: push_front(int elem){
    if(m_capacity == m_size){
        m_capacity *= 2;
        int *cpyPtr = new int[m_capacity];
        for(int i = 0 ; i < m_size ; i++)
            cpyPtr[i] = ptr_arr[i];
        delete[]ptr_arr;
        ptr_arr = cpyPtr;
    }
    for(int i = m_size ; i > 0 ; i--)
        ptr_arr[i] = ptr_arr[i-1];        
    ptr_arr[0] = elem;
    m_size++;
}

void Vector :: pop_back(){
    if (m_size == 0)
        return;
    int *cpyPtr = new int[m_capacity];
    for(int i = 0 ; i < m_size - 1 ; i++)
        cpyPtr[i] = ptr_arr[i];
    delete[]ptr_arr;
    ptr_arr = cpyPtr;
    m_size--;
}

void Vector :: pop_front(){
    if (m_size == 0)
        return;
    int*cpyPtr = new int[m_capacity];
    for(int i = 0 ; i < m_size - 1; i++)
        cpyPtr[i] = ptr_arr[i+1];
    delete[]ptr_arr;
    ptr_arr = cpyPtr;
    m_size--;
}

int Vector :: size() const{
    return m_size;
}

void Vector :: printArr() const{
    for(int i = 0 ; i < m_size ; ++i)
        cout << ptr_arr[i] << " ";
}