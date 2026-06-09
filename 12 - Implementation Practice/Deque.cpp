#include <iostream>
#include "Deque.h"
using namespace std;

template <class T>
Node<T>::Node()
{
    prev = next = nullptr;
}
template <class T>
Node<T>::Node(T val)
{
    prev = next = nullptr;
    value = val;
}
template <class T>
Deque<T>::Deque()
{
    front = back = nullptr;
    count = 0;
}
template <class T>
void Deque<T>::pushFront(T val)
{
    Node<T> *newNode = new Node(val);
    if (front == nullptr)
    {
        front = back = newNode;
    }
    else
    {
        front->prev = newNode;
        newNode->next = front;
        front = newNode;
    }
}

template <class T>
void Deque<T>::popBack()
{
    if (back == nullptr)
    {
        return;
    }
    else if (front == back)
    {
        delete back;
        front = back = nullptr;
    }
    else
    {
        Node<T> *tmp = back->prev;
        tmp->next = nullptr;
        delete back;
        back = tmp;
    }
}

template <class T>
void Deque<T>::moveToFront(int pos)
{
    assert(pos >= 0 && pos < count);
    if (pos == 0 || front == nullptr)
    {
        return;
    }

    Node<T> *tmp = front;
    for (int i = 0; i < pos && tmp != nullptr; i++)
    {
        tmp = tmp->next;
    }

    if (tmp == nullptr || tmp == front)
    {
        return;
    }
    Node<T> *prev = tmp->prev;
    prev->next = tmp->next;
    pushFront(tmp->value);
    delete tmp;
}
