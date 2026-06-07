#pragma once

template <class T>
class CircularNode
{
public:
    CircularNode<T> *next;
    T value;

    CircularNode();
    CircularNode(T val);
};

template <class T>
class CircularLinkedList
{
public:
    int count;
    CircularNode<T> *head;
    CircularNode<T> *tail;

    CircularLinkedList();
    int Length();
    T At(int);
    void InsertAt(int, T);
    void Append(T);
    void DeleteAt(int);
    void Display();
    void Reverse();
    ~CircularLinkedList();
};