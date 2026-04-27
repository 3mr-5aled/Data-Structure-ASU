// Lab7_Problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

// RemoveRange
void RemoveRange(set<int> &s, int L, int R)
{
    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        if (*it >= L && *it <= R)
        {
            it = s.erase(it);
        }
        else
        {
            it++;
        }
    }
}

// CountRange
int CountRange(set<int> &s, int L, int R)
{
    int count = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        if (*it >= L && *it <= R)
        {
            count++;
        }
    }
    return count;
}

int main()
{

    set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.insert(7);
    s.insert(9);
    s.insert(11);

    cout << "Original set: ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    int L = 4, R = 10;

    int result = CountRange(s, L, R);
    cout << "Count in range [" << L << ", " << R << "] = " << result << endl;

    RemoveRange(s, L, R);

    cout << "Set after removing range: ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
