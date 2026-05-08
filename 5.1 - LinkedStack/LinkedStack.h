#pragma once

template <class T>
class StackNode
{
public:
    T data;
    StackNode<T> *next;

    StackNode(void); // O(1)
    StackNode(T);    // O(1)
};

template <class T>
class LinkedStack
{
    StackNode<T> *head;
    int size;

public:
    LinkedStack(void);  // O(1)
    bool isEmpty();     // O(1)
    void Push(T);       // O(1)
    T Pop();            // O(1)
    void Clear();       // O(n)
    ~LinkedStack(void); // O(n)
};
