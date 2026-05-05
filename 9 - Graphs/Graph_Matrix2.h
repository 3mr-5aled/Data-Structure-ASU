#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <vector>

class Graph_Matrix
{
private:
    int matrixSize;
    std::vector<std::vector<int>> adjMatrix;
    bool isDirected;
    const int NO_EDGE = 1e9; // large value to represent no edge

    void validateNode(int node);

public:
    Graph_Matrix(int nodesCount, bool directed = true);

    void addEdge(int s, int d, int wt);
    void removeEdge(int s, int d);
    void printGraph();
};

#endif