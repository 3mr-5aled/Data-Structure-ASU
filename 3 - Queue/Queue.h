#pragma once
template <class T>
class Linkedlist
{
    T *arr;
    int front;
    int back;
    int capacity;
    int elements;

public:
    Linkedlist(int size);
    void enqueue(T val);
    void dequeue();
    bool isFull();
    bool isEmpty();
    T Front();
    ~Linkedlist(void);
};