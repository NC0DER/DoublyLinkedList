#include "LinkedList.h"
#include <string>

int main() { //Temporary Test Main will be split from the implementation file in the future
    DLL::LinkedList <int> list;
    list.fill({1, 2, 3, 4, 5, 7, 8, 9, 10}); //Instead of manually filling list


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
