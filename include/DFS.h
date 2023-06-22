#ifndef DFS_H
#define DFS_H
#include "Graph.h"
#include "Board.h"

struct dfs
{
    static void doDFS(const Board &board, int start, int cel);
    static void foundPath(const Board &board,std::vector<int>& visited);
    static void pathOrder(const Board &board,std::vector<int>& visited);
};

#endif // DFS_H