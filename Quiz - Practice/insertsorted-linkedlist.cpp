template <class T>
void LinkedList::insertSorted(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if (size == 0)
    {
        head = tail = newNode;
        size++;
    }
    else if (val < head->value)
    {
        newNode->next = head;
        head = newNode;
        size++;
    }
    else if (val > tail->value)
    {
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    else
    {
        Node<v> *temp = head;
        Node<v> *tempNext = temp->next;
        Node<v> *newNode = new Node<v>(val);
        for (int i = 0; i < size - 1; i++)
        {
            if (val >= temp->value && val < tempNext->value)
            {
                newNode->next = tempNext;
                temp->next = newNode;
                size++;
                break;
            }
            temp = temp->next;
            tempNext = temp->next;
        }
    }
}