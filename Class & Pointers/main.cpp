#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{

    // CLASSES
    // rectangle class
    rectangle r1(5, 7);
    r1.area();

    // Pointers
    // cout << *numPtr << endl; // exception !!
    int *numPtr;
    int num = 54;
    numPtr = &num;
    cout << *numPtr << endl;

    // Dynamic allocation of memory.
    // Enable complex "linked" data structures like linked lists and trees.

    // using (new) Operator
    int *p1;
    p1 = new int;        // allocate memory for an integer
    *p1 = 42;            // assign a value to the allocated memory
    int *p2 = p1;        // p2 points to the same memory location as p1
    p1 = new int;        // allocate new memory for an integer
    cout << *p1 << endl; // undefined behavior, p1 points to new memory
    cout << *p2 << endl; // outputs 42, p2 still points to the original memory

    delete p1; // deallocate memory allocated to p1
    delete p2; // deallocate memory allocated to p2 (original memory)
    // Note: Deleting p1 does not affect p2, but deleting p2 will free the memory that p1 was originally pointing to. After deleting p1, it is important to set it to nullptr to avoid dangling pointer issues.

    return 0;
}