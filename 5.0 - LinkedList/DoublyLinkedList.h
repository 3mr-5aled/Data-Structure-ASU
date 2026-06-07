#pragma once

template <class T>
class DoublyNode
{
public:
    DoublyNode<T> *prev;
    DoublyNode<T> *next;
    T value;

    DoublyNode();
    DoublyNode(T val);
};

template <class T>
class DoublyLinkedList
{
public:
    int count;
    DoublyNode<T> *head;
    DoublyNode<T> *tail;

    DoublyLinkedList();
    int Length();
    T At(int);
    void InsertAt(int, T);
    void Append(T);
    void DeleteAt(int);
    void Display();
    void Reverse();
    ~DoublyLinkedList();
};