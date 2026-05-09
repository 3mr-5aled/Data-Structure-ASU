#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = next = nullptr;
    }
};

void reverse(Node *&head)
{
    Node *temp = nullptr;
    Node *current = head;

    while (current != nullptr)
    {
        // swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // move to next node (which is prev after swap)
        current = current->prev;
    }

    // update head
    if (temp != nullptr)
        head = temp->prev;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    cout << "Original: ";
    print(head);

    reverse(head);

    cout << "Reversed: ";
    print(head);
}
