#ifndef BOARD_H
#define BOARD_H
#include "Graph.h"
#include <iostream>

class Board
{
public:
    Board();
    int getKing() const;
    char alias[25];
    Graph graph; //tworzymy graf oparty na listach stanowiacy dla nas graf wszystkich sytuacji na planszy
private:
    int king;
    int tower;
    bool validMove(int a, int b);
};

#endif // BOARD_H