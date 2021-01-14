//
// Created by Muhmd on 4/30/2020.
//

#include "BSTNode.h"

template<class type>
type BSTNode<type>::getData() const
{
    return data;
}

template<class type>
void BSTNode<type>::setData(type data)
{
    BSTNode::data = data;
}

template<class type>
BSTNode<type> *BSTNode<type>::getRight() const
{
    return right;
}

template<class type>
void BSTNode<type>::setRight(BSTNode *right)
{
    BSTNode::right = right;
}

template<class type>
BSTNode<type> *BSTNode<type>::getLeft() const
{
    return left;
}

template<class type>
void BSTNode<type>::setLeft(BSTNode *left)
{
    BSTNode::left = left;
}

template<class type>
BSTNode<type>::BSTNode()
{
    right = left = nullptr;
}

template<class type>
BSTNode<type>::BSTNode(type data)
{
    BSTNode::data = data;
    right = left = nullptr;
}
