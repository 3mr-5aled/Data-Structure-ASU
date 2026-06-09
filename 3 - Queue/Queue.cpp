#include "Queue.h"
#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
Linkedlist<T>::Linkedlist(int size)
{
    capacity = size;
    front = back = -1;
    elements = 0;
    arr = new T[capacity];
}

template <class T>
void Linkedlist<T>::enqueue(T val)
{
    assert(!isFull());
    if (isEmpty())
    {
        front = 0;
    }
    back = ((back + 1) % capacity);
    arr[back] = val;
    elements++;
}

template <class T>
void Linkedlist<T>::dequeue()
{
    assert(!isEmpty());
    if (elements == 1)
    {
        front = -1;
        back = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }
    elements--;
}

template <class T>
bool Linkedlist<T>::isFull()
{
    return elements == capacity;
}

template <class T>
bool Linkedlist<T>::isEmpty()
{
    return elements == 0;
}

template <class T>
T Linkedlist<T>::Front()
{
    assert(!isEmpty());
    return arr[front];
}

template <class T>
Linkedlist<T>::~Linkedlist()
{
    delete[] arr;
}
