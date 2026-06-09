#pragma once

template <class T>
class Linkedlist
{
    T *arr;
    int size, count;

public:
    Linkedlist();                   // O(1)
    int Length();                   // O(1)
    void Append(T item);            // Amortized O(1), worst-case O(n) when expanding
    void Expand();                  // O(n)
    T at(int index);                // O(1)
    void Insert(T item, int index); // O(n)
    void Remove(int index);         // O(n)
    ~Linkedlist();                  // O(1)
};