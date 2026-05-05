#include <iostream>
#include <queue>
using namespace std;

int main()
{

    // Max-Heap Priority Queue using STL
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    cout << "Max-Heap Priority Queue: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    // Min-Heap Priority Queue using STL
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    min_pq.push(5);
    cout << "\nMin-Heap Priority Queue: ";
    while (!min_pq.empty())
    {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }

    return 0;
}
