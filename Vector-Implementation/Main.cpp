#include "VectorImplement.hpp"

int main() {
    cout << "--- Default Constructor ---" << endl;
    Vector v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_front(5);
    cout << "v1 after push_back and push_front: ";
    v1.printArr();
    cout << "\nSize: " << v1.size() << endl << endl;

    cout << "--- Parameterized Constructor ---" << endl;
    Vector v2(5);
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    cout << "v2: ";
    v2.printArr();
    cout << "\nSize: " << v2.size() << endl << endl;

    cout << "--- Copy Constructor ---" << endl;
    Vector v3(v2);
    cout << "v3 (copy of v2): ";
    v3.printArr();
    cout << "\nSize: " << v3.size() << endl << endl;

    cout << "--- Move Constructor ---" << endl;
    Vector v4(std::move(v3));
    cout << "v4 (moved from v3): ";
    v4.printArr();
    cout << "\nSize: " << v4.size() << endl;
    cout << "v3 after move: ";
    v3.printArr();
    cout << "\nSize: " << v3.size() << endl << endl;

    cout << "--- Copy Assignment ---" << endl;
    v1 = v2;
    cout << "v1 after copy assignment from v2: ";
    v1.printArr();
    cout << "\nSize: " << v1.size() << endl << endl;

    cout << "--- Move Assignment ---" << endl;
    v4 = std::move(v2);
    cout << "v4 after move assignment from v2: ";
    v4.printArr();
    cout << "\nSize: " << v4.size() << endl;
    cout << "v2 after move: ";
    v2.printArr();
    cout << "\nSize: " << v2.size() << endl << endl;

    cout << "--- Operator+ and Operator+= ---" << endl;
    Vector v5;
    v5.push_back(100);
    v5.push_back(200);

    Vector v6;
    v6.push_back(1);
    v6.push_back(2);

    Vector v7 = v5 + v6;
    cout << "v7 (v5 + v6): ";
    v7.printArr();
    cout << "\nSize: " << v7.size() << endl;

    v5 += v6;
    cout << "v5 after v5 += v6: ";
    v5.printArr();
    cout << "\nSize: " << v5.size() << endl << endl;

    cout << "--- Pop Back and Pop Front ---" << endl;
    cout << "v5 before pop: ";
    v5.printArr();
    cout << endl;
    v5.pop_back();
    v5.pop_front();
    cout << "v5 after pop_back and pop_front: ";
    v5.printArr();
    cout << "\nSize: " << v5.size() << endl;

    return 0;
}