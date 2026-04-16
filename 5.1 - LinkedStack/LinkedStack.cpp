#include <iostream>
#include "LinkedStack.h"
using namespace std;

template <class T>
StackNode<T>::StackNode(void)
{
    data = 0;
    next = NULL;
}

template <class T>
StackNode<T>::StackNode(T val)
{
    data = val;
    next = NULL;
}

template <class T>
LinkedStack<T>::LinkedStack(void)
{
    head = NULL;
    size = 0;
}

template <class T>
bool LinkedStack<T>::isEmpty()
{
    return (size == 0);
}

template <class T>
void LinkedStack<T>::Push(T val)
{
    StackNode<T> *newNode = new StackNode<T>(val);
    newNode->next = head;
    head = newNode;
    size++;
}

template <class T>
T LinkedStack<T>::Pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow! Cannot pop from an empty stack." << endl;
        throw std::runtime_error("Stack underflow");
    }
    StackNode<T> *temp = head;
    T poppedValue = temp->data;
    head = head->next;
    delete temp;
    size--;
    return poppedValue;
}

template <class T>
void LinkedStack<T>::Clear()
{
    StackNode<T> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    // while (!isEmpty())
    //     Pop();
}

template <class T>
LinkedStack<T>::~LinkedStack(void)
{
    Clear();
}
