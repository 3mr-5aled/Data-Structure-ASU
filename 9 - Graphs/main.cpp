#include <iostream>
#include "Graph_Matrix.h"
#include "Graph_Matrix.cpp"
#include "Graph_List.h"
#include "Graph_List.cpp"
using namespace std;

int main()
{
    Graph_Matrix g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 3);
    g.removeEdge(1, 2);

    cout << "Graph adjacency matrix:" << endl;
    g.printGraph();

    Graph_List gl;
    gl.addEdge('A', 'B', 10);
    gl.addEdge('A', 'C', 5);
    gl.addEdge('B', 'C', 2);
    gl.addEdge('B', 'D', 1);
    gl.addEdge('C', 'B', 3);
    gl.removeEdge('B', 'C');

    cout << "\nGraph adjacency list:" << endl;
    gl.printGraph();

    return 0;
}