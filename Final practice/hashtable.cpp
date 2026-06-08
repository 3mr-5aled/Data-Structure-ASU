#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, int> freq;
    string str = "helloworld";

    for (char c : str)
    {
        freq[c]++;
    }

    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ")" << endl;
    }

    return 0;
}