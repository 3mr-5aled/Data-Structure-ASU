#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"

#include <vector>

using namespace std;

int main()
{
    // using Arraylist
    Linkedlist<int> L;
    L.Append(9);
    L.Append(8);
    L.Append(7);
    L.Append(6);
    L.Insert(100, 2);
    L.Remove(1);

    for (int i = 0; i < L.Length(); i++)
        cout << L.at(i) << endl;

    // using Vectors
    vector<int> v = {9, 8, 7, 6};
    v.insert(v.begin() + 2, 100); // or v.at(2) = 100; or v[2] = 100;
    v.erase(v.begin() + 1);       // or v.erase(v.begin() + 1, v.begin() + 2); to remove a range of elements

    vector<int>::iterator it;
    it = v.begin() + 2; // point to the third element

    for (const auto &item : v)
    {
        cout << item << endl;
    }
    v.push_back(5);         // add an element to the end of the vector
    v.pop_back();           // remove the last element of the vector
    int size = v.size();    // get the number of elements in the vector
    auto it = v.data();     // get the pointer to the underlying array
    int cap = v.capacity(); // get the capacity of the vector
    v.clear();              // clear the vector

    // --- Vector Remove Range Combinations ---
    // 1. Remove from index i to j (e.g., from index 2 to 5, exclusive)
    vector<int> vec1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vec1.erase(vec1.begin() + 2, vec1.begin() + 5);

    // 2. Remove first N elements (e.g., first 3 elements)
    vector<int> vec2 = {0, 1, 2, 3, 4, 5};
    vec2.erase(vec2.begin(), vec2.begin() + 3);

    // 3. Remove last N elements (e.g., last 3 elements)
    vector<int> vec3 = {0, 1, 2, 3, 4, 5};
    vec3.erase(vec3.end() - 3, vec3.end());

    // 4. Remove from index i to end (e.g., from index 3 to end)
    vector<int> vec4 = {0, 1, 2, 3, 4, 5};
    vec4.erase(vec4.begin() + 3, vec4.end());

    // 5. Remove all elements (equivalent to vec.clear())
    // vec4.erase(vec4.begin(), vec4.end());
    // ----------------------------------------

    return 0;
}