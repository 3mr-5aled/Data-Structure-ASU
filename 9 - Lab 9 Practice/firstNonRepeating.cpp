#include <iostream>
#include <unordered_map>

using namespace std;

int firstNonRepeatingElement(int arr[], int n)
{
    unordered_map<int, int> freq;
    // First pass: Count occurrences of each element
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    // Second pass: Find the first element with frequency 1
    for (int i = 0; i < n; i++)
    {
        if (freq[arr[i]] == 1)
        {
            return arr[i]; // First non-repeating element found
        }
    }
    return -1; // If no non-repeating element exists
}

int main()
{

    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = firstNonRepeatingElement(arr, n);
    if (result != -1)
    {
        cout << "First non-repeating element: " << result << endl;
    }
    else
    {
        cout << "No non-repeating element found." << endl;
    }

    return 0;
}