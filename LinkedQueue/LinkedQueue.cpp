#include <iostream>
#include <stdexcept>
#include "LinkedQueue.h"
using namespace std;

template <class T>
QueueNode<T>::QueueNode(void)
{
    data = 0;
    next = NULL;
}

template <class T>
QueueNode<T>::QueueNode(T val)
{
    data = val;
    next = NULL;
}

template <class T>
LinkedQueue<T>::LinkedQueue(void)
{
    front = NULL;
    rear = NULL;
    size = 0;
}

template <class T>
bool LinkedQueue<T>::isEmpty()
{
    return (size == 0);
}

template <class T>
void LinkedQueue<T>::Enqueue(T val)
{
    QueueNode<T> *newNode = new QueueNode<T>(val);
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <class T>
T LinkedQueue<T>::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
        throw std::runtime_error("Queue underflow");
    }

    QueueNode<T> *temp = front;
    T dequeuedValue = temp->data;
    front = front->next;
    delete temp;
    size--;

    if (front == NULL)
        rear = NULL;

    return dequeuedValue;
}

template <class T>
void LinkedQueue<T>::Clear()
{
    QueueNode<T> *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
}

template <class T>
LinkedQueue<T>::~LinkedQueue(void)
{
    Clear();
}
