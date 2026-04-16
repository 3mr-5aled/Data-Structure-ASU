#pragma once

template <class T>
class StackNode
{
public:
    T data;
    StackNode<T> *next;

    StackNode(void);
    StackNode(T);
};

template <class T>
class LinkedStack
{
    StackNode<T> *head;
    int size;

public:
    LinkedStack(void);
    bool isEmpty();
    void Push(T);
    T Pop();
    void Clear();
    ~LinkedStack(void);
};
