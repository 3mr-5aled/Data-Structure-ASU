#include <iostream>
#include <stack>
#include <string>

using namespace std;

void checkBalance(string str)
{
    stack<char> s;
    bool isBalanced = true;
    for (int i = 0; i < str.length(); i++)
    {
        char current = str[i];
        if (str[i] == '(')
            s.push(current);
        else
        {
            if (!s.empty())
                s.pop();
            else
            {
                isBalanced = false;
                break;
            }
        }
    }

    if (isBalanced && s.empty())
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
}

int main()
{
    cout << "Enter your brackets: " << endl;
    while (true)
    {
        string input;
        cin >> input;
        if (input == "-1")
            break;

        checkBalance(input);
    }

    return 0;
}