#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> elements(arr1.begin(), arr1.end()); // Store arr1 elements
    vector<int> intersection;

    // Traverse arr2 and check for common elements
    for (int num : arr2)
    {
        if (elements.count(num))
        {
            intersection.push_back(num);
            elements.erase(num); // Prevent duplicates in the result
        }
    }

    return intersection;
}

int main()
{

    vector<int> v1 = {10, 20, 30, 40, 50};
    vector<int> v2 = {30, 40, 50, 60, 70};

    vector<int> result = findIntersection(v1, v2);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}