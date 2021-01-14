//
// Created by Muhmd on 4/5/2020.
//

#ifndef LINKEDQUEUE_QUEUE_H
#define QUEUE_QUEUE_H
using namespace std;

template <class T>
class Queue {
private:

    struct node
    {
        T item;
        node *next;
    };
    node *front, *rear;
    int length;

public:

    bool isEmpty()
    {
        return rear == NULL;
    }

    void enqueue(T element)
    {
        node *temp = new node;
        temp->item = element;
        temp->next = NULL;
        if(isEmpty())
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
        length++;
    }

    void dequeue()
    {
        if(isEmpty())
            cout << "Empty Queue Cannot Dequeue...!\n";
        else
        {
            if(front == rear)
                front = rear = NULL;
            else
            {
                node *temp = front;
                front = front->next;
                delete temp;
            }
            length--;
        }
    }

    T getFront()
    {
        if(isEmpty())
        {
            cout << "Queue Is Empty On getFront...!\n";
            return 0;
        }
        return front->item;
    }

    T getRear()
    {
        if(isEmpty())
        {
            cout << "Queue Is Empty On getRear...!\n";
            return 0;
        }
        return rear->item;
    }

    int getSize()
    {
        return length;
    }

    void print()
    {
        if (isEmpty())
            cout << "Queue Is Empty On Print...!\n";
        else
        {
            node *temp = front;
            cout << "Queue Elements: [";
            for (size_t i = 0; i < length; i++)
            {
                cout << temp->item << " ";
                temp = temp->next;
            }
            cout << "]\n";
        }
    }

    int search(T element)
    {
        if (isEmpty())
            cout << "Queue Is Empty On Search...!\n";
        else
        {
            node *temp = front;
            for (size_t i = 0; i < length; i++)
             {
                if (temp->item == element)
                    return temp->item;
                temp = temp->next;
            }
        }
    }

    void clear()
    {
        node *temp;
        while (front!=NULL)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        length = 0;
    }

    Queue()
    {
        front = NULL;
        rear = NULL;
        length =0;
    }
};


#endif //QUEUE_QUEUE_H
