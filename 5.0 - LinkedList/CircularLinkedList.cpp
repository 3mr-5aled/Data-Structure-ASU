#include "CircularLinkedList.h"
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
CircularNode<T>::CircularNode()
{
    value = 0;
    next = nullptr;
}

template <class T>
CircularNode<T>::CircularNode(T val)
{
    value = val;
    next = nullptr;
}

template <class T>
CircularLinkedList<T>::CircularLinkedList()
{
    head = tail = nullptr;
    count = 0;
}

template <class T>
int CircularLinkedList<T>::Length()
{
    return count;
}

template <class T>
void CircularLinkedList<T>::Append(T val)
{
    CircularNode<T> *newNode = new CircularNode<T>(val);

    if (head == nullptr)
    {
        head = tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    count++;
}

template <class T>
T CircularLinkedList<T>::At(int pos)
{
    assert(pos >= 0 && pos < count);

    CircularNode<T> *tmp = head;
    for (int i = 0; i < pos; i++)
        tmp = tmp->next;

    return tmp->value;
}

template <class T>
void CircularLinkedList<T>::InsertAt(int pos, T val)
{
    assert(pos >= 0 && pos < count);

    CircularNode<T> *newNode = new CircularNode<T>(val);

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    else
    {
        CircularNode<T> *tmp = head;
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;

        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    count++;
}

template <class T>
void CircularLinkedList<T>::DeleteAt(int pos)
{
    assert(pos >= 0 && pos < count);

    if (pos == 0)
    {
        CircularNode<T> *del = head;
        if (count == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }
        delete del;
    }
    else
    {
        CircularNode<T> *tmp = head;
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;

        CircularNode<T> *del = tmp->next;
        tmp->next = del->next;
        if (del == tail)
            tail = tmp;
        delete del;
    }

    count--;
}

template <class T>
void CircularLinkedList<T>::Display()
{
    if (count == 0)
        return;

    CircularNode<T> *tmp = head;
    for (int i = 0; i < count; i++)
    {
        cout << tmp->value << endl;
        tmp = tmp->next;
    }
}

template <class T>
void CircularLinkedList<T>::Reverse()
{
    if (count < 2)
        return;

    CircularNode<T> *prev = tail;
    CircularNode<T> *current = head;
    CircularNode<T> *nextNode = nullptr;

    for (int i = 0; i < count; i++)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    CircularNode<T> *oldHead = head;
    head = tail;
    tail = oldHead;
    tail->next = head;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while (count > 0)
        DeleteAt(0);
}