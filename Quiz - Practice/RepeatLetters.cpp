#include <iostream>
#include <stack>

using namespace std;

void RepeatLetter(string str)
{
    stack<int> s;
    for (char w : str)
    {
        if (w < '9' && w > '0')
        {
            s.push(w - '0');
        }
        else
        {
            if (!s.empty())
            {
                int count = s.top();
                for (int i = 0; i < count; i++)
                {
                    cout << w << " ";
                }
                s.pop();
            }
        }
    }
    cout << endl;
}

int main()
{

    string str = "3a2b1c";
    RepeatLetter(str);

    system("pause");
    return 0;
}
