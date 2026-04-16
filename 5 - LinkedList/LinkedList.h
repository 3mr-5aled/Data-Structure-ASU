#pragma once

template <class T>
class Node
{
public:
    Node<T> *next;
    T value;

    Node();      // O(1)
    Node(T val); // O(1)
};

template <class T>
class LinkedList
{
    int count;
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList();                    // O(1)
    int Length();                    // O(1)
    T At(int);                       // O(n)
    void InsertAt(int, T);           // O(n)
    void Append(T);                  // O(1)
    void DeleteAt(int);              // O(n)
    void Display();                  // O(n) - Lab 5 additional function
    void MoveNode(int, int);         // O(n) - Lab 5 additional function
    void Reverse();                  // O(n)
    bool HasCycle();                 // O(n)
    void CreateCycleToPosition(int); // O(n)
    void BreakCycle();               // O(n)
    ~LinkedList(void);               // O(n)
};