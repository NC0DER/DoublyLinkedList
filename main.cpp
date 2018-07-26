#include "LinkedList.h"

int main() { //Temporary Test Main will be split from the implementation file in the future
    DLL::LinkedList <int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.print();
    return 0;
}
