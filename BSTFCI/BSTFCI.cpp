//
// Created by Muhmd on 4/30/2020.
//

#include "BSTFCI.h"

/*      Private Methods     */

/*     Max() & height() Functions used in isBalance Function    */

template<class type>
int BSTFCI<type>::max(int x, int y)
{
    return (x >= y) ? x : y;
}

template<class type>
int BSTFCI<type>::height(BSTNode<type> *ptr)      /*      Compute height for every node       */
{
    if (!ptr)
        return 0;
    return 1 + max(height(ptr->left), height(ptr->right));
}

/*     search() & compareSubTree() Functions used in isSubTree() Function    */

template<class type>
BSTNode<type> *BSTFCI<type>::search(type value)
{
    {
        BSTNode<type> *temp = root;
        while (temp != nullptr && value != temp->getData())
        {
            if (value > temp->getData())
                temp = temp->getRight();
            else
                temp = temp->getLeft();
        }
        return temp;
    }
}

template<class type>
bool BSTFCI<type>::compareSubTree(BSTNode<type> *t1, BSTNode<type> *t2)
{
    if (!t1 && t2)
        return 0;

    if (!t1 || !t2)
        return 1;

    if (t1->getData() == t2->getData() && compareSubTree(t1->getLeft(), t2->getLeft()) &&
        compareSubTree(t1->getRight(), t2->getRight()))
        return 1;

    return 0;
}

template<class type>
bool BSTFCI<type>::isSubTree(BSTNode<type> *t2)
{
    BSTNode<type> *found = search(t2->getData());
    if (found)
        return compareSubTree(found, t2);
    return 0;
}

/*     printRange() Function used in printRange() Function    */

template<class type>
void BSTFCI<type>::printRange(BSTNode<type> *ptr, type start, type end)
{
    if (!ptr)
        return;

    if (ptr->getData() > start)
        printRange(ptr->getLeft(), start, end);

    if (ptr->getData() >= start && ptr->getData() <= end)
        cout << ptr->getData() << " ";

    printRange(ptr->getRight(), start, end);
}

template<class type>
void BSTFCI<type>::flip(BSTNode<type> *&ptr)
{
    BSTNode<type> *right = ptr->getRight();
    BSTNode<type> *left = ptr->getLeft();
    ptr->setRight(left);
    ptr->setLeft(right);
}

template<class type>
void BSTFCI<type>::preOrder(BSTNode<type> *ptr)       /*      Print: Root Left Right      */
{
    if (!ptr)
        return;
    cout << ptr->getData() << " " << endl;
    preOrder(ptr->getLeft());
    preOrder(ptr->getRight());
}

template<class type>
void BSTFCI<type>::inOrder(BSTNode<type> *ptr)        /*      Print: Left Root Right      */
{
    if (!ptr)
        return;
    inOrder(ptr->getLeft());
    cout << ptr->getData() << " " << endl;
    inOrder(ptr->getRight());
}

template<class type>
void BSTFCI<type>::postOrder(BSTNode<type> *ptr)      /*      Print: Left Right Root      */
{
    if (!ptr)
        return;
    postOrder(ptr->getLeft());
    postOrder(ptr->getRight());
    cout << ptr->getData() << " " << endl;
}


/*      Public Methods      */


template<class type>
BSTNode<type> *BSTFCI<type>::getRoot() const
{
    return root;
}

template<class type>
void BSTFCI<type>::insert(type value)
{
    BSTNode<type> *newNode = new BSTNode<type>;
    newNode->setData(value);
    newNode->setLeft(nullptr);
    newNode->setRight(nullptr);
    if (!root)
        root = newNode;
    else
    {
        BSTNode<type> *temp = root;
        while (true)
        {
            if ((value > temp->getData() && !temp->getRight()) || (value <= temp->getData() && !temp->getLeft()))
                break;
            if (value > temp->getData())
                temp = (temp->getRight());
            else
                temp = (temp->getLeft());
        }

        if (value > temp->getData())
            temp->setRight(newNode);
        else
            temp->setLeft(newNode);
    }
}

template<class type>
bool BSTFCI<type>::isBalance(BSTNode<type> *ptr)
{
    if (!root)
        return 1;
    return abs(height(ptr->left) - height(ptr->right)) <= 1 && isBalance(ptr->left) && isBalance(ptr->right);
}

template<class type>
void BSTFCI<type>::printRange(type start, type end)
{
    return printRange(root, start, end);
}

template<class type>
void BSTFCI<type>::flip()
{
    return flip(root);
}

template<class type>
int BSTFCI<type>::digitSum(BSTNode<int> *ptr, int value)
{
    if(!ptr)
        return 0;
    value = (value*10) + ptr->getData();
    if(!ptr->getRight() && !ptr->getLeft())
        return value;
    return digitSum(ptr->getLeft(), value) + digitSum(ptr->getRight(), value) ;
}

template<class type>
void BSTFCI<type>::preOrder()
{
    preOrder(root);
}

template<class type>
void BSTFCI<type>::inOrder()
{
    return inOrder(root);
}

template<class type>
void BSTFCI<type>::postOrder()
{
    return postOrder(root);
}


template<class type>
BSTFCI<type>::BSTFCI()
{
    root = nullptr;
}
