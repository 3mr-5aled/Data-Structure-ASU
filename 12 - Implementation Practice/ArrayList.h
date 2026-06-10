#include <iostream>

using namespace std;

template <class T>
class ArrayList
{
    int elements, size;
    T *arr;

public:
    ArrayList();

    int Length();
    void Append(T val);
    void Expand();
    void insertAt(int pos, T val);
    void DeleteAt(int pos);
    T At(int pos);

    ~ArrayList();
}