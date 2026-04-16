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
    BST();
    bool contains(T);
    void insert(T);
    void traverse(Order);
    void remove(T);

private:
    void inOrder(Node<T> *N);
    void preOrder(Node<T> *N);
    void postOrder(Node<T> *N);
    Node<T> *findNode(T);
    Node<T> *findMin(Node<T> *N);
    Node<T> *findParent(T);
};
