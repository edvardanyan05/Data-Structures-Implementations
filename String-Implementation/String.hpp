#pragma once

#include <iostream>
using namespace std;

class String{
    private:
    static constexpr size_t small_string_size = 22;

    union {
        char small_string[small_string_size + 1];
        struct{
            char* heapPTR;
            size_t m_size;
            size_t m_capacity;
        };
    };

    bool usingStack;

    public:
        String();
        String(const char* str);
        String(const String &other);
        ~String();

    public:
        char* c_str();
        size_t size();
        bool is_using_stack();
};