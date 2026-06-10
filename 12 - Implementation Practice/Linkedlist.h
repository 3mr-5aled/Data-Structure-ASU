#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T value;
    Node<T> *next;
    Node();
    Node(T val);
};

template <class T>
class LinkedList
{
    Node<T> *head;
    Node<T> *tail;
    int count;

public:
    LinkedList();
    int Length();
    T At(int pos);
    void insertAt(int pos, T val);

    void DeleteAt(int pos);
    void Display();
    // exam 2021 (1st)
    void Reverse();
    void MoveZeros();

    // exam 2025
    void Append(T val);
    void Swap();
    void Rotate();

    ~LinkedList();
};