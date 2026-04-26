#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string &s)
{
    stack<char> temp;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            temp.push(s[i]);
        else if (s[i] == ')')
        {
            if (temp.empty())
                return false;

            temp.pop();
        }
    }

    return temp.empty();
}

int main()
{
    string s1 = "(()";
    string s2 = ")(";
    string s3 = "((()))";

    cout << (isBalanced(s1) ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced(s2) ? "Balanced" : "Not Balanced") << endl;
    cout << (isBalanced(s3) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}