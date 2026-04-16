#include "LinkedList.h"
#include <assert.h>

template <class T>
Node<T>::Node()
{
    value = 0;
    next = 0;
}

template <class T>
Node<T>::Node(T val)
{
    value = val;
    next = 0;
}

template <class T>
LinkedList<T>::LinkedList(void)
{
    head = tail = 0;
    count = 0;
}

template <class T>
int LinkedList<T>::Length()
{
    return count;
}

template <class T>
void LinkedList<T>::Append(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if (head == 0)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template <class T>
T LinkedList<T>::At(int pos)
{
    assert(pos >= 0 && pos < count);
    Node<T> *tmp = head;
    for (int i = 0; i < pos; i++)
        tmp = tmp->next;
    return tmp->value;
}

template <class T>
void LinkedList<T>::InsertAt(int pos, T val)
{
    assert(pos >= 0 && pos < count);
    Node<T> *tmp = head;
    Node<T> *newNode = new Node<T>(val);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;

        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    count++;
}

template <class T>
void LinkedList<T>::DeleteAt(int pos)
{
    assert(pos >= 0 && pos < count);
    Node<T> *tmp = head;
    if (pos == 0)
    {
        head = head->next;
        delete tmp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            tmp = tmp->next;
        Node<T> *del = tmp->next;
        tmp->next = del->next;
        delete del;
        if (pos == count - 1)
            tail = tmp;
    }
    count--;
}

template <class T>
void LinkedList<T>::Display()
{
    Node<T> *tmp = head;
    while (tmp != NULL)
    {
        std::cout << tmp->value;
        std::cout << std::endl;
        tmp = tmp->next;
    }
}

template <class T>
void LinkedList<T>::MoveNode(int val, int pos)
{
    Node<T> *temp = head;
    int c = 0;
    while (temp != NULL && temp->value != val)
    {
        temp = temp->next;
        c++;
    }
    DeleteAt(c);
    if (pos == count)
    {
        Append(val);
    }
    else
    {
        InsertAt(pos, val);
    }
}

template <class T>
void LinkedList<T>::Reverse()
{
    if (head == NULL || head->next == NULL)
        return;

    Node<T> *prev = NULL;
    Node<T> *current = head;
    Node<T> *nextNode = NULL;

    tail = head;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}

template <class T>
bool LinkedList<T>::HasCycle()
{
    Node<T> *slow = head;
    Node<T> *fast = head;

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
void LinkedList<T>::CreateCycleToPosition(int pos)
{
    assert(pos >= 0 && pos < count);
    if (head == NULL || tail == NULL)
        return;

    Node<T> *target = head;
    for (int i = 0; i < pos; i++)
        target = target->next;

    tail->next = target;
}

template <class T>
void LinkedList<T>::BreakCycle()
{
    // If there is no cycle, nothing to fix.
    Node<T> *slow = head;
    Node<T> *fast = head;
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

    slow = head;
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
    tail = lastInCycle;
}

template <class T>
LinkedList<T>::~LinkedList(void)
{
    BreakCycle();
    while (count != 0)
        DeleteAt(0);
}
