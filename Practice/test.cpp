#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p = &a;
    int **pp = &p;
    // **pp is equivalent to *p, which is equivalent to a
    cout << **pp << endl;

    return 0;
}
