//
// Created by Muhmd on 4/16/2020.
//

#ifndef DOUBLY_LINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLY_LINKEDLIST_DOUBLYLINKEDLIST_H
using namespace std;

template<class type>
class DoublyLinkedList
{
private:
    struct node
    {
        type item;
        node *next;
        node *previous;
    };
    node *front;
    node *rear;
    int length;

public:

    bool isEmpty()
    {
        return front == NULL;
    }

    void insertFront(type element)
    {
        node *temp = new node;
        temp->item = element;
        temp->previous = NULL;
        if (isEmpty())
        {
            temp->next = NULL;
            front = rear = temp;
        }
        else
        {
            temp->next = front;
            front->previous = temp;
            front = temp;
        }
        length++;
    }

    void insertBack(type element)
    {
        node *temp = new node;
        temp->item = element;
        temp->next = NULL;
        if (isEmpty())
        {
            temp->previous = NULL;
            front = rear = temp;
        }
        else
        {
            temp->previous = rear;
            rear->next = temp;
            rear = temp;
        }
        length++;
    }

    void insertAt(int index, type element)
    {
        if (index < 0 || index > length)
            cout << "Out Of Range...!\n";
        else if (index == 0)
            insertFront(element);
        else if (index == length)
            insertBack(element);
        else
        {
            node *newNode = new node;
            node *prevPtr = front;
            node *nextPtr = front->next;
            newNode->item = element;
            for (size_t i = 1; i < index; i++)
            {
                prevPtr = nextPtr;
                nextPtr = nextPtr->next;
            }
            newNode->next = nextPtr;
            newNode->previous = prevPtr;
            prevPtr->next = newNode;
            nextPtr->previous = newNode;
            length++;
        }
    }

    void removeFront()
    {
        if (isEmpty())
            cout << "List Is Empty...!\n";
        else if (length == 1)
        {
            delete front;
            front = rear = NULL;
            length--;
        }
        else
        {
            node *temp = front;
            front = front->next;
            front->previous = NULL;
            delete temp;
            length--;
        }
    }

    void removeBack()
    {
        if (isEmpty())
            cout << "List Is Empty...!\n";
        else if (length == 1)
        {
            delete front;
            front = rear = NULL;
            length--;
        }
        else
        {
            node *temp = rear;
            rear = rear->previous;
            rear->next = NULL;
            delete temp;
            length--;
        }
    }

    void remove(type element)
    {
        if (front->item == element)
            removeFront();
        else if (rear->item == element)
            removeBack();
        else
        {
            node *temp = front->next;
            while (temp != NULL && temp->item != element)
                temp = temp->next;
            if (temp == NULL)
                cout << "Not Found...!\n";
            else
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                delete temp;
                length--;
            }
        }
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= length)
            cout << "Out Of Range...!\n";
        else if (index == 0)
            removeFront();
        else if (index == length - 1)
            removeBack();
        else
        {
            node *temp = front->next;
            for (size_t i = 1; i < index; i++)
                temp = temp->next;
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            delete temp;
        }
    }

    int getFront()
    {
        return front->item;
    }

    int getRear()
    {
        return rear->item;
    }

    int getSize()
    {
        return length;
    }

    node* begin()
    {
        return front;
    }

    node* end()
    {
        return rear->next;
    }

    void print()
    {
        cout << "Elements List...\n";
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse()
    {
        cout << "Elements List As Reverse...\n";
        node *temp = rear;
        while (temp != NULL)
        {
            cout << temp << " ";
            temp = temp->previous;
        }
        cout << endl;
    }

    DoublyLinkedList()
    {
        front = rear = NULL;
        length = 0;
    }

    ~DoublyLinkedList()
    {
        node *temp = new node;
        while (front != NULL)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        length = 0;
    }

};

#endif //DOUBLY_LINKEDLIST_DOUBLYLINKEDLIST_H
