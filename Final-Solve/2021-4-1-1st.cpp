#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{

    // if card drawn = stack.top -> stack.pop
    // win when stack.length <= 3
    stack<char> pile;
    int n;
    cout << "Enter number of cards: ";
    cin >> n;
    string cards;
    cin >> cards;
    bool status = false;

    for (int i = 0; i < n; i++)
    {
        if (pile.size() == 0)
        {
            pile.push(cards[i]);
        }
        else if (cards[i] == pile.top())
        {
            pile.pop();
        }
        else
        {
            pile.push(cards[i]);
        }
    }

    if (pile.size() <= 3)
    {
        status = true;
    }

    // if win print
    cout << "Status: ";
    if (status)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    cout << "Remaining: " << pile.size() << endl;

    return 0;
}