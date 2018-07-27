#include "LinkedList.h"
#include <string>

int main() { //Temporary Test Main will be split from the implementation file in the future
    DLL::LinkedList <int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(10);

    DLL::LinkedList <bool> list2;
    list2.append(true);
    list2.append(false);
    list2.append(false);
    list2.append(true);

    DLL::LinkedList <char> list3;
    list3.append('a');
    list3.append('b');
    list3.append('c');

    DLL::LinkedList <std::string> list4;
    list4.append("Hello");
    list4.append("World");

    list.reverse_print();
    list2.print();
    list3.print();
    list4.reverse_print();
    return 0;
}
