#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int> span(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && prices[st.top()] <= prices[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - st.top();
        }

        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << span[i];
        if (i + 1 < n)
        {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}