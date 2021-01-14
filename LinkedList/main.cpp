#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList l;
    l.insertFront(10);
    l.insertBack(30);
    l.insertBack(40);
    l.insertAt(1, 20);
    l.insertFront(0);
    l.insertBack(50);
//    l.removeFront();
//    l.removeBack();
//    l.removeAt(2);
    l.print();
    cout << endl;
    cout << l.search(50) << endl;
    l.reverse();
    l.print();
    cout << endl;
    cout << l.search(20);
    return 0;
}
