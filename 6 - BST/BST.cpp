#include "BST.h"
#include <assert.h>
#include <iostream>

using namespace std;

template <class T>
Node<T>::Node()
{
    value = 0;
    right = NULL;
    left = NULL;
}

template <class T>
Node<T>::Node(T val)
{
    value = val;
    right = NULL;
    left = NULL;
}

template <class T>
BST<T>::BST()
{
    root = NULL;
}

template <class T>
bool BST<T>::contains(T val)
{
    Node<T> *check = findNode(val);

    return check != NULL;
}

template <class T>
void BST<T>::insert(T val)
{
    assert(!contains(val));

    Node<T> *newNode = new Node<T>(val);

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        Node<T> *temp = root;
        while (true)
        {
            if (val > temp->value)
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    break;
                }
                else
                    temp = temp->right;
            }
            if (val < temp->value)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    break;
                }
                else
                    temp = temp->left;
            }
        }
    }
}

template <class T>
void BST<T>::traverse(Order order)
{
    switch (order)
    {
    case Order::InOrder:
        inOrder(root);
        break;
    case Order::PreOrder:
        preOrder(root);
        break;
    case Order::PostOrder:
        postOrder(root);
        break;
    }
}

template <class T>
void BST<T>::remove(T val)
{
    assert(contains(val));

    Node<T> *temp = findNode(val);
    Node<T> *parent = findParent(val);

    // Case 1: Leaf node
    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp == root)
        {
            root = NULL;
        }
        else if (temp->value < parent->value)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }

        delete temp;
    }

    // Case 2: Only right child
    else if (temp->left == NULL)
    {
        if (temp == root)
        {
            root = temp->right;
        }
        else if (temp->value < parent->value)
        {
            parent->left = temp->right;
        }
        else
        {
            parent->right = temp->right;
        }

        delete temp;
    }

    // Case 3: Only left child
    else if (temp->right == NULL)
    {
        if (temp == root)
        {
            root = temp->left;
        }
        else if (temp->value < parent->value)
        {
            parent->left = temp->left;
        }
        else
        {
            parent->right = temp->left;
        }

        delete temp;
    }

    // Case 4: Two children
    else
    {
        Node<T> *min = findMin(temp->right);
        T minVal = min->value;

        remove(minVal);       // remove successor
        temp->value = minVal; // replace value
    }
}

template <class T>
void BST<T>::inOrder(Node<T> *N)
{
    // in order : left , root , right
    if (N != NULL)
    {
        inOrder(N->left);
        cout << N->value << endl;
        inOrder(N->right);
    }
}

template <class T>
void BST<T>::preOrder(Node<T> *N)
{
    // pre order : root , left , right
    if (N != NULL)
    {
        cout << N->value << endl;
        preOrder(N->left);
        preOrder(N->right);
    }
}

template <class T>
void BST<T>::postOrder(Node<T> *N)
{
    // in order : left , right, root
    if (N != NULL)
    {
        postOrder(N->left);
        postOrder(N->right);
        cout << N->value << endl;
    }
}

template <class T>
Node<T> *BST<T>::findNode(T val)
{
    Node<T> *temp = root;

    while (temp != NULL)
    {
        if (temp->value == val)
        {
            return temp;
        }
        else if (val > temp->value)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return NULL;
}

template <class T>
Node<T> *BST<T>::findMin(Node<T> *N)
{
    Node<T> *temp = N;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

template <class T>
Node<T> *BST<T>::findParent(T val)
{
    assert(contains(val));

    Node<T> *current = root;
    Node<T> *parent = NULL;

    while (current->value != val)
    {
        parent = current;

        if (val < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return parent;
}
