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
	void printGraph();
	~Graph_List();
};

#endif // GRAPH_LIST_H