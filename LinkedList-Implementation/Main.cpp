#include "LinkedList.hpp"

int main() {
    //  Default constructor
    List list1;
    cout << "List1 after default construction: ";
    list1.printList();

    //  Variadic constructor
    List list2(5, 10, 20, 30, 40, 50);
    cout << "List2 after variadic construction: ";
    list2.printList();

    //  insert_begin and insert_end
    list1.insert_begin(1);
    list1.insert_begin(2);
    list1.insert_end(3);
    list1.insert_end(4);
    cout << "List1 after insertions: ";
    list1.printList();

    //  Copy constructor
    List list3 = list1;
    cout << "List3 (copy of List1): ";
    list3.printList();

    //  Move constructor
    List list4 = std::move(list2);
    cout << "List4 (moved from List2): ";
    list4.printList();
    cout << "List2 after move: ";
    list2.printList();

    //  Copy assignment
    list2 = list1;
    cout << "List2 after copy assignment from List1: ";
    list2.printList();

    //  Move assignment
    list2 = move(list3);
    cout << "List2 after move assignment from List3: ";
    list2.printList();
    cout << "List3 after move: ";
    list3.printList();

    //  operator+
    List list5 = list1 + list4;
    cout << "List5 (List1 + List4): ";
    list5.printList();

    //  operator+=
    list1 += list4;
    cout << "List1 after list1 += list4: ";
    list1.printList();

    // deleteNodeByValue
    list1.deleteNodeByValue(3);  // delete middle
    list1.deleteNodeByValue(2);  // delete head
    list1.deleteNodeByValue(100); // value not found
    cout << "List1 after deletions: ";
    list1.printList();

    //  size
    cout << "Size of List1: " << list1.size() << endl;
    cout << "Size of List4: " << list4.size() << endl;

    //  Edge cases: empty lists
    List emptyList;
    List emptyCopy = emptyList; // copy constructor on empty
    List emptyMoved = move(emptyList); // move constructor on empty
    cout << "Empty copy: ";
    emptyCopy.printList();
    cout << "Empty moved: ";
    emptyMoved.printList();

    return 0;
}