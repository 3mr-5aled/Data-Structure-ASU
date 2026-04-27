#include <iostream>
#include <stack>
#include <string>

using namespace std;

void browserNavigation()
{
    stack<string> s;
    while (true)
    {
        string command;
        cout << "Enter command (VISIT <URL>/BACK/EXIT):" << endl;
        cin >> command;
        if (command == "VISIT")
        {
            string url;
            cin >> url;
            cout << "Current Page: " << url << endl;
            s.push(url);
        }
        else if (command == "BACK")
        {
            if (!s.empty())
            {
                s.pop();
                if (!s.empty())
                {
                    cout << "Current Page: " << s.top() << endl;
                }
                else
                {
                    cout << "No pages left" << endl;
                }
            }
            else
            {
                cout << "No pages left" << endl;
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
    }
}

int main()
{
    browserNavigation();
    return 0;
}