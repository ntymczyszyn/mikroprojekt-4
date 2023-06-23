#include "include/DFS.h"
#include "include/AStar.h"

int main()
{
    // 25 wierzchołków, król H(7), skoczek W(22), wieża A(0)
    dfs::doDFS({25, 7, 22, 0});
    AStar::doAStar({25, 7, 22, 0});

    return 0;
}