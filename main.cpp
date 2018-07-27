#include "LinkedList.h"
#include <string>

int main() { //Temporary Test Main will be split from the implementation file in the future
    DLL::LinkedList <int> list; //Create an empty list
    list.fill({1, 2, 3, 4, 5, 7, 8, 9, 10}); //fill list by appending iteratively.

    DLL::LinkedList <bool> list2({true, false, false, true}); // same as filling list but with a constructor.
    DLL::LinkedList <char> list3({'a', 'b', 'c'});

    DLL::LinkedList <std::string> list4; //Empty list
    list4.append("Hello"); //Fill it manually
    list4.append("World");

    list.reverse_print();
    list2.print();
    list3.print();
    list4.reverse_print();
    return 0;
}
