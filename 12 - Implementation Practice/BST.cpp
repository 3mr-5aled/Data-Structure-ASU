#include "BST.h"
#include <iostream>

template <class T>
Node<T>::Node()
{
    left = right = nullptr;
    value = T();
}

template <class T>
Node<T>::Node(T val)
{
    left = right = nullptr;
    value = val;
}

template <class T>
BST<T>::BST()
{
    root = nullptr;
}

template <class T>
BST<T>::~BST()
{
    // empty destructor
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
        if (temp->value < val)
            temp = temp->right;
        if (temp->value > val)
            temp = temp->left;
        else
            return temp;
    }

    return temp;
}

template <class T>
void BST<T>::insert(T val)
{
    assert(contains(val) == false);

    Node<T> *newNode = new Node<T>(val);
    if (root == NULL)
    {
        root = newNode;
        return;
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
                    temp->left = newNode;
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
                    temp->right = newNode;
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
        inOrder(node->left);
        cout << node->value << endl;
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
    Node<T> *parent = root;
    Node<T> *child = root;
    while (child != NULL)
    {
        if (child->value == val)
        {
            break;
        }

        parent = child;
        if (child->value > val)
        {
            child = child->left;
        }
        else
        {
            child = child->right;
        }
    }

    return parent;
}

template <class T>
Node<T> *BST<T>::findMin(Node<T> *start)
{
    Node<T> *tmp = start;
    while (tmp->left != nullptr)
    {
        tmp = tmp->left;
    }
    return tmp;
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
Node<T> *BST<T>::findMax()
{
    Node<T> *tmp = root;
    assert(tmp != nullptr);
    while (tmp->right != nullptr)
    {
        tmp = tmp->right;
    }
    return tmp;
}