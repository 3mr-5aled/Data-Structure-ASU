#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Graph_List
{
	int size;
	unordered_map<char, vector<pair<char, int>>> adj;

public:
	Graph_List();
	void addEdge(char s, char d, int wt);
	void removeEdge(char s, char d);
	// Breadth-First Search starting from a given node
	void BFS(char start);

	// Depth-First Search starting from a given node (wrapper)
	void DFS(char start);
	void printGraph();
	~Graph_List();

private:
	// Helper for recursive DFS
	void dfsUtil(char node, unordered_map<char, bool> &visited);
};

#endif // GRAPH_LIST_H