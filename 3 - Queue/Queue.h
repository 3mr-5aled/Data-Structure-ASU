#pragma once
template <class T>
class Queue
{
    T *arr;
    int front;
    int back;
    int capacity;
    int elements;

public:
    Queue(int size);
    void enqueue(T val);
    void dequeue();
    bool isFull();
    bool isEmpty();
    T Front();
    ~Queue(void);
};