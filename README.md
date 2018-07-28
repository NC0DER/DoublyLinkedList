# DoublyLinkedList
A Doubly Linked List Library made with templates, smart pointers, std::containers and other C++14, C++11 coding conventions.  
Features a main.cpp for testing the effect of the methods described below.  
If you like to give it a try you can just simply include `LinkedList.h` to your project.  

## Class methods  
- [x] `fill()`   : fills the list by appending its read element by the initializer_list provided.  
- [x] `empty()`  : returns `true` if the list is empty, `false` otherwise.  
- [x] `length()` : returns an `int` which holds the length of the list.  
- [x] `append()` : appends the provided element at the end of the list.  
- [x] `remove()` : Searchs and removes the provided element in any part of the list.  
- [x] `search()` : Searchs the list for the provided element, if it's found 1 is returned, if not 0, if the list is empty -1 (error).  
- [x] `print()`  : prints the list in this format `[ <element1> ... <elementN> ]`, where N is the order of insertion.  
- [x] `reverse_ print()`  : prints the list in this format `[ <elementN> ... <element1> ]`, where N is the order of insertion.  

## Example Usage
Make a main.cpp, include the LinkedList.h and you can declare a DoublyLinkedList like this:  
```cpp
#include "LinkedList.h" //namespace is DLL for the list object in order to avoid conflict with other common implementations.

int main() {
    DLL::LinkedList <int> list; //Create an empty list.
    list.fill({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}); //you could fill the list by appending iteratively.

    DLL::LinkedList <bool> list2({true, false, false, true}); //same as filling list but with a constructor.
    DLL::LinkedList <char> list3({'a', 'b', 'c'});

    DLL::LinkedList <std::string> list4; //Empty list.
    list4.append("Hello"); //You could fill it manually.
    list4.append("World");
    
    //...
    
    return 0;
}
```
Compile using a `-std=c++14` flag because of the `make_unique()` call and other features that are used.
