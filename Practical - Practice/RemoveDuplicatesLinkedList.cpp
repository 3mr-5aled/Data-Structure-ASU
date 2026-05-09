#include "LinkedList.h"

template <class T>
void LinkedList<T>::RemoveDuplicates()
{
    if (size <= 1)
        return;

    Node<T> *temp1 = head;
    while (temp1 != NULL && temp1->next != NULL)
    {
        Node<T> *temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->value == temp2->next->value)
            {
                Node<T> *del = temp2->next;
                temp2->next = del->next;
                if (del == tail)
                    tail = temp2;
                delete del;
                size--;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp1 = temp1->next;
    }
}