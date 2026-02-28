#include "String.hpp"

String :: String(){
    usingStack = true;
    small_string[0] = '\0';
}

String :: String(const char* str){
    size_t str_len = 0;
    while (str[str_len] != '\0')
        ++str_len;

    if(str_len <= small_string_size){
        usingStack = true;
        for(size_t i = 0 ; i < str_len; ++i)
            small_string[i] = str[i];
        small_string[str_len] = '\0';
    }else{
        usingStack = false;
        heapPTR = new char[str_len + 1];
        m_size = str_len;
        m_capacity = str_len;
        for(size_t i = 0 ; i < str_len; ++i)
            heapPTR[i] = str[i];
        heapPTR[str_len] = '\0';
    }
}

String :: String(const String &other){
    usingStack = other.usingStack;
    if(usingStack){
        for(size_t i = 0 ; i < small_string_size ; i++){
            small_string[i] = other.small_string[i];
            if(other.small_string[i] == '\0')
                break;
        }
    }else{
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        heapPTR = new char[m_size + 1];
        for(size_t i = 0 ; i <= other.m_size ; i++)
            heapPTR[i] = other.heapPTR[i];
    }
}

String :: ~String(){
    if(!usingStack){
        delete[] heapPTR;
        heapPTR = nullptr;
    }
}