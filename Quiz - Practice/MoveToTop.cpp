#include <iostream>
#include <stack>

using namespace std;

void moveToTop(stack<int> &s, int k)
{
    stack<int> temp, temp2;
    int target;
    if (k > s.size() - 1 || k < 0)
    {
        cout << "Error index";
        return;
    }

    int n = s.size(); // Store original size

    // Extract element at index k
    for (int i = 0; i < n; i++) // Use n instead of s.size()
    {
        if (i == k)
        {
            target = s.top();
            s.pop();
            break;
        }
        else
        {
            temp.push(s.top());
            s.pop();
        }
    }

    // Reverse temp into temp2
    while (!temp.empty())
    {
        temp2.push(temp.top());
        temp.pop();
    }

    // Push back in correct order
    while (!temp2.empty())
    {
        s.push(temp2.top());
        temp2.pop();
    }

    // Push target on top
    s.push(target);
}

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int index = 3;
    stack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);

    display(s);
    moveToTop(s, index);
    display(s);

    return 0;
}