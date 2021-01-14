//
// Created by Muhmd on 4/30/2020.
//

#ifndef BSTFCI_BSTFCI_H
#define BSTFCI_BSTFCI_H

#include "BSTNode.cpp"

template<class type>
class BSTFCI
{
private:

    /*      Attributes      */

    BSTNode<type> *root;

    /*      Private Methods     */


    /*     Max() & height() Functions used in isBalance Function    */

    int max(int x, int y);

    int height(BSTNode<type> *ptr);

    /*     search() & compareSubTree() Functions used in isSubTree Function    */

    BSTNode<type> *search(type value);

    bool compareSubTree(BSTNode<type> *t1, BSTNode<type> *t2);

    /*     isSubTree() Function used in Function in main    */

    bool isSubTree(BSTNode<type> *t2);

    /*     printRange() Function used in printRange() Function    */

    void printRange(BSTNode<type> *ptr, type start, type end);

    void flip(BSTNode<type>* &ptr);

    /*     digitSum() Function used in digitSum() Function in main    */

    int digitSum(BSTNode<int> *ptr, int value);

    void preOrder(BSTNode<type> *ptr);

    void inOrder(BSTNode<type> *ptr);

    void postOrder(BSTNode<type> *ptr);

public:

    /*      Public Methods      */

    BSTNode<type> *getRoot() const;

    void insert(type value);

    bool isBalance(BSTNode<type> *ptr);

    void printRange(type start, type end);

    void flip();

    void preOrder();

    void inOrder();

    void postOrder();

    template <class t>
    friend bool isSubTree(BSTFCI<t> t1, BSTFCI<t> t2);

    friend int digitSum(BSTFCI<int> t);

    BSTFCI();
};


#endif //BSTFCI_BSTFCI_H
