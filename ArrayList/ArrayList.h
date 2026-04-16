#pragma once

template <class T>
class ArrayList
{
    T *arr;
    int size, count;

public:
    ArrayList();
    int Length();
    void Append(T item);
    void Expand();
    T at(int index);
    void Insert(T item, int index);
    void Remove(int index);
    ~ArrayList();
};