#include "Queue.h"
#include <iostream>
#include <assert.h>

using namespace std;

template <class T>
Queue<T>::Queue(int size)
{
    capacity = size;
    arr = new T[capacity];
    front = -1;
    back = -1;
    elements = 0;
}

template <class T>
void Queue<T>::enqueue(T val)
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
void Queue<T>::dequeue()
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
bool Queue<T>::isFull()
{
    return elements == capacity;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return elements == 0;
}

template <class T>
T Queue<T>::Front()
{
    assert(!isEmpty());
    return arr[front];
}

template <class T>
Queue<T>::~Queue()
{
    delete[] arr;
}
