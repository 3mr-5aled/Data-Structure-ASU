#include <iostream>
#include <stack>
#include <string>

using namespace std;

void RepeatFunction(string str)
{
    stack<int> num;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (i % 2 == 0)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                cout << "Invalid Input" << endl;
                return;
            }

            num.push(str[i] - '0');
        }
        else
        {
            int repeatCount = num.top();
            num.pop();

            for (int j = 0; j < repeatCount; j++)
            {
                cout << str[i];
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