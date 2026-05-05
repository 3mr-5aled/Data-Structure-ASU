#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <iostream>
using namespace std;

class Graph_Matrix
{
private:
	int matrixSize;
	int **adjMatrix;

public:
	Graph_Matrix(int nodesCount);

	void addEdge(int s, int d, int wt);
	void removeEdge(int s, int d);
	void printGraph();

	~Graph_Matrix(); // destructor to free memory
};

#endif