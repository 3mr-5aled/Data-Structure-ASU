#include "Graph_Matrix.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
Graph_Matrix::Graph_Matrix(int nodesCount, bool directed)
{
    if (nodesCount <= 0)
        throw invalid_argument("Invalid number of nodes");

    matrixSize = nodesCount;
    isDirected = directed;

    // Initialize matrix with NO_EDGE
    adjMatrix = vector<vector<int>>(matrixSize, vector<int>(matrixSize, NO_EDGE));

    // Distance to itself = 0
    for (int i = 0; i < matrixSize; i++)
        adjMatrix[i][i] = 0;
}

// Validate node index
void Graph_Matrix::validateNode(int node)
{
    if (node < 0 || node >= matrixSize)
        throw out_of_range("Invalid node index");
}

// Add edge
void Graph_Matrix::addEdge(int s, int d, int wt)
{
    validateNode(s);
    validateNode(d);

    adjMatrix[s][d] = wt;

    // Mirror if undirected
    if (!isDirected)
        adjMatrix[d][s] = wt;
}

// Remove edge
void Graph_Matrix::removeEdge(int s, int d)
{
    validateNode(s);
    validateNode(d);

    adjMatrix[s][d] = NO_EDGE;

    if (!isDirected)
        adjMatrix[d][s] = NO_EDGE;
}

// Print matrix
void Graph_Matrix::printGraph()
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            if (adjMatrix[i][j] == NO_EDGE)
                cout << "INF ";
            else
                cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}