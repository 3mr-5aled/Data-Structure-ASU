#include <iostream>
#include <unordered_map>

using namespace std;

int RepeatedAlert(vector<int> &zones, int k)
{
    unordered_map<int, int> lastSeen;
    int count = 0;

    for (int i = 0; i < zones.size(); i++)
    {
        int z = zone[i];
        if (lastSeen.find(z) != lastSeen.end())
        {
            if (i - lastSeen[z] <= k)
            {
                count++;
            }
        }
        lastSeen[z] = i;
    }
    return count;
}

int main()
{

    vector<int> zones = {1, 3, 1, 4, 1, 3};
    int k = 2;

    cout << "Repeated ALerts: " << RepeatedAlert(zones, k) << endl;

    return 0;
}