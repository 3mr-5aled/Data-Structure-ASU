#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{

    unordered_map<char, int> wordCounter; // Create an empty unordered_map.
    string sentence = "";
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    unordered_map<char, int>::iterator it;
    for (int i = 0; i < sentence.length(); i++)
    {
        char letter = sentence[i];
        it = wordCounter.find(letter);
        if (it != wordCounter.end())
        {
            it->second++;
        }
        else
        {
            wordCounter[letter] = 1;
        }
    }

    for (it = wordCounter.begin(); it != wordCounter.end(); it++)
    {
        cout << it->first << " -> " << it->second << endl;
    }

    return 0;
}