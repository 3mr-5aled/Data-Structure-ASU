#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countPairs(const vector<int> &skills, int target)
{
    unordered_map<int, int> skillCount;
    int count = 0;

    for (int skill : skills)
    {
        int complement = target - skill;
        if (skillCount.find(complement) != skillCount.end())
        {
            count += skillCount[complement];
        }
        skillCount[skill]++;
    }

    return count;
}

int main()
{

    vector<int> skills = {10, 20, 35, 40, 50};
    int target = 60;

    cout << "Number of valid pairs: " << countPairs(skills, target) << endl;

    return 0;
}