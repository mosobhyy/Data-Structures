#include <iostream>
#include <limits>

using namespace std;

template<class T>
class MyList
{
public:
    int length, itsSize;
    T *elems;

    int getSize()
    {
        return itsSize;
    }

    virtual void addElem(T element) = 0;

    virtual T getElem() = 0;

    virtual bool isEmpty() = 0;

    virtual bool isFull() = 0;

    virtual void clearItems() = 0;

    virtual void print() = 0;

    MyList()
    {
        length = 0;
        itsSize = 1;
        elems = new T[itsSize];
    }

    ~MyList()
    {
        delete[] elems;
    }
};

template<class T>
class MyStack : public MyList<T>
{
    int top;

public:

    void addElem(T element)
    {
        if (isFull())
        {
            T *newElems = new T[this->itsSize + 1];
            for (int i = 0; i < this->itsSize; i++)
                newElems[i] = this->elems[i];
            delete[] this->elems;
            this->elems = newElems;
            this->itsSize++;
        }
        this->elems[++top] = element;
        this->length++;
    }


    T getElem()
    {
        this->length--;
        return this->elems[top--];
    }


    bool isEmpty()
    {
        return top < 0;
    }


    bool isFull()
    {
        return top == this->itsSize - 1;
    }


    void clearItems()
    {
        top = -1;
    }


    void print()
    {
        cout << "All Elements\n";
        while (this->length != 0)
            cout << "Element-->" << this->getElem() << endl;
    }


    MyStack() : MyList<T>()
    {
        top = -1;
    }
};

template<class T>
class MyQueue : public MyList<T>
{
    int front, rear;

public:

    void addElem(T element)
    {
        if (isFull())
        {
            T *newElems = new T[this->itsSize + 1];
            for (int i = 0; i < this->itsSize; i++)
                newElems[i] = this->elems[i];
            delete[] this->elems;
            this->elems = newElems;
            this->itsSize++;
        }

        if (isEmpty())
            front = (front + 1) % this->itsSize;

        rear = (rear + 1) % this->itsSize;
        this->elems[rear] = element;
        this->length++;
    }

    T getElem()
    {
        T element = this->elems[front];
        front = (front + 1) % this->itsSize;
        this->length--;
        return element;
    }

    bool isEmpty()
    {
        return this->length == 0;
    }


    bool isFull()
    {
        return this->length == this->itsSize;
    }


    void clearItems()
    {
        front = rear = -1;
        this->length = 0;
    }


    void print()
    {
        cout << "All Elements\n";
        while (front != rear)
            cout << "Element-->" << this->getElem() << endl;
        cout << "Element-->" << this->getElem() << endl;
    }

    MyQueue() : MyList<T>()
    {
        front = rear = -1;
    }
};

class Rectangle
{
    int length;
    int width;
public:

    class rectangleException
    {
    };

    Rectangle()
    {
        length = width = 0;
    }

    Rectangle(int length, int width)
    {
        if (length < 0 || width < 0)
        {
            this->length = this->width = 0;
            throw rectangleException();
        }
        this->length = length;
        this->width = width;
    }

    int getLength() const
    {
        return length;
    }

    int getWidth() const
    {
        return width;
    }

    int getArea() const
    {
        return length * width;
    }

    friend ostream &operator<<(ostream &out, const Rectangle &rectangle);
};

