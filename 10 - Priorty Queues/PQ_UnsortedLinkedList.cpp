struct Node
{
    int data;
    Node *next;
};

class PQ_UnsortedLL
{
    Node *head;

public:
    PQ_UnsortedLL() { head = NULL; }

    void insert(int val)
    {
        Node *temp = new Node{val, head};
        head = temp;
    }

    int remove()
    {
        if (!head)
            return -1;

        Node *maxNode = head, *prev = NULL;
        Node *curr = head, *prevMax = NULL;

        while (curr)
        {
            if (curr->data > maxNode->data)
            {
                maxNode = curr;
                prevMax = prev;
            }
            prev = curr;
            curr = curr->next;
        }

        if (prevMax)
            prevMax->next = maxNode->next;
        else
            head = head->next;

        int val = maxNode->data;
        delete maxNode;
        return val;
    }
};