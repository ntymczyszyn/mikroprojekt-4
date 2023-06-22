#include "../include/Graph.h"

Graph::Graph(int nodes):
        n(nodes),  array(nodes) {}

void Graph::addEdge(int a, int b)
{
    array[a].push_back(b);
    array[b].push_back(a);
}
// można to poprawić na std::find
bool Graph::isEdge(int a, int b) const
{
    for(int i{0}; i < numberOfNeighbours(a); ++i)
    {
        if(array[a][i] == b)
            return true;
    }
    return false;
}

int Graph::numberOfNeighbours(int a) const
{
    return array[a].size();
}

int Graph::numberOfNodes() const
{
    return n;
}




