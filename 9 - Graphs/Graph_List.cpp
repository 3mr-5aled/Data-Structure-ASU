#include "Graph_List.h"

Graph_List::Graph_List()
{
    size = 0;
}

void Graph_List::addEdge(char s, char d, int wt)
{
    adj[s].push_back({d, wt});
    size++;
}

void Graph_List::removeEdge(char s, char d)
{
    vector<pair<char, int>> edges = adj[s];
    for (auto it = edges.begin(); it != edges.end(); ++it)
    {
        if (it->first == d)
        {
            edges.erase(it);
            break;
        }
    }
    size--;
}

void Graph_List::printGraph()
{
    for (const auto &node : adj)
    {
        cout << node.first << ": ";
        for (const auto &edge : node.second)
        {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }
}

Graph_List::~Graph_List()
{
    adj.clear();
}