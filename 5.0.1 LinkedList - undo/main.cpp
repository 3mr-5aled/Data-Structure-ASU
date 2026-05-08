#include <iostream>
#include "LinkedList.h"

using namespace std;
int main()
{
    LinkedList<int> l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);

    cout << "Original:-" << endl;
    l.display();

    cout << "=================================" << endl;
    l.moveNode(4, 1);
    l.display();
    l.undo();
    l.undo();
    l.undo();
    cout << "modifing one :-" << endl;
    l.display();
}
