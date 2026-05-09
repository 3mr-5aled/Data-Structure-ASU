#include <iostream>
#include <queue>

using namespace std;

int firstNonRepeated(queue<int> q)
{
    if (q.empty())
    {
        return 0;
    }

    int n = q.size();
    for (int i = 0; i < n; ++i)
    {
        int current = q.front();
        q.pop();
        q.push(current);

        int count = 0;
        for (int j = 0; j < n; ++j)
        {
            int value = q.front();
            q.pop();
            if (value == current)
            {
                ++count;
            }
            q.push(value);
        }

        if (count == 1)
        {
            return current;
        }
    }

    return 0;
}

int main()
{

    queue<int> q;

    q.push(4);
    q.push(5);
    q.push(4);
    q.push(6);
    q.push(5);

    cout << firstNonRepeated(q);

    return 0;
}
