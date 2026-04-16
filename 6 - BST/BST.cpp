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

    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp == root)
        {
            root = NULL;
        }
        else
        {
            Node<T> *parent = findParent(temp->value);

            if (temp->value < parent->value)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
        }
        delete temp;
    }
    else if (temp->left == NULL && temp->right != NULL)
    {
        Node<T> *parent = findParent(temp->value);
        if (temp == root)
        {
            root = root->right;
        }
        if (temp->value < parent->value)
        {
            parent->left = temp->right;
        }
        else
        {
            parent->right = temp->right;
        }
    }
    else if (temp->left != NULL && temp->right == NULL)
    {
        Node<T> *parent = findParent(temp->value);
        if (temp == root)
        {
            root = root->left;
        }
        if (temp->value < parent->value)
        {
            parent->left = temp->left;
        }
        else
        {
            parent->right = temp->left;
        }
    }
    else
    {
        Node<T> *min = findMin(temp->right);
        T minVal = min->value;
        remove(minVal);
        temp->value = minVal;
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
    Node<T> *a = root;
    Node<T> *b = NULL;

    b = a;
    while (a->value != val)
    {
        if (val < a->value)
            a = a->left;
        else
            a = a->right;
    }
    return b;
}
