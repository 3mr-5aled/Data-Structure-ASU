#include <iostream>
#include <queue>

using namespace std;

void rotateQueue(queue<int> &q, int k)
{
    int n = q.size();
    k = k % n; // Handle cases where k is greater than the size of the queue

    for (int i = 0; i < k; i++)
    {
        int frontElement = q.front();
        q.pop();
        q.push(frontElement);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    queue<int> q2 = q;

    rotateQueue(q, 3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    rotateQueue(q2, 7);
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }

    return 0;
}