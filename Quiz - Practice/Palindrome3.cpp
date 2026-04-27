#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
    stack<int> s;
    queue<int> q;
    int n = str.length();
    for (size_t i = 0; i < n; i++)
    {
        s.push(str[i]);
        q.push(str[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (q.front() == s.top())
        {
            s.pop();
            q.pop();
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{

    string str;
    cin >> str;

    bool status = isPalindrome(str);

    if (status)
        cout << "is Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}