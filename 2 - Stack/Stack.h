#pragma once
template <class T>
class Stack
{
    T *arr;
    int elements;
    int capacity;

public:
    Stack();
    Stack(int size);
    void push(T val);
    T pop();
    T top();
    void expand();
    bool isEmpty();
    ~Stack();
};