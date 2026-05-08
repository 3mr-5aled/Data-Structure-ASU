#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Simulates text editor with undo ('1')
string processEditor(const string &input)
{
    stack<char> editor;

    for (char ch : input)
    {
        if (ch == ' ')
        {
            continue; // ignore spaces
        }
        else if (ch == '1')
        {
            // Undo operation
            if (!editor.empty())
            {
                editor.pop();
            }
        }
        else
        {
            // Add character
            editor.push(ch);
        }
    }

    // Build result in correct order
    string result;
    while (!editor.empty())
    {
        result = editor.top() + result; // prepend
        editor.pop();
    }

    return result;
}

int main()
{
    string input;
    getline(cin, input); // stop on Enter

    string output = processEditor(input);

    for (char ch : output)
    {
        cout << ch << " ";
    }

    return 0;
}