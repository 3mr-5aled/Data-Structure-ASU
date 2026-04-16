#include <iostream>
#include "ArrayList.h"
#include "ArrayList.cpp"

#include <vector>

using namespace std;

int main()
{
    // using Arraylist
    ArrayList<int> L;
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
    v.insert(v.begin() + 2, 100);
    v.erase(v.begin() + 1);

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

    return 0;
}