#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "CircularLinkedList.h"
#include "CircularLinkedList.cpp"
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"

using namespace std;

void BrainstormCycleDetection()
{
    cout << "\n=== Brainstorm: Detecting a cycle in a singly linked list ===\n";
    cout << "1) Normal traversal only: move node by node until NULL.\n";
    cout << "   - Problem: if there is a cycle, traversal never reaches NULL (infinite loop).\n";
    cout << "   - Advantage: simplest idea.\n";
    cout << "   - Disadvantage: cannot safely confirm a cycle by itself.\n\n";

    cout << "2) Keep visited node addresses in another structure.\n";
    cout << "   - If we visit an address again, a cycle exists.\n";
    cout << "   - Advantage: easy to understand.\n";
    cout << "   - Disadvantage: extra memory O(n), needs external storage.\n\n";

    cout << "3) Floyd's tortoise and hare (two pointers).\n";
    cout << "   - Slow moves 1 step, fast moves 2 steps.\n";
    cout << "   - If they meet, cycle exists; if fast reaches NULL, no cycle.\n";
    cout << "   - Advantage: O(1) extra space, no node modification.\n";
    cout << "   - Disadvantage: less intuitive than visited set.\n\n";

    LinkedList<int> demo;
    demo.Append(1);
    demo.Append(2);
    demo.Append(3);
    demo.Append(4);

    cout << "Demo before creating cycle: "
         << (demo.HasCycle() ? "Cycle found" : "No cycle") << endl;

    demo.CreateCycleToPosition(1); // 4 points back to node 2

    cout << "Demo after creating cycle (1 -> 2 -> 3 -> 4 -> 2 ...): "
         << (demo.HasCycle() ? "Cycle found" : "No cycle") << endl;

    demo.BreakCycle();
}

void summedList(LinkedList<int> &l)
{
    if (l.head == nullptr || l.head->next == nullptr)
    {
        return;
    }
    Node<int> *curr = l.head;

    while (curr->next != nullptr)
    {
        curr->value += curr->next->value;
        if (curr->next->next == nullptr)
        {
            delete curr->next;
            curr->next = nullptr;
            l.tail = curr;
            l.count--;
            break;
        }

        curr = curr->next;
    }

    // display list
    Node<int> *temp = l.head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DemoCircularLinkedList()
{
    CircularLinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.InsertAt(1, 99);
    list.DeleteAt(2);
    list.Reverse();

    cout << "Circular linked list:" << endl;
    list.Display();
}

void DemoDoublyLinkedList()
{
    DoublyLinkedList<int> list;
    list.Append(10);
    list.Append(20);
    list.Append(30);
    list.InsertAt(1, 15);
    list.DeleteAt(2);
    list.Reverse();

    cout << "Doubly linked list:" << endl;
    list.Display();
}

int main()
{
    LinkedList<int> L;
    L.Append(9);
    L.Append(10);
    L.Append(11);
    L.InsertAt(1, 100);
    L.DeleteAt(3);

    L.Reverse();

    for (int i = 0; i < L.Length(); i++)
        cout << L.At(i) << endl;

    BrainstormCycleDetection();

    LinkedList<int> l;
    l.Append(2);
    l.Append(4);
    l.Append(6);
    l.Append(3);
    l.Append(3);

    summedList(l);

    cout << "\n=== Circular and Doubly Linked List Demos ===\n";
    DemoCircularLinkedList();
    DemoDoublyLinkedList();

    return 0;
}