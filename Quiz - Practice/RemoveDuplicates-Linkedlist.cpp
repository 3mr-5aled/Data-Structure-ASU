template <class T>
void LinkedList::RemoveDuplicates(T val)
{
    Node<T> *temp = head;
    Node<T> *del;
    for (int i = 0; i < size - 1; i++)
    {
        del = temp->next;
        for (int j = 0; j < size; j++)
        {
            if (temp->value == del->value)
            {
                del = del->next;
                deleteAt(j);
                j--;
            }
            else
            {
                del = del->next;
            }
        }
        temp = temp->next;
    }
}