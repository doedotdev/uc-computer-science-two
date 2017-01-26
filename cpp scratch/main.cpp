#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    linkedList a;

    for (int i = 0 ; i< 10; i++){
        a.pushBack(i);
    }
    cout << a.getSizeQuick() << endl;


    return 0;
}