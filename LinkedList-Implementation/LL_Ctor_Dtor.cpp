#include "LinkedList.hpp"

List :: List(){
    head = nullptr;
}


List :: List(size_t lst_length, ...){
    if (lst_length == 0) {
        head = nullptr;
        return;
    }

    va_list args;
    va_start(args, lst_length);

    head = new Node(va_arg(args, int));
    Node* current = head;
    for(size_t i = 2; i <= lst_length; i++){
        current->next = new Node(va_arg(args, int));
        current = current->next;
    }

    va_end(args);
}


List :: List(const List &other){
    if(!other.head){
        head = nullptr;
        return;
    }
    head = new Node(other.head->value);
    Node* it_this = head;
    Node* it_other = other.head;
    while(it_other->next != nullptr){
        it_this->next = new Node(it_other->next->value);
        it_this = it_this->next;
        it_other = it_other->next;
    }
}


List :: List(List &&other){
    head = other.head;
    other.head = nullptr;
}


List :: ~List(){
    while(head != nullptr){
        Node* needDeletePTR = head;
        head = head->next;
        delete needDeletePTR;
    }
}