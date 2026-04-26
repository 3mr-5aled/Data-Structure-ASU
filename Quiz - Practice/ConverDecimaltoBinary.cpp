#include <iostream>
#include <stack>

using namespace std;

void calcBinary(int num)
{
    stack<int> temp;

    while (num != 0)
    {
        temp.push(num % 2);
        num /= 2;
    }
    while (!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }
    cout << endl;
}

int main()
{

    int num;
    while (true)
    {
        cout << "enter a number to convert:" << endl;
        cin >> num;
        if (num == -1)
            break;
        calcBinary(num);
    }

    return 0;
}