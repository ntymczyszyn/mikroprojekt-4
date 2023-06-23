#ifndef ASTAR_H
#define ASTAR_H
#include "Board.h"
#include <cmath>
#include <limits>

struct AStar
{
    static int heuristic(int a, int b);
    static void doAStar (const Board &board);
    static void pathOrder(const Board &board,std::vector<int>& visited, std::vector<int>& fScore, std::vector<int>& hScore, std::vector<int>& gScore);
    static void foundPath(const Board &board, const std::vector<int>& cameFrom, int current);
};

#endif // ASTAR_H