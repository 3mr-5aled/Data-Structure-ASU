#include <iostream>
#include <stack>
#include <string>

using namespace std;

void RepeatFunction(string str)
{
    stack<int> num;
    for (size_t i = 0; i < str.length(); i++)
    {
        int current = str[i];

        if (isalpha(current))
        {
            s.push(current);
        }
        else if (isdigit(current))
        {
            int repeatCount = current - '0'; // Convert char to int

            if (!s.empty())
            {
                char charToRepeat = s.top();
                s.pop();

                for (int j = 0; j < repeatCount; j++)
                {
                    cout << charToRepeat << " ";
                }
            }
        }
    }

    cout << endl;
}

int main()
{
    string input;
    while (true)
    {
        cin >> input;
        if (input == "-1")
        {
            break;
        }
        RepeatFunction(input);
    }

    return 0;
}