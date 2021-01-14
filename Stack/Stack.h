//
// Created by Muhmd on 4/3/2020.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

using namespace std;

int maxSize = 100;
template <class T>
class Stack {
private:
    T arr[100];
    int top;
public:

     /* Methods */

     bool isEmpty()
     {
         return top < 0;
     }

    void push(int element)
    {
         if(top==maxSize-1)
             cout << "Stack is full on push\n";
         else {
             top++;
             arr[top] = element;
         }
    }

    void pop()
    {
         if(isEmpty())
             cout << "Stack is empty on pop\n";
         else
             top--;
    }

    void pop(T &element)
    {
        if(isEmpty())
            cout << "Stack is empty on pop\n";
        else {
            element = arr[top];
            top--;
        }
    }

    void getTop()
    {
         if(isEmpty())
             cout << "Stack is empty\n";
        else
            cout << arr[top];
    }

    void print()
    {
         cout << "[ ";
         for(int i=top ; i>=0 ; i--)
             cout << arr[i] << " ";
         cout << "]\n";
    }

    /* Constructor */

    Stack()
    {
        top = -1;
    }

};


#endif //STACK_STACK_H
