#include <iostream>
#include <queue>

using namespace std;

queue<int> Inventory(queue<int> q)
{
    queue<int> finalQ;
    while (!q.empty())
    {
        int current = q.front();
        if (current % 2 == 0)
        {
            if (current < 20)
                finalQ.push(0);
            else
                finalQ.push(current);
        }
        q.pop();
    }

    return finalQ;
}

void DisplayQueue(queue<int> q)
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
    q.push(15);
    q.push(8);
    q.push(22);
    q.push(3);
    q.push(6);

    DisplayQueue(q);

    q = Inventory(q);

    DisplayQueue(q);

    return 0;
}