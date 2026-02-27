#include "LinkedList.hpp"

List& List :: operator=(const List& other){
    if (this == &other)
        return *this;

    while(head != nullptr){
        Node * needDeletePTR = head;
        head = head->next;
        delete needDeletePTR;
    }
    if (!other.head)
        return *this;
    head = new Node(other.head->value);
    Node* it_this = head;
    Node* it_other = other.head;
    while(it_other->next){
        it_this->next = new Node(it_other->next->value);
        it_this = it_this->next;
        it_other = it_other->next;
    }
    return *this;
}


List& List :: operator=(List&& other){
    if (this == &other)
        return *this;

    while(head != nullptr){
        Node * needDeletePTR = head;
        head = head->next;
        delete needDeletePTR;
    }

    head = other.head;
    other.head = nullptr;
    return *this;
}


List List :: operator+(const List& other) const{
    List tmp;
    if(head == nullptr && other.head == nullptr)
        return tmp;

    Node* it_this = head;
    Node* it_other = other.head;
    Node* it_tmp;

    if(it_this != nullptr){
        it_tmp = new Node(head->value);
        tmp.head = it_tmp;
        while(it_this->next){
            it_tmp->next = new Node(it_this->next->value);
            it_this = it_this->next;
            it_tmp = it_tmp->next;
        }
    }
    if(it_other != nullptr){
        if (tmp.head != nullptr){
            it_tmp->next = new Node(it_other->value);
        }
        else{
            it_tmp = new Node(it_other->value);
            tmp.head = it_tmp;
        }

        while(it_other->next){
            it_tmp->next = new Node(it_other->next->value);
            it_other = it_other->next;
            it_tmp = it_tmp->next;
        }
    }
    return tmp;
}


List& List :: operator+=(const List& other){
    *this = *this + other;
    return *this;
}