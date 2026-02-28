#include "String.hpp"

int main() {

    cout << "----- Small String Test -----\n";
    String s1("hello");
    cout << "s1: " << s1.c_str() << "\n";
    cout << "size: " << s1.size() << "\n";
    cout << "using stack: " << s1.is_using_stack() << "\n\n";


    cout << "----- Large String Test -----\n";
    String s2("This string is definitely longer than twenty two characters");
    cout << "s2: " << s2.c_str() << "\n";
    cout << "size: " << s2.size() << "\n";
    cout << "using stack: " << s2.is_using_stack() << "\n\n";


    cout << "----- Copy Constructor (Small) -----\n";
    String s3(s1);
    cout << "s3: " << s3.c_str() << "\n";
    cout << "size: " << s3.size() << "\n";
    cout << "using stack: " << s3.is_using_stack() << "\n\n";


    cout << "----- Copy Constructor (Heap) -----\n";
    String s4(s2);
    cout << "s4: " << s4.c_str() << "\n";
    cout << "size: " << s4.size() << "\n";
    cout << "using stack: " << s4.is_using_stack() << "\n\n";

    cout << "Program finished successfully.\n";

    return 0;
}