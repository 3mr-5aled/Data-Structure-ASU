#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

    unordered_map<char, int> LetterCounter;
    string str = "helloworld";

    unordered_map<char, int>::iterator it;
    for (int i = 0; i < str.length(); i++)
    {
        it = LetterCounter.find(str[i]);
        if (it != LetterCounter.end())
        {
            LetterCounter[str[i]]++;
        }
        else
        {
            LetterCounter[str[i]] = 1;
        }
    }

    for (auto it = LetterCounter.begin(); it != LetterCounter.end(); it++)
    {
        cout << it->first << "," << it->second << endl;
    }

    return 0;
}