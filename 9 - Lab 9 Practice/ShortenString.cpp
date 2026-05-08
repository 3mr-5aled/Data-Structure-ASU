#include <iostream>
#include <stack>
#include <string>

using namespace std;

string shortenString(string str1)
{
    // Store the string without duplicate elements
    stack<char>
        st;
    int i = 0;
    // Traverse the string str
    while (i < str1.length())
    {
        // Checks if stack is empty or top of the stack is not equal to current character
        if (st.empty() || str1[i] != st.top())
        {
            st.push(str1[i]);
            i++;
        }
        // If top element of the stack is equal to the current character
        else
        {
            st.pop();
            i++;
        }
    }
    if (st.empty())
    {
        return ("Empty String");
    }
    // If stack is not Empty
    else
    {
        string short_string = "";
        while (!st.empty())
        {
            short_string = st.top() +
                           short_string;
            st.pop();
        }
        return (short_string);
    }
}

int main()
{
    cout << shortenString("azxxzy") << endl;
    cout << shortenString("aaccdd") << endl;

    return 0;
}