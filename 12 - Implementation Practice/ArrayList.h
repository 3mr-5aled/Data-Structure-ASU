#include <iostream>

using namespace std;

template <class T>
class Linkedlist
{
    int elements, size;
    T *arr;

public:
    Linkedlist();

    int Length();
    void Append(T val);
    void Expand();
    void insertAt(int pos, T val);
    void DeleteAt(int pos);
    T At(int pos);

    ~Linkedlist();
}