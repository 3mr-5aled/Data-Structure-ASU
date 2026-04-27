#include <iostream>
#include <deque>
#include <string>

using namespace std;

bool isPalindrome(deque<char> dq)
{
    while (!dq.empty())
    {
        if (dq.front() != dq.back())
        {
            return false;
        }
        else
        {
            dq.pop_back();
            dq.pop_front();
        }
    }

    return true;
}

int main()
{

    deque<char> dq;
    string str;
    cin >> str;

    for (char x : str)
        dq.push_back(x);

    bool status = isPalindrome(dq);

    if (status)
        cout << "is Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}