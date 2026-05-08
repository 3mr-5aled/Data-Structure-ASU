/*
 * Linked List Cycle Detection - Brainstorming Discussion
 *
 * For Discussion:
 * 1. What would happen if we try to traverse the list normally?
 *    - If we traverse the list using a standard `while (curr != nullptr)` loop,
 *      we will enter an infinite loop because the `next` pointer of the last node
 *      will point back to a previous node, meaning we will never hit `nullptr`.
 *
 * 2. How could we detect that the list does not actually end?
 *    - We can detect a cycle by keeping track of the nodes we have already visited.
 *      If we encounter a node that is already in our completely visited collection,
 *      then a cycle exists! If we eventually reach a `nullptr`, we know it actually ends.
 *
 * 3. What ideas could help us identify repeated visits to the same node?
 *    - Hash Set (Visited Tracking): We can store the memory addresses/pointers of visited
 *      nodes in a hash set (`std::unordered_set<ListNode*>`). As we traverse, we check
 *      if the current node is already in the set.
 *    - Node Modification: We could add a `bool visited` flag to the node structure,
 *      or temporarily point visited nodes' `next` to a dummy node as we walk through.
 *
 * 4. Can this problem be solved using only the linked list itself, without modifying the nodes?
 *    - Yes! We can use Floyd's Cycle-Finding Algorithm (also known as the "Tortoise
 *      and Hare" algorithm). We use two pointers: a "slow" pointer that moves one
 *      node at a time, and a "fast" pointer that moves two nodes at a time. If there
 *      is a cycle, the fast pointer will eventually "lap" the slow pointer and they
 *      will meet pointing to the exact same node. This requires O(1) auxiliary space.
 *
 * Approaches: Advantages & Disadvantages
 * - Hash Set Approach:
 *      Advantage: Simple to understand and implement. Guaranteed to catch a cycle on the first lap.
 *      Disadvantage: Requires O(N) extra space/memory to store the pointers.
 * - Floyd's Cycle-Finding Algorithm (Two Pointers):
 *      Advantage: Extremely space-efficient, requiring O(N) time but O(1) auxiliary space.
 *      Disadvantage: Slightly trickier to conceptualize initially.
 */

#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Approach 1: Using a Hash Set
// Time Complexity: O(N)
// Space Complexity: O(N)
bool hasCycleHashSet(ListNode *head)
{
    unordered_set<ListNode *> visited;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        // If the node is already in the set, we've found a cycle!
        if (visited.count(curr))
        {
            return true;
        }
        // Otherwise, insert it and move to the next node
        visited.insert(curr);
        curr = curr->next;
    }

    return false; // Reached end of the list, no cycle
}

// Approach 2: Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
// Time Complexity: O(N)
// Space Complexity: O(1)
bool hasCycleFloyd(ListNode *head)
{
    // A list with 0 or 1 node without a cycle pointing to itself can't have a cycle
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    ListNode *slow = head; // Tortoise
    ListNode *fast = head; // Hare

    // Fast pointer moves 2 steps, so we must check both `fast` and `fast->next`
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Moves 1 step
        fast = fast->next->next; // Moves 2 steps

        if (slow == fast)
        {
            return true; // Fast pointer caught up to slow pointer -> Cycle!
        }
    }

    return false; // Fast pointer reached the end of the list -> No Cycle
}

int main()
{
    // Test Case: Create a list with a cycle: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Backreference creating cycle

    cout << "Testing with Floyd's Algorithm:\n";
    if (hasCycleFloyd(node1))
    {
        cout << "-> Cycle detected in the linked list!" << endl;
    }
    else
    {
        cout << "-> No cycle detected in the linked list." << endl;
    }

    // Memory cleanup omitted to avoid infinite loop when deleting cyclic nodes.
    // In a real application, you'd break the cycle first before cleaning up.

    return 0;
}
