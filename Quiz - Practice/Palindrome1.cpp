#include <iostream>
#include <stack>

using namespace std;

void checkPalindrome(string str)
{
    stack<char> s;
    bool isPalindrome = true;
    for (char w : str)
    {
        s.push(w);
    }

    for (char w : str)
    {
        if (w != s.top())
        {
            isPalindrome = false;
            break;
        }

        s.pop();
    }

    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
}

int main()
{

    string str = "abccba";
    checkPalindrome(str);

    string str2 = "abcabc";
    checkPalindrome(str2);

    return 0;
}
