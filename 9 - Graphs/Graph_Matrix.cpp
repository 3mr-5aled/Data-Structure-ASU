#include "Graph_Matrix.h"

// Constructor
Graph_Matrix::Graph_Matrix(int nodesCount)
{
    matrixSize = nodesCount;

    // Allocate rows
    adjMatrix = new int *[matrixSize];

    // Allocate columns and initialize with 0 (no edge)
    for (int i = 0; i < matrixSize; i++)
    {
        adjMatrix[i] = new int[matrixSize];

        for (int j = 0; j < matrixSize; j++)
            adjMatrix[i][j] = 0;
    }
}

// Add edge (directed)
void Graph_Matrix::addEdge(int s, int d, int wt)
{
    if (s >= matrixSize || d >= matrixSize || s < 0 || d < 0)
    {
        cout << "Invalid node index!" << endl;
        return;
    }

    adjMatrix[s][d] = wt;
}

// Remove edge
void Graph_Matrix::removeEdge(int s, int d)
{
    if (s >= matrixSize || d >= matrixSize || s < 0 || d < 0)
    {
        cout << "Invalid node index!" << endl;
        return;
    }

    adjMatrix[s][d] = 0;
}

// Print graph
void Graph_Matrix::printGraph()
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Destructor (fixes memory leak)
Graph_Matrix::~Graph_Matrix()
{
    for (int i = 0; i < matrixSize; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}