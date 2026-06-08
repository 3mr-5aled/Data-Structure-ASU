#include <iostream>
#include <queue>

using namespace std;

void simulateCardDeck(int n)
{
    queue<int> deck;
    queue<int> discarded;

    for (int i = 1; i <= n; i++)
    {
        deck.push(i);
    }

    while (deck.size() >= 2)
    {
        discarded.push(deck.front());
        deck.pop();

        deck.push(deck.front());
        deck.pop();
    }

    cout << "Discarded cards: ";
    while (!discarded.empty())
    {
        cout << discarded.front();
        discarded.pop();

        if (!discarded.empty())
        {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "Remaining card: " << deck.front() << endl;
}

template <class T>
queue<T> replace(queue<T> inputQueue, T v1, T v2)
{
    int count = static_cast<int>(inputQueue.size());

    while (count > 0)
    {
        T current = inputQueue.front();
        inputQueue.pop();

        if (current == v1)
        {
            current = v2;
        }

        inputQueue.push(current);
        count--;
    }

    return inputQueue;
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front();
        q.pop();

        if (!q.empty())
        {
            cout << ' ';
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    simulateCardDeck(n);

    int size;
    cin >> size;

    queue<int> values;
    for (int i = 0; i < size; i++)
    {
        int value;
        cin >> value;
        values.push(value);
    }

    int v1, v2;
    cin >> v1 >> v2;

    queue<int> modified = replace(values, v1, v2);
    printQueue(modified);

    return 0;
}