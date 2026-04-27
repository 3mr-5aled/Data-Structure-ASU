#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countRepeatedAlerts(const vector<int> &zones, int K)
{
    unordered_map<int, int> lastSeen;
    int count = 0;

    for (int i = 0; i < zones.size(); i++)
    {
        int zone = zones[i];
        if (lastSeen.find(zone) != lastSeen.end())
        {
            if (i - lastSeen[zone] <= K)
            {
                count++;
            }
        }
        lastSeen[zone] = i;
    }
    return count;
}

int main()
{

    vector<int> zones = {1, 3, 1, 4, 1, 3};
    int K = 2;

    cout << "Zone counts:" << countRepeatedAlerts(zones, K) << endl;

    return 0;
}