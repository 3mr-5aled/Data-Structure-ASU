#include <iostream>
#include <cassert>
#include "ArrayList.h"

using namespace std;

template <class T>
Linkedlist<T>::Linkedlist()
{
    elements = 0;
    size = 10;
    arr = new T[size];
}

template <class T>
void Linkedlist<T>::Append(T val)
{
    if (elements == size)
    {
        expand();
    }
    arr[elements] = val;
    elements++;
}

template <class T>
void Linkedlist<T>::Expand()
{
    size *= 2;
    T *newArr = new T[size];
    for (int i = 0; i < elements; i++)
    {
        newArr[i] = arr[i];
    }
    delete arr;
    arr = newArr;
}

template <class T>
void Linkedlist<T>::insertAt(int pos, T val)
{
    assert(pos < elements);
    if (elements == size)
    {
        expand();
    }
    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    elements++;
}

template <class T>
void Linkedlist<T>::DeleteAt(int pos)
{
    assert(pos < elements);
    for (int i = pos; i < elements - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    elements--;
}

template <class T>
T Linkedlist<T>::At(int pos)
{
    return arr[pos];
}

template <class T>
int Linkedlist<T>::Length()
{
    return elements;
}

template <class T>
Linkedlist<T>::~Linkedlist()
{
    delete[] arr;
}
