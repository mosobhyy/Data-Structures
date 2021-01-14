//
// Created by Muhmd on 4/4/2020.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <cassert>
using namespace std;

template <class T>
class Queue {
private:

    /* Attributes */

    int front, rear, length, maxSize;
    T *arr;


public:

    /* Methods */

    bool isEmpty()
    {
        return length==0;
    }

    bool isFull()
    {
        return length==maxSize;
    }

    void enqueue(T element)
    {
        if(isFull())
            cout << "Queue Is Full Can't Enqueue...!\n";
        else
        {
            rear = (rear+1) % maxSize;
            arr[rear] = element;
            length++;
        }
    }

    void dequeue()
    {
        if(isEmpty())
            cout << "Queue Is Empty can't Dequeue...!\n";
        else
        {
            front = (front+1) % maxSize;
            length--;
        }
    }

    T getFront()
    {
        assert(!isEmpty());
        return arr[front];
    }

    T getRear()
    {
        assert(!isEmpty());
        return arr[rear];
    }

    int getSize()
    {
        return length;
    }

    void print()
    {
        if(isEmpty())
            cout << "Queue Is Empty...!\n";
        else
        {
            cout << "Queue Elements: [";
            int i = front -1;
            do
            {
                i = (i + 1) % maxSize;
                cout << arr[i] << " ";
            }
            while (i != rear);
            cout << "]\n";
        }
    }

    int search(T element)
    {
        int index = -1;
        if(isEmpty())
            cout << "Queue Is Empty...!\n";
        else
        {
            int i = front - 1;
            do
            {
                i = (i + 1) % maxSize;
                if (arr[i] == element) {
                    index = i;
                    break;
                }
            }
            while (i != rear);
        }
        return index;
    }

    /* Constructor */

    Queue(int size)
    {
        maxSize = size;
        arr = new T[maxSize];
        front = 0;
        rear = maxSize-1;
        length = 0;
    }
};


#endif //QUEUE_QUEUE_H
