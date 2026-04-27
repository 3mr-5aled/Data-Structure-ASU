#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    stack<char> editorStack;
    char input;

    cout << "Enter characters (use '1' to undo, 'q' to finish):" << endl;

    while (cin >> input && input != 'q')
    {
        if (input == '1')
        {
            if (!editorStack.empty())
            {
                editorStack.pop(); // Undo operation
            }
        }
        else
        {
            editorStack.push(input); // Add character
        }
    }
    stack<char> copyStack = editorStack; // Create a copy to print without modifying original stack

    while (!copyStack.empty())
    {
        cout << copyStack.top(); // Print current top character
        copyStack.pop();
    }

    // Since a stack is LIFO, we extract to a string to print in correct order
    string result = "";
    while (!editorStack.empty())
    {
        result = editorStack.top() + result;
        editorStack.pop();
    }

    cout << "Final Text: " << result << endl;

    return 0;
}