#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> umap; // Create an empty unordered_map.

    cout << "empty: " << umap.empty() << endl; // Check if the container has no elements.

    umap["apple"] = 5;                   // operator[] inserts key if missing, then assigns value.
    umap["banana"] = 10;                 // operator[] access/insert for key "banana".
    umap["orange"] = 15;                 // operator[] access/insert for key "orange".
    umap.insert(make_pair("grape", 20)); // Insert key-value pair using insert().

    umap.at("mango") = 25;                            // at() inserts if key is missing, then assigns value.
    cout << "at mango: " << umap.at("mango") << endl; // Access value for key "mango".

    cout << "size: " << umap.size() << endl; // Return number of key-value pairs.

    auto itBegin = umap.begin(); // Iterator to the first element in bucket order.
    auto itEnd = umap.end();     // Iterator representing position after last element.
    if (itBegin != itEnd)
    {
        cout << "begin: " << itBegin->first << " -> " << itBegin->second << endl; // Dereference begin iterator.
    }

    cout << "operator[] apple: " << umap["apple"] << endl; // Access value by key (inserts default if missing).
    cout << "at banana: " << umap.at("banana") << endl;    // Access existing key with bounds checking.

    auto itFind = umap.find("orange"); // Find returns iterator to key, or end if not found.
    if (itFind != umap.end())
    {
        cout << "find orange: " << itFind->second << endl; // Key found, print associated value.
    }
    else
    {
        cout << "find orange: not found" << endl; // Key was not found in map.
    }

    umap.erase("banana");                                // Erase element by key.
    cout << "size after erase: " << umap.size() << endl; // Size updates after removing key.

    unordered_map<string, int> other; // Another map for demonstrating swap.
    other["grape"] = 20;              // Fill the other map with sample data.
    other["mango"] = 30;

    umap.swap(other);                                         // Swap all contents between umap and other.
    cout << "after swap, umap size: " << umap.size() << endl; // umap now has elements from other.

    umap.clear();                                          // Remove all elements from umap.
    cout << "empty after clear: " << umap.empty() << endl; // Verify container is empty again.

    return 0;
}