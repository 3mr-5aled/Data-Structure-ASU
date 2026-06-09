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
class Linkedlist
{
    Node<T> *head;
    Node<T> *tail;
    int count;

public:
    Linkedlist();
    int Length();
    T At(int pos);
    void insertAt(int pos, T val);
    void Append(T val);
    void DeleteAt(int pos);
    void Display();
    // exam 2021 (1st)
    void Reverse();
    void MoveZeros();
    ~Linkedlist();
};