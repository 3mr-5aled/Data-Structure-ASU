#include <iostream>
#include <queue>

using namespace std;

template <class T>
queue<T> ReplaceQueue(queue<T> &q, int c, int r)
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        int current = q.front();
        if (current > c)
        {
            q.push(c);
        }
        else if (current == c)
        {
            q.push(r);
        }
        else
        {
            q.push(current);
        }
        q.pop();
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
    int arr[] = {2, 11, 3, 15, 10, 4};
    for (int x : arr)
        q.push(x);
    int c = 10;
    int r = 1;
    q = ReplaceQueue(q, c, r);

    printQueue(q);
    system("pause");
    return 0;
}
