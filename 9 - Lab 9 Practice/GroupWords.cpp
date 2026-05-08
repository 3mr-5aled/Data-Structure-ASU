#include <iostream>
#include <map>
#include <vector>

using namespace std;

void groupWords(vector<string> &words)
{
    map<string, vector<string>> grouped;
    // Sort characters in each word and use as a key in the map
    for (string word : words)
    {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end()); // Sort characters
        grouped[sortedWord].push_back(word);        // Store the original word
    }
    // Print grouped words
    for (auto &entry : grouped)
    {
        cout << "[ ";
        for (string w : entry.second)
        {
            cout << w << " ";
        }
        cout << "]" << endl;
    }
}

int main()
{

    vector<string> words = {"listen", "silent", "hello", "llohe", "abc", "cab", "bac"};
    groupWords(words);

    return 0;
}