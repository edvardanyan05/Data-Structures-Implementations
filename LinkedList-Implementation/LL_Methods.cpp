#include "LinkedList.hpp"

void List :: insert_begin(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void List :: insert_end(int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node*p = head;
    while(p->next != nullptr)
        p = p->next;
    p->next = newNode;
}

void List :: deleteNodeByValue(int value){
    if(head == nullptr)
        return;

    if(head->val == value){
        Node*needDeletePTR = head; 
        head = head->next;
        delete needDeletePTR;
        return;
    }    
    
    Node*p = head;
    while(p->next != nullptr && p->next->val != value)
        p = p->next;
    if(p->next == nullptr)
        return;
    Node*needDeletePTR = p->next;
    p->next = p->next->next;
    delete needDeletePTR;
}

void List :: printList() const{
    Node*p = head;
    cout << "List - ";
    while(p != nullptr){
        cout <<p->val << " ";
        p = p->next;
    }
    cout << endl;
}

size_t List :: size() const{
    size_t len = 0;
    Node*p = head;
    while(p != nullptr){
        len++;
        p = p->next;
    }
    return len;
}
