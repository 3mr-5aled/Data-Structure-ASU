#include <iostream>
#include <stack>

using namespace std;

bool checkPalindrome(const string &str)
{
    stack<char> s;
    for (char c : str)
    {
        s.push(c);
    }

    for (char c : str)
    {
        if (s.top() != c)
        {
            return false; // Not a palindrome
        }
        s.pop();
    }
    return true; // Is a palindrome
}

int main()
{

    string str;
    cout << "Enter a string: ";
    cin >> str;
    bool isPalindrome = checkPalindrome(str);
    if (isPalindrome)
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}