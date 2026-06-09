#include <iostream>
using namespace std;

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
    Node<T> *left;
    Node<T> *right;
    T value;
    Node();
    Node(T val);
};

template <class T>
class BST
{
    Node<T> *root;

public:
    BST(void);

    bool contains(T val);
    Node<T> *findNode(T val);
    void insert(T val);

    void traverse(Order order);

    void inOrder(Node<T> *node);
    void preOrder(Node<T> *node);
    void postOrder(Node<T> *node);

    Node<T> *findParent(T val);
    Node<T> *findMin(Node<T> *start);

    // final 2021 (2nd)
    Node<T> findMax();
    void remove(T val);

    ~BST();
};
