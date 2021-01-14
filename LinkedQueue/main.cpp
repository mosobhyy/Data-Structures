#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
//    q.dequeue();
//    q.dequeue();
//    q.dequeue();
//    q.dequeue();
//    q.dequeue();
//    cout << q.getFront() << endl;
//    cout << q.getRear() << endl;
//    cout << q.getSize();
//    cout << q.getRear() << endl;
    q.print();
    return 0;
}
