#include "CycleLinkedList.h"
#include <cassert>

template <class T>
CycleLinkedList<T>::CycleLinkedList() : LinkedList<T>()
{
}

template <class T>
bool CycleLinkedList<T>::HasCycle()
{
    Node<T> *slow = this->head;
    Node<T> *fast = this->head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

template <class T>
void CycleLinkedList<T>::CreateCycleToPosition(int pos)
{
    assert(pos >= 0 && pos < this->count);
    if (this->head == NULL || this->tail == NULL)
        return;

    Node<T> *target = this->head;
    for (int i = 0; i < pos; i++)
        target = target->next;

    this->tail->next = target;
}

template <class T>
void CycleLinkedList<T>::BreakCycle()
{
    Node<T> *slow = this->head;
    Node<T> *fast = this->head;
    bool hasCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle)
        return;

    slow = this->head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node<T> *cycleStart = slow;
    Node<T> *lastInCycle = cycleStart;
    while (lastInCycle->next != cycleStart)
        lastInCycle = lastInCycle->next;

    lastInCycle->next = NULL;
    this->tail = lastInCycle;
}

template <class T>
CycleLinkedList<T>::~CycleLinkedList()
{
    BreakCycle();
}