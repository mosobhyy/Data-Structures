#include <iostream>
#include "BSTFCI.cpp"

template<class type>
bool isSubTree(BSTFCI<type> t1, BSTFCI<type> t2);

//bool isOperator(char element)
//{
//    return element == '*' || element == '/' || element == '+' || element == '-';
//}
//
//int start = 0;
//
//void buildTree(BSTNode<char> *ptr, string exp)
//{
//    if (start == 7)
//        return;
//    BSTNode<char> *newNode = new BSTNode<char>;
//    newNode->setData(exp[start]);
//    ptr = newNode;
//    start++;
//    if (isOperator(ptr->getData()))
//    {
//        buildTree(ptr->getLeft(), exp);
//        buildTree(ptr->getRight(), exp);
//    }
//    else
//        return;
//}
//
//BSTNode<char> *buildTree(string exp)
//{
//    BSTNode<char> *temp = new BSTNode<char>;
//    buildTree(temp, exp);
//    return temp;
//}

int max(int x, int y);

void largestValues(BSTNode<int> *ptr, int arr[], int index);

int *largestValues(BSTFCI<int> t);

int digitSum(BSTFCI<int> t);


int main()
{
    return 0;
}

template<class type>
bool isSubTree(BSTFCI<type> t1, BSTFCI<type> t2)
{
    return t1.isSubTree(t2.getRoot());
};

int max(int x, int y)
{
    return x >= y ? x : y;
}

void largestValues(BSTNode<int> *ptr, int arr[], int index)
{
    if (!ptr || (!ptr->getLeft() && !ptr->getRight()))
        return;
    if (!ptr->getLeft())
        arr[index++] = ptr->getRight()->getData();
    if (!ptr->getRight())
        arr[index++] = ptr->getLeft()->getData();
    if (ptr->getLeft() && ptr->getRight())
    {
        int left = ptr->getLeft()->getData();
        int right = ptr->getRight()->getData();
        arr[index++] = max(left, right);
    }
    largestValues(ptr->getLeft(), arr, index);
    largestValues(ptr->getRight(), arr, index);
}

int *largestValues(BSTFCI<int> t)
{
    static int arr[5] = {t.getRoot()->getData()};
    largestValues(t.getRoot(), arr, 1);

    return arr;
}


int digitSum(BSTFCI<int> t)
{
    return t.digitSum(t.getRoot(), 0);
}