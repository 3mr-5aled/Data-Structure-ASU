#include <iostream>
#include <cassert>
#include "ArrayList.h"

using namespace std;
template <class T>
inline Queue<T>::Queue()
{
    size = 10;
    arr = new T[size];
    count = 0;
}

template <class T>
int Queue<T>::Length()
{
    return count;
}

template <class T>
void Queue<T>::Append(T item)
{
    if (count == size)
    {
        Expand();
    }
    arr[count] = item;
    count++;
}

template <class T>
void Queue<T>::Expand()
{
    size *= 2;
    T *newArr = new T[size];
    for (int i = 0; i < count; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

template <class T>
T Queue<T>::at(int index)
{
    return arr[index];
}

template <class T>
void Queue<T>::Insert(T item, int index)
{
    assert(index < count);

    if (count == size)
    {
        Expand();
    }
    for (int i = count; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = item;
    count++;
}

template <class T>
void Queue<T>::Remove(int index)
{
    assert(index < count);
    for (int i = index; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    count--;
}

template <class T>
Queue<T>::~Queue()
{
    delete[] arr;
}
