#include <iostream>
#include <stack>

using namespace std;

template <class T>
T firstNonRepeating(stack<T> &s)
{
    stack<T> original = s;
    stack<T> processed;
    stack<T> temp;

    while (!original.empty())
    {
        T current = original.top();
        original.pop();

        bool isRepeated = false;

        // Check in the remaining unexplored elements
        while (!original.empty())
        {
            if (original.top() == current)
                isRepeated = true;

            temp.push(original.top());
            original.pop();
        }

        // Restore unexplored elements
        while (!temp.empty())
        {
            original.push(temp.top());
            temp.pop();
        }

        // Check in the already processed elements
        while (!processed.empty())
        {
            if (processed.top() == current)
                isRepeated = true;

            temp.push(processed.top());
            processed.pop();
        }

        // Restore processed elements
        while (!temp.empty())
        {
            processed.push(temp.top());
            temp.pop();
        }

        if (!isRepeated)
        {
            return current;
        }

        processed.push(current);
    }

    return (T)-1;
}

int main()
{
    stack<int> s;

    // 4 , 5 , 4 , 6 , 5

    s.push(5);
    s.push(6);
    s.push(4);
    s.push(5);
    s.push(4);

    cout << firstNonRepeating(s) << endl;

    return 0;
}