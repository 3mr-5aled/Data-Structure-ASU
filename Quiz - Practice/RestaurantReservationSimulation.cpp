#include <iostream>
#include <queue>
#include <string>

using namespace std;

void simulateRestaurant(string input)
{
    queue<char> q;

    for (char cmd : input)
    {
        if (cmd == 'v')
        {
            // VIP arrives, gets order, and leaves immediately.
            // We do nothing to the queue.
            continue;
        }
        else if (cmd == 'd')
        {
            // Up to three customers receive orders and leave.
            for (int i = 0; i < 3; i++)
            {
                if (!q.empty())
                {
                    q.pop();
                }
                else
                {
                    break; // Queue is empty, stop serving.
                }
            }
        }
        else
        {
            // Normal customer joins the queue.
            q.push(cmd);
        }
    }

    // Display remaining customers
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    cout << endl;
}

int main()
{
    string input;
    // Example Input: abcevfdv
    if (cin >> input)
    {
        simulateRestaurant(input);
    }
    return 0;
}