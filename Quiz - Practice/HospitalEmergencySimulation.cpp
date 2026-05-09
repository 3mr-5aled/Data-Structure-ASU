#include <iostream>
#include <queue>

using namespace std;

template <class T>
void printQueue(queue<T> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void Emergency(queue<int> &q, int numOfRooms)
{

    int size = q.size();

    for (int i = 0; i < size; i++)
    {
        int current = q.front();
        if (numOfRooms > 0)
        {
            if (current == 1)
            {
                q.pop();
            }
            else if (current == 2)
            {
                int temp = current;
                q.pop();
                if (q.front() == 1)
                {
                    q.pop();
                    q.push(temp);
                }
            }
            else if (current == 3)
            {
                int temp = current;
                q.pop();
                if (q.front() == 2 || q.front() == 1)
                {
                    q.pop();
                    q.push(temp);
                }
            }
            numOfRooms--;
        }
    }

    printQueue(q);
}

int main()
{
    int numOfRooms = 5;
    queue<int> q;
    int arr[] = {3, 2, 1, 3, 2, 1, 1};
    for (int x : arr)
        q.push(x);

    Emergency(q, numOfRooms);

    system("pause");
    return 0;
}
