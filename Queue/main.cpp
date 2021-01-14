#include <iostream>
#include "Queue.h"
using namespace std;
int main() {
    Queue<char> q(5);
    q.enqueue('A');
    q.enqueue('B');
    q.enqueue('C');
    q.enqueue('D');
    q.enqueue('E');
    q.print();
    return 0;
}
