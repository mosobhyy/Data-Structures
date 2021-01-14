//
// Created by Muhmd on 4/15/2020.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
using namespace std;

class LinkedList
{
private:
    struct node
    {
        int item;
        node* next;
    };

    node *front, *rear;
    int length;
public:

    bool isEmpty()
    {
        return length == 0;
    }

    void insertFront(int element)
    {
        node *temp = new node;
        temp->item = element;
        temp->next = NULL;
        if(isEmpty())
            front = rear = temp;
        else
        {
            temp->next = front;
            front = temp;
        }
        temp = NULL;
        length++;
    }

    void insertBack(int element)
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
        temp = NULL;
        length++;
    }

    void insertAt(int index, int element)
    {
        if(index<0 || index>length)
            cout << "Out Of Range...!\n";
        else if (index==0)
            insertFront(element);
        else if (index==length)
             insertBack(element);
        else
        {
            node *newNode = new node;
            newNode->item = element;
            node *temp = front;
            for(size_t i=1 ; i<index ; i++)
                temp = temp->next;
                newNode->next = temp->next;
            temp->next = newNode;
            length++;
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

    void removeFront()
    {
        if(isEmpty())
            cout << "List Is Empty...!\n";
        else if(length==1)
        {
            delete front;
            front = rear = NULL;
            length--;
        }
        else
        {
            node *temp = front;
            front = front->next;
            delete temp;
            length--;
        }
    }

    void removeBack()
    {
        if(isEmpty())
            cout << "List Is Empty...!\n";
        else if(length==1)
        {
            delete front;
            front = rear = NULL;
            length--;
        }
        else
        {
            node *newRear = front;
            node *temp = front->next;
            while (temp!=rear)
            {
                newRear = temp;
                temp = temp->next;
            }
            delete temp;
            newRear->next = NULL;
            rear = newRear;
            length--;
        }
    }

    void remove(int element)
    {
        if(isEmpty())
            cout << "List Is Empty...!\n";
        else if(front->item == element)
            removeFront();
        else
        {
            node *ptr = front;
            node *temp = front->next;
            while (temp!=NULL && temp->item!=element)
            {
                ptr = temp;
                temp = temp->next;
            }
            if(temp==NULL)
                cout << "Not Found...!\n";
            else if(temp==rear)
                removeBack();
            else
            {
                ptr->next = temp->next;
                delete temp;
                length--;
            }
        }
    }

    void removeAt(int index)
    {
        if(isEmpty())
            cout << "List Is Empty...!\n";
        if(index<0 || index>=length)
            cout << "Out Of Range...!\n";
        else if (index==0)
            removeFront();
        else if (index==length-1)
            removeBack();
        else
        {
            node *ptr = front;
            node *temp = front->next;
            for (size_t i = 1; i<index ; i++)
            {
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = temp->next;
            delete temp;
            length--;
        }
    }

    void reverse()
    {
        if(isEmpty())
            cout << "List Is Empty...!\n";
        else
        {
            node *previous = NULL, *current = front, *next = front;
            while(next!=NULL)
            {
                next = next->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            front = previous;
        }
    }

    int search(int element)
    {
        int index=0;
        node *temp = front;
        while(temp!=NULL)
        {
            if(temp->item==element)
                return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void print()
    {
        node *temp = front;
        while(temp!=NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
    }

    LinkedList()
    {
        front = rear = NULL;
        length=0;
    }
};


#endif //LINKEDLIST_LINKEDLIST_H
