#pragma once

template <class T>
class QueueNode
{
public:
    T data;
    QueueNode<T> *next;

    QueueNode(void); // O(1)
    QueueNode(T);    // O(1)
};

template <class T>
class LinkedQueue
{
    QueueNode<T> *front;
    QueueNode<T> *rear;
    int size;

public:
    LinkedQueue(void);  // O(1)
    bool isEmpty();     // O(1)
    void Enqueue(T);    // O(1)
    T Dequeue();        // O(1)
    void Clear();       // O(n)
    ~LinkedQueue(void); // O(n)
};
