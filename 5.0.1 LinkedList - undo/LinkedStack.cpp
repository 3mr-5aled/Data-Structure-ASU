#include "LinkedList.h"

using namespace std;
template <class t>
LinkedList<t>::LinkedList()
{
    head = tail = nullptr;
    size = 0;
}

template <class t>
void LinkedList<t>::append(t value)
{
    Node<t> *n = new Node<t>(value);
    if (size == 0)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        tail = tail->next;
    }
    Undo<t> u(size, "append");
    s.push(u);
    size++;
}

template <class t>
void LinkedList<t>::insertAt(int pos, t value)
{
    assert(pos >= 0 && pos < size);
    Node<t> *n = new Node<t>(value);
    Node<t> *tmp = head;
    if (pos == 0)
    {
        n->next = head;
        head = n;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        n->next = tmp->next;
        tmp->next = n;
    }
    s.push(Undo<t>(pos, "insert"));
    size++;
}

template <class t>
void LinkedList<t>::deleteAt(int pos)
{
    assert(pos >= 0 && pos < size);
    Node<t> *tmp = head;
    if (pos == 0)
    {
        head = tmp->next;
        delete tmp;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            tmp = tmp->next;
        }
        Node<t> *d = tmp->next;
        Node<t> *newd = new Node<t>(d->data);
        s.push(Undo<t>(pos, "delete", newd));
        tmp->next = d->next;
        delete d;
        if (pos == size - 1)
        {
            tail = tmp;
        }
    }
    size--;
}

template <class t>
int LinkedList<t>::length()
{
    return size;
}

template <class t>
t LinkedList<t>::at(int pos)
{
    assert(pos >= 0 && pos < size);
    Node<t> *tmp = head;
    for (int i = 0; i < pos; i++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

template <class t>
void LinkedList<t>::display()
{
    Node<t> *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

template <class t>
void LinkedList<t>::moveNode(t value, int pos)
{
    Node<t> *tmp = head;
    int index = 0;
    while (tmp != NULL && tmp->data != value)
    {
        tmp = tmp->next;
        index++;
    }
    deleteAt(index);
    insertAt(pos, value);
    s.push(Undo<t>(-1, "move"));
}
template <class t>
void LinkedList<t>::undo()
{

    if (s.top().name == "append" || s.top().name == "insert")
    {
        deleteAt(s.top().pos);
        s.pop();
        s.pop();
        if (flag)
        {
            undo();
        }
    }
    else if (s.top().name == "delete")
    {
        if (s.top().pos == size)
        {
            append(s.top().nodes->data);
        }
        else
        {
            insertAt(s.top().pos, s.top().nodes->data);
        }
        s.pop();
        s.pop();
        if (flag)
        {
            flag = false;
        }
    }
    else if (s.top().name == "move")
    {
        flag = true;
        s.pop();
        undo();
    }
}
