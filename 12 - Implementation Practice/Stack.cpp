#include <iostream>
#include <cassert>
#include "Stack.h"

using namespace std;

template <class T>
Stack<T>::Stack()
{
    elements = 0;
    size = 10;
    arr = new T[size]
}

template <class T>
Stack<T>::Stack(int s)
{
    elements = 0;
    size = s;
    arr = new T[size]
}

template <class T>
int Stack<T>::Length()
{
    return elements;
}

template <class T>
void Stack<T>::Push(T val)
{
    if (elements == size)
    {
        expand();
    }
    arr[elements] = val;
    elements++;
}

template <class T>
T Stack<T>::Pop()
{
    assert(!Empty());
    elements--;
    return arr[elements];
}

template <class T>
void Stack<T>::Top()
{
    return arr[elements - 1];
}

template <class T>
void Stack<T>::Expand()
{
    T *newArr = new T[size * 2];
    for (int i = 0; i < elements; i++)
    {
        newArr[i] = arr[i];
    }
    size *= 2;
    delete arr;
    arr = newArr;
}

template <class T>
bool Stack<T>::Empty()
{
    return (elements == 0);
}

template <class T>
Stack<T>::~Stack()
{
    delete arr;
}