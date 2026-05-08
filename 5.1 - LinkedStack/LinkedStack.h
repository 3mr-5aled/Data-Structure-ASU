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
    LinkedStack(void);             // O(1)
    bool isEmpty();                // O(1)
    void Append(T);                // O(1)
    void insertAt(T val, int pos); // O(n)
    T Pop();                       // O(1)
    void remove(int pos);          // O(n)
    void MoveNode(T val, int pos); // O(n)
    void Display();                // O(n)
    void Clear();                  // O(n)
    ~LinkedStack(void);            // O(n)
};
