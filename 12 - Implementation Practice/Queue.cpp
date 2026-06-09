#include <iostream>
#include <cassert>
#include "Queue.h"

using namespace std;

template <class T>
Linkedlist<T>::Linkedlist()
{
    front = back = -1;
    elements = 0;
    size = 20;
    arr = new T[size];
}

template <class T>
Linkedlist<T>::Linkedlist(int s)
{
    front = back = -1;
    elements = 0;
    size = s;
    arr = new T[s];
}

template <class T>
int Linkedlist<T>::Length()
{
    return elements;
}

template <class T>
void Linkedlist<T>::Enqueue(T val)
{
    assert(elements != size);
    if (Empty())
    {
        front = 0;
    }
    back = (back + 1) % size;
    arr[back] = val;
    elements++;
}

template <class T>
void Linkedlist<T>::Dequeue()
{
    assert(!Empty());
    if (elements == 1)
    {
        front = back = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
    elements--;
}

template <class T>
T Linkedlist<T>::Front()
{
    assert(!Empty());
    return arr[front];
}

template <class T>
bool Linkedlist<T>::Empty()
{
    return (elements == 0);
}

template <class T>
Linkedlist<T>::~Linkedlist()
{
    delete arr;
}