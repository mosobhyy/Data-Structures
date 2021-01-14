//
// Created by Muhmd on 4/23/2020.
//

#ifndef BINARY_TREE_TREE_H
#define BINARY_TREE_TREE_H

#include <iostream>
#include <vector>

using namespace std;

template<class type>
class Tree
{
private:

    struct node
    {
        type data;
        node *right;
        node *left;
    };

    node *found(type value, node *(&ptr))
    {
        node *previous = nullptr;
        node *current = root;
        while (current && value != current->data)
        {
            previous = current;
            if (value > current->data)
                current = current->right;
            else
                current = current->left;
        }
        ptr = previous;
        return current;
    }

    node *min(node *tree)
    {
        node *temp = tree;
        while (temp->left)
            temp = temp->left;
        return temp;
    }

    node *max(node *tree)
    {
        node *temp = tree;
        while (temp->right != nullptr)
            temp = temp->right;
        return temp;
    }

    void preOrder(node *ptr)
    {
        if (ptr)
        {
            cout << ptr->data << endl;
            preOrder(ptr->left);
            preOrder(ptr->right);
        }
    }

public:

    int start;
    node *root;

    bool flag = true;

    bool isEmpty()
    {
        return root == nullptr;
    }

    void insert(type value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (isEmpty())
            root = newNode;
        else
        {
            node *temp = root;
            while (true)
            {
                if ((value > temp->data && !temp->right) || (value <= temp->data && !temp->left))
                    break;
                else if (value > temp->data)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            if (value > temp->data)
                temp->right = newNode;
            else
                temp->left = newNode;
        }
    }

    void erase(type value)
    {
        node *previous;
        node *current = found(value, previous);
        if (!current)
        {
            cout << "Element Not Found...!\n";
            return;
        }
        else if (!current->right && !current->left)     // Leaf
        {
            if (previous->right == current)
                previous->right = nullptr;
            else
                previous->left = nullptr;
            delete current;
        }
        else if (!current->right && current->left)
        {
            previous->left = current->left;
            delete current;
        }
        else if (current->right && !current->left)
        {
            previous->right = current->right;
            delete current;
        }
        else
        {
            node *temp = current->right;
            if (!temp->left)
                current->right = nullptr;
            else
            {
                while (temp->left)
                {
                    previous = temp;
                    temp = temp->left;
                }
                previous->left = nullptr;
            }
            current->data = temp->data;
            delete temp;
        }
        cout << "Element Deleted Successfully...\n";
    }

    node *search(type value)
    {
        node *temp = root;
        while (temp != nullptr && value != temp->data)
        {
            if (value > temp->data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return temp;
    }

    bool isBalance(node *ptr)
    {
        if (!ptr)
            return 1;
        int right = height(ptr->right);
        int left = height(ptr->left);
        if (abs(right - left) <= 1 && isBalance(ptr->right) && isBalance(ptr->left))
            return 1;
        return 0;
    }

    int max(int x, int y)
    {
        return (x >= y) ? x : y;
    }

    int height(node *ptr)
    {
        if (!ptr)
            return 0;
        return 1 + max(height(ptr->left), height(ptr->right));
    }

    bool isSubTree(node *t2)
    {
        node *original = search(t2->data);
        if (original)
            return subTree(original, t2);
        return 0;
    }

    bool subTree(node *t1, node *t2)
    {
        if (!t1 && t2)
            return 0;

        if (!t1 || !t2)
            return 1;

        if (t1->data == t2->data && subTree(t1->left, t2->left) && subTree(t1->right, t2->right))
            return 1;

        return 0;
    }

    void range(node *ptr, type start, type end)
    {
        if (!ptr)
            return;

        if (ptr->data > start)
            range(ptr->left, start, end);

        if (ptr->data >= start && ptr->data <= end)
            cout << ptr->data << " ";

        range(ptr->right, start, end);
    }

    void flip()
    {
        flip(root);
    }

    void flip(node* &ptr)
    {
        node* right = ptr->right;
        node* left = ptr->left;
        ptr->right = left;
        ptr->left = right;
    }

    void min()
    {
        if (isEmpty())
            cout << "Tree Is Empty...\n";
        else
        {
            cout << "Minimum Element In Tree: " << min(root)->data << endl;
        }
    }

    void max()
    {
        if (isEmpty())
            cout << "Tree Is Empty...\n";
        else
        {
            cout << "Maximum Element In Tree: " << max(root)->data << endl;
        }
    }

    void preOrder()
    {
        return preOrder(root);
    }

    Tree()
    {
        root = nullptr;
        start = 0;
    }

    bool isOperator(char element)
    {
        return element == '*' || element == '/' || element == '+' || element == '-' ? 1 : 0;
    }

    Tree buildTree(Tree &t, string exp)
    {
        buildTree(t.root, exp);
        return t;
    }

    void buildTree(node* &t, string exp)
    {
        if (start == 7)
            return;
        node *newNode = new node;
        newNode->data = exp[start];
        newNode->left = nullptr;
        newNode->right = nullptr;
        t = newNode;
        start = start + 1;
        if (isOperator(t->data))
        {
            buildTree(t->left, exp);
            buildTree(t->right, exp);
        }
        else
            return;
    }

};


#endif //BINARY_TREE_TREE_H
