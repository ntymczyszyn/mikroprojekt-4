#ifndef GRAF_LISTA_H_INCLUDED
#define GRAF_LISTA_H_INCLUDED

#include <stack>
#include <vector>

class Graph
{
public:
    Graph(int nodes);

    void addEdge(int a, int b);
    bool isEdge(int a, int b) const ;
    int numberOfNeighbours(int a) const;
    int numberOfNodes() const;
private:
    std::vector<std::vector<int>> array; // tablica list sasiedztwa
    int n;
};

#endif