#include "DoublyLinkedList.h"
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
DoublyNode<T>::DoublyNode()
{
    value = 0;
    prev = next = nullptr;
}

template <class T>
DoublyNode<T>::DoublyNode(T val)
{
    value = val;
    prev = next = nullptr;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = tail = nullptr;
    count = 0;
}

template <class T>
int DoublyLinkedList<T>::Length()
{
    return count;
}

template <class T>
void DoublyLinkedList<T>::Append(T val)
{
    DoublyNode<T> *newNode = new DoublyNode<T>(val);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    count++;
}

template <class T>
T DoublyLinkedList<T>::At(int pos)
{
    assert(pos >= 0 && pos < count);

    DoublyNode<T> *tmp = head;
    for (int i = 0; i < pos; i++)
        tmp = tmp->next;

    return tmp->value;
}

template <class T>
void DoublyLinkedList<T>::InsertAt(int pos, T val)
{
    assert(pos >= 0 && pos < count);

    DoublyNode<T> *newNode = new DoublyNode<T>(val);

    if (pos == 0)
    {
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
    }
    else
    {
        DoublyNode<T> *tmp = head;
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;

        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next->prev = newNode;
        tmp->next = newNode;
    }

    count++;
}

template <class T>
void DoublyLinkedList<T>::DeleteAt(int pos)
{
    assert(pos >= 0 && pos < count);

    if (pos == 0)
    {
        DoublyNode<T> *del = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete del;
    }
    else
    {
        DoublyNode<T> *tmp = head;
        for (int i = 0; i < pos; i++)
            tmp = tmp->next;

        if (tmp->prev != nullptr)
            tmp->prev->next = tmp->next;
        if (tmp->next != nullptr)
            tmp->next->prev = tmp->prev;
        if (tmp == tail)
            tail = tmp->prev;

        delete tmp;
    }

    count--;
}

template <class T>
void DoublyLinkedList<T>::Display()
{
    DoublyNode<T> *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << endl;
        tmp = tmp->next;
    }
}

template <class T>
void DoublyLinkedList<T>::Reverse()
{
    if (count < 2)
        return;

    DoublyNode<T> *current = head;
    DoublyNode<T> *temp = nullptr;

    tail = head;

    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
        head = temp->prev;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (count > 0)
        DeleteAt(0);
}