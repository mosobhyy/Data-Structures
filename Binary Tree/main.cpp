#include <iostream>
#include "Tree.h"

using namespace std;


int main()
{
    string expression = "+3*4/82";
    Tree<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(2);
    t.insert(1);
    t.insert(4);
    t.insert(7);
    t.insert(9);
    t.insert(8);
    t.insert(10);
//    t.erase(10);
    t.preOrder();
    return 0;
}
