#include <iostream>
#include <stack>
#include <string>

using namespace std;

string evaluateEditingString(const string &input)
{
    stack<char> edited;

    for (char ch : input)
    {
        if (ch == '#')
        {
            if (!edited.empty())
            {
                edited.pop();
            }
        }
        else if (ch == '$')
        {
            if (!edited.empty())
            {
                edited.push(edited.top());
            }
        }
        else
        {
            edited.push(ch);
        }
    }

    string reversed;
    while (!edited.empty())
    {
        reversed = edited.top() + reversed;
        edited.pop();
    }

    string finalForm;
    for (int i = static_cast<int>(reversed.size()) - 1; i >= 0; i--)
    {
        finalForm += reversed[i];
    }

    return finalForm;
}

int calculateCardGamePoints(const string &cards)
{
    stack<int> validRounds;
    int totalPoints = 0;

    for (char card : cards)
    {
        if (card == 'W')
        {
            validRounds.push(5);
            totalPoints += 5;
        }
        else if (card == 'D')
        {
            validRounds.push(10);
            totalPoints += 10;
        }
        else if (card == 'C')
        {
            totalPoints -= validRounds.top();
            validRounds.pop();
        }
        else if (card == 'S')
        {
            int lastRound = validRounds.top();
            validRounds.pop();
            int secondLastRound = validRounds.top();
            validRounds.push(lastRound);

            int lastTwoSum = lastRound + secondLastRound;
            validRounds.push(lastTwoSum);
            totalPoints += lastTwoSum;
        }
    }

    return totalPoints;
}

int main()
{
    string editString;
    cin >> editString;
    cout << evaluateEditingString(editString) << endl;

    int rounds;
    cin >> rounds;

    string cards;
    cards.reserve(rounds);
    for (int i = 0; i < rounds; i++)
    {
        char card;
        cin >> card;
        cards.push_back(card);
    }

    cout << calculateCardGamePoints(cards) << endl;

    return 0;
}