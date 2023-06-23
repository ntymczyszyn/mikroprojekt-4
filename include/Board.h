#ifndef BOARD_H
#define BOARD_H
#include "Graph.h"

class Board
{
public:
    Board(int _size, int _king, int _knight, int _tower);
    int getKing() const;
    int getKnight() const;
    char alias[25];
    Graph graph;
private:
    int king;
    int tower;
    int knight;
    bool validMove(int a, int b);
};

#endif // BOARD_H