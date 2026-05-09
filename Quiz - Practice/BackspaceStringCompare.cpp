#include <iostream>
#include <stack>

using namespace std;

void BackspaceCompare(string str)
{
    stack<int> s1;
    stack<int> s2;
    bool secondInput = false;
    for (char w : str)
    {
        if (w == ' ')
            secondInput = true;

        if (!secondInput)
        {
            if (w == '#')
            {
                if (!s1.empty())
                {
                    s1.pop();
                }
            }
            s1.push(w);
        }
        else
        {

            if (w == '#')
            {
                if (!s2.empty())
                {
                    s2.pop();
                }
            }
            s2.push(w);
        }
    }

    bool same = true;
    while (!s1.empty())
    {
        if (s1.top() != s2.top())
        {
            same = false;
            break;
        }
        else
        {
            s1.pop();
            s2.pop();
        }
    }

    if (same)
        cout << "Identical" << endl;
    else
        cout << "Different" << endl;
}

int main()
{

    string str = "ab#c ad#c";
    BackspaceCompare(str);
    string str2 = "abb#c adb#c";
    BackspaceCompare(str2);

    system("pause");
    return 0;
}
