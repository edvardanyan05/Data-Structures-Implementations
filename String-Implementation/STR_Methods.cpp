#include "String.hpp"

char* String :: c_str(){
    if(usingStack)
        return small_string;
    else
        return heapPTR;
}

size_t String :: size(){
    if(usingStack){
        size_t str_len = 0;
        while (small_string[str_len] != '\0')
            ++str_len;
        return str_len;
    }else{
        return m_size;
    }
}

bool String :: is_using_stack(){
    return usingStack;
}