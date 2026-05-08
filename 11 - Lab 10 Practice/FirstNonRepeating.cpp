#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int nonRepeating(const vector<int> &arr)
{
    int result = -1; // Default to -1 if no non-repeating element is found
    unordered_map<int, int> countMap;
    for (int num : arr)
    {
        countMap[num]++;
    }
    for (int num : arr)
    {
        if (countMap[num] == 1)
        {
            result = num;
            break; // Found the first non-repeating element, exit loop
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {4, 5, 1, 2, 5, 4, 1, 3};
    vector<int> arr2 = {10, 10, 20, 20, 30, 30};
    int result = nonRepeating(arr);
    cout << "First non-repeating element: " << result << endl;
    int result2 = nonRepeating(arr2);
    cout << "First non-repeating element: " << result2 << endl;

    return 0;
}