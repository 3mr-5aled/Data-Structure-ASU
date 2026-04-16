#include "LinkedQueue.cpp"
#include "LinkedQueue.h"
#include <iostream>
#include <string>
using namespace std;

string PreserveSentenceUsingLinkedQueue(const string &sentence)
{
    LinkedQueue<char> charQueue;
    string result;

    for (size_t i = 0; i < sentence.length(); i++)
    {
        charQueue.Enqueue(sentence[i]);
    }

    while (!charQueue.isEmpty())
        result += charQueue.Dequeue();

    return result;
}

void BrainstormSentenceUsingQueue()
{
    string input = "Data Structures";
    string output = PreserveSentenceUsingLinkedQueue(input);

    cout << "Input:  " << input << endl;
    cout << "Output: " << output << endl;
    cout << "Trigger used to dequeue: reading until queue becomes empty." << endl;
    cout << "Why linked queue is flexible: dynamic nodes grow as needed for unknown stream size." << endl;
}

int main()
{
    // Old demo kept for basic queue operations.
    LinkedQueue<int> q;
    q.Enqueue(5);
    q.Enqueue(8);
    q.Dequeue();
    q.Enqueue(10);

    if (q.isEmpty())
    {
        cout << "The LinkedQueue is now empty!\n";
        q.Enqueue(35);
    }

    cout << "\n";
    BrainstormSentenceUsingQueue();
    return 0;
}
