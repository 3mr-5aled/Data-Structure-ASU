#include "Graph_List.h"
#include <queue>
#include <unordered_map>

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

// Breadth-First Search (BFS)
// Uses a queue to visit nodes in layers: first all neighbors of the start,
// then neighbors of those neighbors, etc.
void Graph_List::BFS(char start)
{
    // Track visited nodes to avoid revisiting
    unordered_map<char, bool> visited;
    queue<char> q;

    // Start from the `start` node
    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting at " << start << ": ";

    while (!q.empty())
    {
        char node = q.front();
        q.pop();

        // Process the node (here we print it)
        cout << node << " ";

        // Visit all adjacent vertices
        for (const auto &edge : adj[node])
        {
            char neighbor = edge.first;
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// Depth-First Search (DFS) wrapper
// Starts a recursive exploration from `start` and prints nodes as they are first discovered.
void Graph_List::DFS(char start)
{
    unordered_map<char, bool> visited;
    cout << "DFS traversal starting at " << start << ": ";
    dfsUtil(start, visited);
    cout << endl;
}

// dfsUtil: recursive helper that visits a node and then explores its neighbors
void Graph_List::dfsUtil(char node, unordered_map<char, bool> &visited)
{
    // Mark current node visited and process it
    visited[node] = true;
    cout << node << " ";

    // Recurse for all unvisited neighbors
    for (const auto &edge : adj[node])
    {
        char neighbor = edge.first;
        if (!visited[neighbor])
            dfsUtil(neighbor, visited);
    }
}