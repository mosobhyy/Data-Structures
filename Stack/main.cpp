#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> s;
    cout << s.isEmpty();
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    cout << s.isEmpty();
    return 0;
}
