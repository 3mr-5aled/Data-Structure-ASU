// #include <iostream>
// #include <set>
// #include <map>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// int main2()
// {
//     // SETS - a collection of unique values
//     cout << "==============================" << endl;
//     cout << "SETS" << endl;
//     cout << "==============================" << endl;
//     set<int> s;
//     set<int>::iterator it;

//     s.insert(1);
//     s.insert(2);
//     s.insert(3);

//     for (it = s.begin(); it != s.end(); it++)
//     {
//         cout << *it << endl;
//     }

//     cout << "==============================" << endl;
//     cout << "SETS FUNCTIONS" << endl;
//     cout << "==============================" << endl;
//     // set functions
//     s.erase(2);                // removes the element with value 2 from the set
//     s.find(2);                 // returns an iterator to the element with value 2, or s.end() if it doesn't exist
//     s.begin();                 // points to the first element
//     s.end();                   // points to the element after the last element
//     cout << s.empty() << endl; // returns true if the set is empty
//     cout << s.size() << endl;  // returns the number of elements in the set

//     // unordered sets - same as sets but with faster access time
//     unordered_set<int> us;
//     us.insert(3);
//     us.insert(1);
//     us.insert(2);
//     for (auto it = us.begin(); it != us.end(); it++)
//     {
//         cout << *it << endl;
//     }

//     cout << "==============================" << endl;
//     cout << "PAIRS" << endl;
//     cout << "==============================" << endl;

//     // Pairs - a pair of values of any type
//     pair<int, string> p1(1, "one");
//     pair<int, string> p2(2, "two");
//     pair<int, string> p3 = make_pair(3, "three");
//     pair<int, string> p4;
//     p4.first = 4;
//     p4.second = "four";

//     cout << p1.first << " " << p1.second << endl;
//     cout << p2.first << " " << p2.second << endl;

//     // pairs functions
//     p1.swap(p2); // swaps the values of p1 and p2

//     cout << "==============================" << endl;
//     cout << "LIST OF PAIRS" << endl;
//     cout << "==============================" << endl;

//     // list of pairs using vector
//     vector<pair<int, string>> v;
//     v.push_back(p1);
//     v.push_back(p2);
//     v.push_back(p3);
//     v.push_back(p4);

//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i].first << " " << v[i].second << endl;
//     }

//     cout << "==============================" << endl;
//     cout << "MAPS" << endl;
//     cout << "==============================" << endl;

//     // Maps - same as vector of pairs but with faster access time
//     map<int, string> m;
//     m[1] = "one";
//     m[2] = "two";
//     m[3] = "three";

//     // finding a key in the map
//     if (m.find(1) == m.end()) // m.find(1) returns an iterator to the element with key 1, or m.end() if it doesn't exist
//     {
//         cout << "Key not found" << endl;
//     }
//     else
//     {
//         cout << m[1] << endl;
//     }

//     for (auto it = m.begin(); it != m.end(); it++)
//     {
//         cout << it->first << " " << it->second << endl;
//     }

//     cout << "==============================" << endl;
//     cout << "MAPS FUNCTIONS" << endl;
//     cout << "==============================" << endl;

//     // Map functions
//     m.erase(2);                     // removes the key-value pair with key 2 from the map
//     m.insert(make_pair(4, "four")); // inserts a new key-value pair (4, "four") into the map
//     m.at(3);                        // returns the value associated with the key 3
//     m.begin();                      // points to the first element
//     m.find(2);                      // returns an iterator to the element with key 2, or m.end() if it doesn't exist
//     m.end();                        // points to the element after the last element
//     cout << m.empty() << endl;      // returns true if the map is empty

//     return 0;
// }

// /*
// | Section         | Functions              | Code Explanation                                             | Time Complexity             |
// |-----------------|------------------------|--------------------------------------------------------------|-----------------------------|
// | Set             | insert(value)          | Adds a unique value to the set. Duplicate values are ignored.| O(log n)                    |
// | Set             | erase(value)           | Removes the value if it exists.                              | O(log n)                    |
// | Set             | find(value)            | Returns iterator to value, or end() if not found.            | O(log n)                    |
// | Set             | begin()                | Returns iterator to first element (smallest in ordered set). | O(1)                        |
// | Set             | end()                  | Returns iterator to one past the last element.               | O(1)                        |
// | Set             | empty()                | Checks whether the set has no elements.                      | O(1)                        |
// | Set             | size()                 | Returns number of elements in the set.                       | O(1)                        |
// | Unordered Set   | insert(value)          | Adds a unique value using hash-based storage.                | Average O(1)                |
// | Unordered Set   | begin(), end()         | Iterates through all values in hash-table order (not sorted).| O(1) for iterator retrieval |
// | Pair            | make_pair(a, b)        | Creates a pair object with two values.                       | O(1)                        |
// | Pair            | swap(otherPair)        | Swaps contents between two pairs.                            | O(1)                        |
// | Vector of Pairs | push_back(pair)        | Appends a pair to the vector.                                | Amortized O(1)              |
// | Vector of Pairs | v[i]                   | Accesses pair at index i.                                    | O(1)                        |
// | Map             | operator[]             | Inserts/updates value for a key.                             | O(log n)                    |
// | Map             | find(key)              | Returns iterator to key, or end() if key not found.          | O(log n)                    |
// | Map             | erase(key)             | Removes key-value pair for that key.                         | O(log n)                    |
// | Map             | insert(make_pair(k, v))| Inserts key-value pair if key does not exist.                | O(log n)                    |
// | Map             | at(key)                | Returns value for key; throws if key not found.              | O(log n)                    |
// | Map             | begin(), end()         | Iterates keys in sorted order.                               | O(1) for iterator retrieval |
// | Map             | empty()                | Checks whether map has no elements.                          | O(1)                        |
// */
