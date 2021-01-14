#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList<int> dl;
    dl.insertAt(0, 10);
    dl.insertAt(1, 20);
    dl.insertAt(2, 30);
    dl.insertAt(3, 40);
    dl.insertAt(4, 50);
    dl.insertFront(0);
    dl.insertBack(60);
    dl.removeFront();
    dl.removeBack();
    dl.removeAt(4);
    dl.remove(10);
    dl.print();
    dl.printReverse();
    return 0;
}
