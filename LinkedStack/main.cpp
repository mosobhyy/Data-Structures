#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.pop();
    s.print();
    s.getTop();
    return 0;
}
