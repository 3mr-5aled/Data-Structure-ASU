#include <iostream>
#include <stack>
#include <string>

using namespace std;

void Compare(string str)
{
    stack<char> s1;
    stack<char> s2;

    bool isString2 = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            isString2 = true;
        if (!isString2)
        {
            if (str[i] == '#')
            {
                s1.pop();
            }
            else
            {
                s1.push(str[i]);
            }
        }
        else
        {
            if (str[i] == '#')
            {
                s2.pop();
            }
            else
            {

                s2.push(str[i]);
            }
        }
    }
    bool isIdentical = true;
    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() == s2.top())
        {
            s1.pop();
            s2.pop();
        }
        else
        {
            isIdentical = false;
            break;
        }
    }
    if (isIdentical)
        cout << "Identical" << endl;
    else
        cout << "Different" << endl;
}

int main()
{

    string input;
    while (true)
    {
        getline(cin, input);
        if (input == "-1")
        {
            break;
        }
        if (input.empty())
        {
            continue;
        }
        Compare(input);
    }

    return 0;
}