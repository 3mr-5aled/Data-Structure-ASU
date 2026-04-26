#include <iostream>
#include <string>
#include <stack>

using namespace std;

void checkPalindrome(string str)
{
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != s.top())
        {
            cout << "Not Palindrome" << endl;
            return;
        }
        s.pop();
    }

    cout << "Palindrome" << endl;
}

int main()
{
    string input;
    while (true)
    {
        cin >> input;
        if (input == "-1")
            break;
        checkPalindrome(input);
    }

    return 0;
}