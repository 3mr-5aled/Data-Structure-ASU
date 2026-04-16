#pragma once
enum Order
{
    INORDER = 0,
    PREORDER = 1,
    POSTORDER = 2,
    XOrder = 3
};

template <class T>
class Node
{
public:
    T value;
    Node<T> *left, *right;
    Node();
    Node(T val);
};

template <class T>
class BST
{
    Node<T> *root;

public:
    BST(void);
    ~BST(void);

    bool contains(T val);
    Node<T> *findNode(T val);
    void insert(T val);

    void traverse(Order order);

    void inOrder(Node<T> *node);
    void preOrder(Node<T> *node);
    void postOrder(Node<T> *node);

    Node<T> *findParent(T val);
    Node<T> *findMin(Node<T> *start);
    void remove(T val);

    void deleteBST(Node<T> *node);
};