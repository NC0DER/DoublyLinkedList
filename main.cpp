#include "LinkedList.h"
#include <string>

int main() { //Temporary Test Main will be split from the implementation file in the future
    DLL::LinkedList <int> list; //Create an empty list
    list.fill({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}); //fill list by appending iteratively.

    DLL::LinkedList <bool> list2({true, false, false, true}); // same as filling list but with a constructor.
    DLL::LinkedList <char> list3({'a', 'b', 'c'});

    DLL::LinkedList <std::string> list4; //Empty list
    list4.append("Hello"); //Fill it manually
    list4.append("World");

    DLL::LinkedList <int> list5; //Empty list
    list5.remove(1);
    list5.append(1);
    list5.print();
    list5.remove(1);
    list5.append(1);
    list5.append(2);
    list5.print();
    list5.remove(2);
    list5.print();
    list5.append(3);
    list5.append(4);
    list5.print();
    list5.remove(3);
    list5.print();
    list5.fill({5,6});
    list5.print();
    list5.remove(5);
    list5.remove(1);
    list5.remove(4);
    list5.remove(6);
    list5.print();
    std::cout << "List empty? (0 = false, 1 = true): " << list5.empty() << std::endl;

    std::cout << "Search returns: " << list.search(10) << " (-1 for empty list, 0 not found, 1 found)" << std::endl;
    std::cout << "The length of the 1st list is: " << list.length() << std::endl;
    list.reverse_print();
    list2.print();
    list3.print();
    list4.reverse_print();
    return 0;
}
