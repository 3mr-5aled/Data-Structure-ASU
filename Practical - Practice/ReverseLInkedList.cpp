#include "LinkedList.h"

template <class T>
void LinkedList<T>::Reverse()
{
    Node<T> *prev = NULL;
    Node<T> *current = head;
    Node<T> *next;
    tail = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
