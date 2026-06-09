#include <iostream>

using namespace std;

template <class T>
class Linkedlist
{
    int front, back, elements, size;
    T *arr;

    // Length: Returns the number of elements.
    // Enqueue: Adds an element to the end of the queue.
    // Dequeue: Removes the element at the front of the queue.
    // Front: Returns the front element.
    // Empty: Returns whether the queue is empty.

public:
    Linkedlist();
    Linkedlist(int size);

    int Length();
    void Enqueue(T val);
    void Dequeue();
    T Front();
    bool Empty();

    ~Linkedlist();
}