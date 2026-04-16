#include "BST.h"
#include <iostream>
#include <assert.h>

template <class T>
Node<T>::Node()
{
    left = right = NULL;
}

template <class T>
Node<T>::Node(T val)
{
    value = val;
    left = right = NULL;
}

template <class T>
BST<T>::BST(void)
{
    root = NULL;
}

template <class T>
bool BST<T>::contains(T val)
{
    Node<T> *tmp = findNode(val);
    return (tmp != NULL);
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

        if (temp->value > val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return temp;
}

template <class T>
void BST<T>::insert(T val)
{
    assert(contains(val) == false);

    Node<T> *nodeToBeInserted = new Node<T>(val);
    if (root == NULL)
    {
        root = nodeToBeInserted;
    }
    else
    {
        Node<T> *temp = root;
        while (true)
        {
            if (temp->value > val)
            {
                // left
                if (temp->left == NULL)
                {
                    temp->left = nodeToBeInserted;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                // right
                if (temp->right == NULL)
                {
                    temp->right = nodeToBeInserted;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

template <class T>
void BST<T>::traverse(Order order)
{
    if (order == INORDER)
        inOrder(root);
    else if (order == PREORDER)
        preOrder(root);
    else
        postOrder(root);
}

template <class T>
void BST<T>::inOrder(Node<T> *node)
{
    if (node != NULL)
    {
        // left
        inOrder(node->left);
        // node
        cout << node->value << endl;
        // right
        inOrder(node->right);
    }
}

template <class T>
void BST<T>::preOrder(Node<T> *node)
{
    if (node != NULL)
    {
        cout << node->value << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
}

template <class T>
void BST<T>::postOrder(Node<T> *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << endl;
    }
}

template <class T>
Node<T> *BST<T>::findParent(T val)
{
    Node<T> *b = NULL;
    Node<T> *a = root;

    while (a != NULL)
    {
        if (a->value == val)
        {
            break;
        }

        b = a;
        if (a->value > val)
        {
            a = a->left;
        }
        else
        {
            a = a->right;
        }
    }

    return b;
}

template <class T>
Node<T> *BST<T>::findMin(Node<T> *start)
{
    Node<T> *minNode = start;
    while (minNode->left != NULL)
    {
        minNode = minNode->left;
    }

    return minNode;
}

template <class T>
void BST<T>::remove(T val)
{
    assert(contains(val));

    Node<T> *n = findNode(val);

    if ((n->left == NULL) && (n->right == NULL)) // deleting a leaf node
    {
        if (n == root)
        {
            root = NULL;
        }
        else
        {
            Node<T> *parent = findParent(val);
            if (val < parent->value)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        delete n;
    }
    else if ((n->left == NULL) && (n->right != NULL))
    {
        Node<T> *parent = findParent(val);
        if (n == root)
        {
            root = n->right;
        }
        else
        {
            if (val < parent->value)
                parent->left = n->right;
            else
                parent->right = n->right;
        }
        delete n;
    }
    else if ((n->left != NULL) && (n->right == NULL))
    {
        Node<T> *parent = findParent(val);
        if (n == root)
            root = n->left;
        else
        {
            if (val < parent->value)
                parent->left = n->left;
            else
                parent->right = n->left;
        }
        delete n;
    }
    else
    {
        Node<T> *minNode = findMin(n->right);
        Node<T> *parent = findParent(minNode->value);

        n->value = minNode->value;

        if (parent == n)
            parent->right = minNode->right;
        else
            parent->left = minNode->right;

        delete minNode;
    }
}

template <class T>
void BST<T>::deleteBST(Node<T> *node)
{
    if (node == NULL)
        return;

    Node<T> *currentTreeNode = node;
    Node<T> *leftTreeNode = node->left;
    Node<T> *rightTreeNode = node->right;
    delete (currentTreeNode);
    deleteBST(leftTreeNode);
    deleteBST(rightTreeNode);
}

template <class T>
BST<T>::~BST(void)
{
    deleteBST(root);
}