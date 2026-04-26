#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> modifyQueue(queue<int> &q)
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        int current = q.front();
        q.pop();

        if (current % 2 == 0)
        {
            if (current < 10)
            {
                q.push(0);
            }
            else
            {
                q.push(current);
            }
        }
    }

    return q;
}

void printQueue(queue<int> q)
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
    int arr[] = {21, 24, 1, 200, 8, 99, 110};
    for (int x : arr)
        q.push(x);

    q = modifyQueue(q);

    printQueue(q);

    return 0;
}