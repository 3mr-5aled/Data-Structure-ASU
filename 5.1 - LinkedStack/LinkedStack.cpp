#include <iostream>
#include "LinkedStack.h"
using namespace std;

template <class T>
StackNode<T>::StackNode(void)
{
    data = 0;
    next = NULL;
}

template <class T>
StackNode<T>::StackNode(T val)
{
    data = val;
    next = NULL;
}

template <class T>
LinkedStack<T>::LinkedStack(void)
{
    head = NULL;
    size = 0;
}

template <class T>
bool LinkedStack<T>::isEmpty()
{
    return (size == 0);
}

void LinkedList::Append(int val)
{
    Node *newNode = new Node(val);
    if (size == 0)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }

    size++;
}

void LinkedList::insertAt(int val, int pos)
{

    assert(pos >= 0 && pos < size);

    Node *temp = head;
    Node *newNode = new Node();

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            if (i == pos)
            {
                temp = temp->next;
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        size++;
    }
}

template <class T>
T LinkedStack<T>::Pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow! Cannot pop from an empty stack." << endl;
        throw std::runtime_error("Stack underflow");
    }
    StackNode<T> *temp = head;
    T poppedValue = temp->data;
    head = head->next;
    delete temp;
    size--;
    return poppedValue;
}

void LinkedList::remove(int pos)
{
    assert(pos >= 0 && pos < size);
    Node *temp = head;
    if (pos == 0)
    {

        head = head->next;
        delete temp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
            if (pos == size - 1)
            {
                tail = temp;
            }
        }
    }
    size--;
}

template <class T>
void LinkedStack<T>::Clear()
{
    StackNode<T> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    // while (!isEmpty())
    //     Pop();
}

template <class T>
LinkedStack<T>::~LinkedStack(void)
{
    Clear();
}

// extra
void LinkedList::MoveNode(int val, int pos)
{
    Node *tmp = head;
    int c = 0;
    while (tmp != NULL && tmp->data != val)
    {
        tmp = tmp->next;
        c++;
    }

    if (tmp != NULL) // Found the value
    {
        remove(c);
        if (pos == size)
            Append(val);
        else
            insertAt(val, pos);
    }
}

void LinkedList::Display()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}