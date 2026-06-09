#include <iostream>
#include <queue>

using namespace std;

queue<int> remove(queue<int> &q, int val)
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        int current = q.front();
        q.pop();
        if (current != val)
        {
            q.push(current);
        }
    }
    return q;
}

int main()
{

    queue<int> q;
    q.push(1);
    q.push(5);
    q.push(8);
    q.push(9);
    q.push(4);
    q.push(4);
    q.push(1);
    q.push(2);

    q = remove(q, 4);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}