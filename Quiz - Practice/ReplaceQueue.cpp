#include <iostream>
#include <queue>

using namespace std;

queue<int> replace(queue<int> &q, int c, int r)
{
    queue<int> newQueue;
    while (!q.empty())
    {
        if (q.front() > c)
        {
            newQueue.push(c);
        }
        else if (q.front() == c)
        {
            newQueue.push(r);
        }
        else
        {
            newQueue.push(q.front());
        }
        q.pop();
    }

    return newQueue;
}

void displayQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    int arr[] = {2, 11, 3, 15, 10, 4};
    for (int x : arr)
        q.push(x);
    int c = 10, r = 1;
    cout << "c= " << c << ", r=" << r << endl;

    displayQueue(q);
    q = replace(q, c, r);
    displayQueue(q);

    return 0;
}