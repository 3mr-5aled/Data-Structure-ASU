#include <iostream>
using namespace std;

class PQ_Array
{
    int arr[100];
    int size;

public:
    PQ_Array() { size = 0; }

    void insert(int val)
    {
        int i;
        for (i = size - 1; i >= 0 && arr[i] < val; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = val;
        size++;
    }

    int remove()
    {
        if (size == 0)
            return -1;
        return arr[--size];
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};