#include "../include/Graph.h"
#include <algorithm>

Graph::Graph(int nodes): n(nodes),  array(nodes) {}

void Graph::addEdge(int a, int b)
{
    array[a].push_back(b);
    array[b].push_back(a);
}

bool Graph::isEdge(int a, int b) const
{
    return std::find(array[a].begin(), array[a].end(), b) != array[a].end();
}

int Graph::numberOfNodes() const
{
    return n;
}




