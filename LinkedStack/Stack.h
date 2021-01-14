//
// Created by Muhmd on 4/4/2020.
//

#ifndef LINKEDSTACK_STACK_H
#define STACK_STACK_H
using namespace std;

template<class T>
class Stack
{

private:

    struct node
    {
        T item;
        node *next;
    };
    node *top;

public:

    /* Methods */

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(T element)
    {
        node *newItemPtr = new node;
        newItemPtr->item = element;
        newItemPtr->next = top;
        top = newItemPtr;
    }

    void pop()
    {
        if (isEmpty())
            cout << "Stack empty on pop\n";
        else
        {
            /* initialize "temp" to delete the data from memory (not just ignore it) */
            node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void pop(T *element)
    {
        if (isEmpty())
            cout << "Stack empty on pop\n";
        else
        {
            element = top->item;
            node *temp = top;
            temp = temp->next = NULL;
            delete temp;
            top = top->next;
        }
    }

    void getTop()
    {
        if (isEmpty())
            cout << "Stack empty on getTop\n";
        else
        {
            cout << top->item;
        }
    }

    void print()
    {
        if (isEmpty())
            cout << "Stack empty on display\n";
        else
        {
            node *temp = top;
            cout << "Items in the stack: [";
            while (temp != NULL)
            {
                cout << temp->item << " ";
                temp = temp->next;
            }
            cout << "]\n";
        }
    }

    /* Constructor */

    Stack()
    {
        top = NULL;
    }

};


#endif //STACK_STACK_H
