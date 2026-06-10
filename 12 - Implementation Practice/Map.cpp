#include "Map.h"
#include <iostream>

using namespace std;

template <class T>
Node<T>::Node()
{
    key = 0;
    value = [];
    left = nullptr;
    right = nullptr;
}
template <class T>
Node<T>::Node(int k, T v)
{
    key = k;
    value.push_back(v);
    left = nullptr;
    right = nullptr;
}

template <class T>
Map<T>::Map()
{
    root = nullptr;
    count = 0;
}

// a. insert (k,v): adds a node with key k and value v to the tree but if a node with the same key exists it will add thevalue to the end of the associated array.

template <class T>
void Map<T>::insert(char key, T val)
{
    Node<T> *newNode = new Node<T>(key, val);

    if (tmp == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node<T> *tmp = root;
        while (true)
        {
            if (key > tmp->key)
            {
                if (tmp->right == nullptr)
                {
                    tmp->right == newNode;
                    return;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            else if (key < tmp->key)
            {
                if (tmp->left == nullptr)
                {
                    tmp->left == newNode;
                    return;
                }
                else
                {
                    tmp = tmp->left;
                }
            }
            else
            {
                tmp->value.push_back(val);
                return;
            }
        }
    }
}

// b. find(k): searches for the node with the key k and displays all the associated values.
template <class T>
void Map<T>::find(char key)
{
    Node<T> *tmp = root;
    vector<T> vals;
    while (tmp != nullptr)
    {

        if (key > tmp->key)
        {
            tmp = tmp->right;
        }
        else if (key < tmp->key)
        {
            tmp = tmp->left;
        }
        else
        {
            cout << "The Key " << k << " has " << tmp->value.size() << " value (s):" << endl;
            for (T item : tmp->value)
            {
                cout << item << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "Key " << k << " was not found !" << endl;
}
