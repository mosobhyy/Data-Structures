#include <iostream>
#include "arrayList.h"
using namespace std;

int main() {
    arrayList arr(100);
    arr.insertAt(0, 10);
    arr.insertAt(1, 20);
    arr.insertAtEnd(30);
    arr.insertNoDuplicate(40);
    arr.updateAt(0, 5);
    cout << arr.getElement(1) << endl;
    cout << arr.getSize() << endl;
    arr.print();
    return 0;
}
