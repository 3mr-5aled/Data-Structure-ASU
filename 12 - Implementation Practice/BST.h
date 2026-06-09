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

    void traverse(Order order);

    void inOrder(Node<T> *node);
    void preOrder(Node<T> *node);
    void postOrder(Node<T> *node);

    Node<T> *findParent(T val);
    Node<T> *findMin(Node<T> *start);

    // final 2021 (2nd)
    void Remove(T val);
    // final 2024 & 21
    void insert(T val);
    Node<T> *Max();

    // final 2024
    void createTree(vector<T> arr);
    void createBalancedTree(vector<T> arr, int start, int end);
    void createTree2(int arr[], int size);

    ~BST();
};
