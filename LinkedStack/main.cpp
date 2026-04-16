#include "LinkedStack.cpp"
#include "LinkedStack.h"
#include <iostream>
#include <string>
using namespace std;

string ReverseEachWordUsingLinkedStack(const string &sentence)
{
    LinkedStack<char> charStack;
    string result;

    for (size_t i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            // Push chars of the current word.
            charStack.Push(sentence[i]);
        }
        else
        {
            // Space is the trigger: pop all chars to reverse the word.
            while (!charStack.isEmpty())
                result += charStack.Pop();
            result += ' ';
        }
    }

    // Important: flush the final word if sentence does not end with space.
    while (!charStack.isEmpty())
        result += charStack.Pop();

    return result;
}

void BrainstormWordReverseUsingStack()
{
    string input = "Data Structures";
    string output = ReverseEachWordUsingLinkedStack(input);

    cout << "Input:  " << input << endl;
    cout << "Output: " << output << endl;
    cout << "Trigger used to pop: space character and end of sentence." << endl;
    cout << "Why linked stack is flexible: dynamic nodes grow as needed for long/unknown words." << endl;
}

int main()
{
    // Old demo kept for basic stack operations.
    LinkedStack<int> s;
    s.Push(5);
    s.Push(8);
    s.Pop();
    s.Push(10);
    if (s.isEmpty())
    {
        cout << "The LinkedStack is now empty!\n";
        s.Push(35);
    }

    cout << "\n";
    BrainstormWordReverseUsingStack();
    return 0;
}
