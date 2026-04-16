#include <iostream>
#include "BST.h"
#include "BST.cpp"

using namespace std;

int main()
{
    BST<int> tree;
    tree.insert(100);
    tree.insert(50);
    tree.insert(60);
    // tree.insert(70);
    tree.insert(70);
    tree.insert(20);
    tree.insert(120);
    tree.insert(130);
    tree.insert(190);
    tree.insert(30);

    tree.remove(100);

    tree.traverse(PreOrder);

    return 0;
}
