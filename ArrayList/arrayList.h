//
// Created by Muhmd on 4/15/2020.
//

#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <iostream>
using namespace std;

class arrayList {
private:
    int *arr, maxSize, length;
public:

    bool isEmpty()
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == maxSize;
    }

    int getSize()
    {
        return length;
    }

    void insertAt(int index, int element)
    {
        if(isFull())
            cout << "List is Full...!\n";
        else if (index<0 || index>length)
            cout << "Out Of Range...!\n";
        else
        {
            for (size_t i=length ; i>index ; i--)
                arr[i] = arr[i-1];
            arr[index] = element;
            length++;
        }
    }

    void insertAtEnd(int element)
    {
        if(isFull())
            cout << "List is Full...!\n";
        else
        {
            arr[length] = element;
            length++;
        }
    }

    void insertNoDuplicate(int element)
    {
        if(search(element)==-1)
            insertAtEnd(element);
        else
            cout << "The element is already exist...!\n";
    }

    void removeAt(int index)
    {
        if(isEmpty())
            cout << "List is Empty...!\n";
        else if (index<0 || index>=length)
            cout << "Out Of Range...!\n";
        else
        {
            for (size_t i=index ; i<length-1 ; i++)
                arr[i] = arr[i+1];
            length--;
        }
    }

    int search(int element)
    {
        for (size_t i=0 ; i<length ; i++)
            if(arr[i] == element)
                return i;
        return -1;
    }

    void updateAt(int index, int element)
    {
        if(index<0 || index>=length)
            cout << "Out Of Range...!\n";
        else
        arr[index] = element;
    }

    int getElement(int index)
    {
        if(index<0 || index>=length)
            cout << "Out Of Range...!\n";
        else
            return arr[index];
    }

    void clear()
    {
        length = 0;
    }

    void print()
    {
        for(size_t i=0 ; i<length ; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    arrayList(int size=10)
    {
        arr = new int[size];
        maxSize = size;
        length = 0;
    }

    ~arrayList()
    {
        delete[]arr;
    }
};


#endif //ARRAYLIST_ARRAYLIST_H
