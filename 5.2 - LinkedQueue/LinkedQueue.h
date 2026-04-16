#pragma once

template <class T>
class QueueNode
{
public:
    T data;
    QueueNode<T> *next;

    QueueNode(void);
    QueueNode(T);
};

template <class T>
class LinkedQueue
{
    QueueNode<T> *front;
    QueueNode<T> *rear;
    int size;

public:
    LinkedQueue(void);
    bool isEmpty();
    void Enqueue(T);
    T Dequeue();
    void Clear();
    ~LinkedQueue(void);
};
