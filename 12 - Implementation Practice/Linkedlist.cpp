#include <iostream>
#include "Linkedlist.h"

using namespace std;

template <class T>
Node<T>::Node()
{
    value = 0;
    next = 0;
}

template <class T>
Node<T>::Node(T val)
{
    value = val;
    next = 0;
}

template <class T>
LinkedList<T>::Linkedlist(T val)
{
    head = tail = 0;
    count = 0;
}

template <class T>
int LinkedQueue<T>::Length()
{
    return count;
}

template <class T>
T LinkedQueue<T>::At(int pos)
{
    assert(pos >= 0 && pos < count);
    Node<T> *temp = head;
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    return temp->value;
}

// Final 2025
template <class T>
void LinkedList<T>::Append(T val)
{
    Node<T> *newNode = new Node(val);
    if (count == 0)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}
template <class T>
void LinkedList<T>::insertAt(int pos, T val)
{
    assert(pos >= 0 && pos < count);
    Node<T> *tmp = head;
    Node<T> *newNode = new Node<T>(val);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    count++;
}

template <class T>
void LinkedList<T>::DeleteAt(int pos)
{
    assert(pos >= 0 && pos < count);
    Node<T> *tmp = head;
    if (pos == 0)
    {
        head = tmp->next;
        delete tmp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        Node<T> *del = tmp->next;
        tmp->next = del->next;
        delete del;
        if (pos == count - 1)
        {
            tail = tmp;
        }
    }
    count--;
}

template <class T>
void LinkedList<T>::Display()
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        DeleteAt(0);
    }
}

// Final 2021 (1st)

template <class T>
void LinkedList<T>::Reverse()
{
    if (head == NULL || head->next == NULL)
        return;

    Node<T> *prev = NULL;
    Node<T> *curr = head;
    Node<T> *next = NULL;

    tail = head;

    while (curr != NULL && curr->next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

template <class T>
void LinkedList<T>::MoveZeroes()
{
    int i = 0;
    for (int index = 0; index < count; index++)
        if (At(i) == 0)
        {
            DeleteAt(i);
            Append(T(0));
        }
        else
        {
            i++;
        }
}

// Final 2021 (2nd)

template <class T>
void LinkedList<T>::insertAt(int pos, T val)
{
    assert(pos >= 0 && pos <= count);
    Node<T> *newNode = new Node(val);
    Node<T> *tmp = head;

    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    count++;
}

// Final 2025
template <class T>
void LinkedList<T>::Swap()
{

    Node<T> *curr = head;
    Node<T> *next = curr->next;
    while (count)
    {
        T tmp = curr->value;
        curr->value = next->value;
        next->value = tmp;
        curr = next->next;
        if (!curr || !curr->next)
        {
            return;
        }
        next = curr->next;
    }
}

template <class T>
void LinkedList<T>::Rotate()
{
    if (head == tail)
    {
        return;
    }

    Node<T> *last = head;
    Node<T> *tmp = tail;

    while (last->next != tail)
    {
        last = last->next
    }
    last->next = nullptr;
    tmp->next = head;
    head = tmp;
    tail = last;
}