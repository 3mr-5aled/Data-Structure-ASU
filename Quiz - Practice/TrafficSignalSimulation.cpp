#include <iostream>
#include <queue>
#include <string>
#include <cassert>

using namespace std;

int main()
{
    string str;
    queue<char> q;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'y')
        {
            q.pop();
        }
        else if (str[i] == 'g')
        {
            for (int i = 0; i < 3; i++)
            {
                if (!q.empty())
                    q.pop();
                else
                    break;
            }
        }
        else if (str[i] == 'r')
        {
            continue;
        }
        else
        {
            q.push(str[i]);
        }
    }

    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }

    return 0;
}