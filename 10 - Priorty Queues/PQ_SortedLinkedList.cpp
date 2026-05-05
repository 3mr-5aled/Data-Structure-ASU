class PQ_SortedLL
{
    Node *head;

public:
    PQ_SortedLL() { head = NULL; }

    void insert(int val)
    {
        Node *temp = new Node{val, NULL};

        if (!head || head->data < val)
        {
            temp->next = head;
            head = temp;
            return;
        }

        Node *curr = head;
        while (curr->next && curr->next->data >= val)
            curr = curr->next;

        temp->next = curr->next;
        curr->next = temp;
    }

    int remove()
    {
        if (!head)
            return -1;
        Node *temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        return val;
    }
};