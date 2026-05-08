#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void groupWords(vector<string> &words)
{
    map<string, vector<string>> grouped;

    for (string word : words)
    {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end()); // sort characters
        grouped[sortedWord].push_back(word);        // store original word
    }

    for (auto &entry : grouped)
    {
        cout << "[";
        for (string w : entry.second)
        {
            cout << w << " , ";
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