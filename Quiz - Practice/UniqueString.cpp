#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<char> s;
    string str;
    cin >> str;

    s.push(str[0]);
    for (int i = 1; i < str.length(); i++)
    {
        if (s.top() == str[i])
        {
            s.pop();
        }
        else
        {
            s.push(str[i]);
        }
    }

    // stack<char> s2;
    // while (!s.empty())
    // {
    //     s2.push(s.top());
    //     s.pop();
    // }

    // while (!s2.empty())
    // {
    //     cout << s2.top();
    //     s2.pop();
    // }

    string result = "";
    while (!s.empty())
    {
        result = s.top() + result;
        s.pop();
    }
    cout << "Final String: " << result << endl;

    return 0;
}