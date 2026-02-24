#include "LinkedList.hpp"

List :: List(){
    head = nullptr;
}
List :: ~List(){
    while(head!= nullptr){
        Node* needDeletePTR = head;
        head = head->next;
        delete needDeletePTR;
    }
}