int main()
{
    char type = ' ';
    int dataType = 0;
    while (type != 's' && type != 'S' && type != 'q' && type != 'Q')
    {
        cout << "Would you like to use a stack or queue (S/Q)?\n";
        cin >> type;
    }
    while (dataType < 1 || dataType > 3)
    {
        cout << "Would you like to store integers, strings, or rectangles (1,2, or 3)?\n";
        cin >> dataType;
    }
    if (type == 's' || type == 'S')
    {
        if (dataType == 1)
        {
            MyStack<int> myStack;
            char yORn = ' ';
            int num;
            while (yORn == 'y' || yORn == 'Y' || yORn == ' ')
            {
                cout << "Enter num:";
                try
                {
                    cin >> num;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        num = 0;
                        throw "Wrong String Input-->will enter 0\n";
                    }
                }
                catch (const char *str)
                {
                    cout << str;
                }
                myStack.addElem(num);
                yORn = ' ';
                while (yORn != 'y' && yORn != 'Y' && yORn != 'n' && yORn != 'N')
                {
                    cout << "Would you like to enter another elem?(y/n)\n";
                    cin >> yORn;
                }
            }
            myStack.print();
        }

        else if (dataType == 2)
        {
            MyStack<string> myStack;
            char yORn = ' ';
            string num;
            while (yORn == 'y' || yORn == 'Y' || yORn == ' ')
            {
                cout << "Enter num:";
                cin >> num;
                myStack.addElem(num);
                yORn = ' ';
                while (yORn != 'y' && yORn != 'Y' && yORn != 'n' && yORn != 'N')
                {
                    cout << "Would you like to enter another elem?(y/n)\n";
                    cin >> yORn;
                }
            }
            myStack.print();
        }

        else if (dataType == 3)
        {
            MyStack<Rectangle> myStack;
            char yORn = ' ';
            int length, width;
            Rectangle *rectangle;
            while (yORn == 'y' || yORn == 'Y' || yORn == ' ')
            {
                cout << "Enter length and width space separated:";
                try
                {
                    cin >> length >> width;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        length = width = -1;
                    }
                    rectangle = new Rectangle(length, width);
                }
                catch (Rectangle::rectangleException)
                {
                    rectangle = new Rectangle(0, 0);
                    cout << "wrong length or width entering 0 and 0\n";
                }
                myStack.addElem(*rectangle);
                yORn = ' ';
                while (yORn != 'y' && yORn != 'Y' && yORn != 'n' && yORn != 'N')
                {
                    cout << "Would you like to enter another elem?(y/n)\n";
                    cin >> yORn;
                }
            }
            myStack.print();
        }
    }
    else if (type == 'q' || type == 'Q')
    {
        if (dataType == 1)
        {
            MyQueue<int> myQueue;
            char yORn = ' ';
            int num;
            while (yORn == 'y' || yORn == 'Y' || yORn == ' ')
            {
                cout << "Enter num:";
                try
                {
                    cin >> num;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        num = 0;
                        throw "Wrong String Input-->will enter 0\n";
                    }
                }
                catch (const char *str)
                {
                    cout << str;
                }
                myQueue.addElem(num);
                yORn = ' ';
                while (yORn != 'y' && yORn != 'Y' && yORn != 'n' && yORn != 'N')
                {
                    cout << "Would you like to enter another elem?(y/n)\n";
                    cin >> yORn;
                }
            }
            myQueue.print();
        }

        else if (dataType == 2)
        {
            MyQueue<string> myQueue;
            char yORn = ' ';
            string num;
            while (yORn == 'y' || yORn == 'Y' || yORn == ' ')
            {
                cout << "Enter num:";
                cin >> num;
                myQueue.addElem(num);
                yORn = ' ';
                while (yORn != 'y' && yORn != 'Y' && yORn != 'n' && yORn != 'N')
                {
                    cout << "Would you like to enter another elem?(y/n)\n";
                    cin >> yORn;
                }
            }
            myQueue.print();
        }

        else if (dataType == 3)
        {
            MyQueue<Rectangle> myQueue;
            char yORn = ' ';
            int length, width;
            Rectangle *rectangle;
            while (yORn == 'y' || yORn == 'Y' || yORn == ' ')
            {
                cout << "Enter length and width space separated:";
                try
                {
                    cin >> length >> width;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        length = width = -1;
                    }
                    rectangle = new Rectangle(length, width);
                }
                catch (Rectangle::rectangleException)
                {
                    rectangle = new Rectangle(0, 0);
                    cout << "wrong length or width entering 0 and 0\n";
                }
                myQueue.addElem(*rectangle);
                yORn = ' ';
                while (yORn != 'y' && yORn != 'Y' && yORn != 'n' && yORn != 'N')
                {
                    cout << "Would you like to enter another elem?(y/n)\n";
                    cin >> yORn;
                }
            }
            myQueue.print();
        }
    }
    return 0;
}

ostream &operator<<(ostream &out, const Rectangle &rectangle)
{
    out << "Length=" << rectangle.length << ",Width=" << rectangle.width << ",Area=" << rectangle.getArea();
    out << endl;
    return out;
}