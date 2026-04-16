#include "Stack.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack()
{
    elements = 0;
    capacity = 10;
    arr = new T[capacity];
}

template <class T>
Stack<T>::Stack(int size)
{
    elements = 0;
    capacity = size;
    arr = new T[capacity];
}

template <class T>
void Stack<T>::push(T val)
{
    if (elements == capacity)
    {
        expand();
    }
    arr[elements] = val;
    elements++;
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    elements--;
    return arr[elements];
}

template <class T>
void Stack<T>::expand()
{
    T *newArr = new T[capacity * 2];
    for (int i = 0; i < elements; i++)
    {
        newArr[i] = arr[i];
    }
    capacity *= 2;
    delete[] arr;
    arr = newArr;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return elements == 0;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] arr;
}
