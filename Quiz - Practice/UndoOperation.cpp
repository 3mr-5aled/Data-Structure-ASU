#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack<char> s;
    stack<char> s2;
    for (int i = 0; i < 8; i++)
    {
        char temp;
        cin >> temp;
        if (temp == '1')
        {
            if (s.empty())
                cout << "Error!!" << endl;
            else
                s.pop();
        }
        else
        {
            s.push(temp);
        }
    }

    while (!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}