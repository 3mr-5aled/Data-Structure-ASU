#pragma once

// final 2022

template <class T>
class Node
{
    Node<T> *prev, *next;
    T value;

public:
    Node();
    Node(T val);
};

template <class T>
class Deque
{
    Node<T> *front, *back;
    int count;

public:
    Deque();
    void pushFront(T val);
    void popBack();
    void moveToFront(int pos);
};
