#include <iostream>

using namespace std;

template <class T>
class Stack
{
    T *arr;
    int elements, size;

    //  Length: Returns the number of elements.
    //  Push: adds an element to the top of the stack.
    //  Pop: removes the top element.
    //  Top: returns the top element.
    //  Empty: returns whether the stack is empty.

public:
    Stack();
    Stack(int s);
    int Length();
    void Push(T val);
    void Pop();
    void Top();
    void Expand();
    bool Empty();

    ~Stack();
}