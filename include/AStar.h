#ifndef ASTAR_H
#define ASTAR_H
#include "Board.h"
#include <cmath>
#include <limits>

struct AStar
{
    static int heuristic(int a, int b);
    static bool isInSet(std::vector <int> &zbior, int a);
    static  void removeFromSet(std::vector <int> &zbior, int a);

    static std::vector <int> doAStar (const Board &plansz, int start, int cel);
    static std::vector <int> odtworz_sciezke(int *cameFrom, int current);
};

#endif // ASTAR_H