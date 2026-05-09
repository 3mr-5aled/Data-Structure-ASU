#include "LinkedList.h"

template <class T>
void LinkedList<T>::insertSorted(int val)
{
    Node<T> *newNode = new Node<T>(val);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else if (val < head->value)
    {
        newNode->next = head;
        head = newNode;
    }
    else if (val >= tail->value)
    {
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != NULL && temp->next->value <= val)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    size++;
}
