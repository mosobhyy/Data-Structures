//
// Created by Muhmd on 4/30/2020.
//

#ifndef BSTFCI_BSTNODE_H
#define BSTFCI_BSTNODE_H

#include <iostream>

using namespace std;

template<class type>
class BSTNode
{
private:
    type data;
    BSTNode *right;
    BSTNode *left;

public:
    type getData() const;

    void setData(type data);

    BSTNode *getRight() const;

    void setRight(BSTNode *right);

    BSTNode *getLeft() const;

    void setLeft(BSTNode *left);

    BSTNode();

    BSTNode(type data);

};


#endif //BSTFCI_BSTNODE_H
