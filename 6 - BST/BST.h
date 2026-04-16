#pragma once
#include <iostream>

using namespace std;

enum Order
{
    InOrder,
    PreOrder,
    PostOrder
};

template <class T>
class Node
{
public:
    T value;
    Node *right;
    Node *left;

    Node();
    Node(T);
};

template <class T>
class BST
{
private:
    Node<T> *root;

public:
    BST();                // O(1)
    bool contains(T);     // O(h), where h is tree height
    void insert(T);       // O(h)
    void traverse(Order); // O(n)
    void remove(T);       // O(h)

private:
    void inOrder(Node<T> *N);     // O(n)
    void preOrder(Node<T> *N);    // O(n)
    void postOrder(Node<T> *N);   // O(n)
    Node<T> *findNode(T);         // O(h)
    Node<T> *findMin(Node<T> *N); // O(h)
    Node<T> *findParent(T);       // O(h)
};
