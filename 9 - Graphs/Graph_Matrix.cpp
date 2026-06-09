#include "Graph_Matrix.h"
#include <queue>
#include <vector>
#include <functional>

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

// Breadth-First Search (BFS) for adjacency matrix
// Visits nodes level by level using a queue
void Graph_Matrix::BFS(int start)
{
    if (start < 0 || start >= matrixSize)
    {
        cout << "Invalid start node for BFS" << endl;
        return;
    }

    vector<bool> visited(matrixSize, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting at " << start << ": ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Look through row `node` to find edges
        for (int j = 0; j < matrixSize; ++j)
        {
            // non-zero weight indicates an edge (weighted graphs assumed)
            if (adjMatrix[node][j] != 0 && !visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    cout << endl;
}

// DFS (recursive) for adjacency matrix
// Uses recursion to go as deep as possible before backtracking
void Graph_Matrix::DFS(int start)
{
    if (start < 0 || start >= matrixSize)
    {
        cout << "Invalid start node for DFS" << endl;
        return;
    }

    vector<bool> visited(matrixSize, false);
    cout << "DFS traversal starting at " << start << ": ";

    // inner lambda for recursion
    function<void(int)> dfsRec = [&](int node)
    {
        visited[node] = true;
        cout << node << " ";
        for (int j = 0; j < matrixSize; ++j)
        {
            if (adjMatrix[node][j] != 0 && !visited[j])
                dfsRec(j);
        }
    };

    dfsRec(start);
    cout << endl;
}