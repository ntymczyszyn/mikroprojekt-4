#include "../include/Board.h"

// 25 wierzchołków, wieża A(0), król H(7), skoczek W(22)
Board::Board(): king(7), tower(0), graph(25)
{
    for(int i{0}; i < 25; ++i)
    {
        alias[i] = i + 'A';
    }
    // tworzymy graf nieskierowany wypełnionymi możliwymi ruchami skoczka
    for(int i{0}; i < 25 ;++i)
        for(int j{0}; j < 25; ++j)
        {
            if(validMove(i, j))
            {
                if(not graph.isEdge(i, j))
                    graph.addEdge(i, j);
            }
        }
}

bool Board::validMove(int a, int b) // z a ---> b
{
    int Ay = a % 5;  // Kolumna pola a
    int Ax = a / 5;  // Wiersz pola a
    int By = b % 5;  // Kolumna pola a
    int Bx = b / 5;  // Wiersz pola a

    if((tower / 5 == Bx or tower % 5 == By) or (tower / 5 == Ax or tower % 5 == Ay))  //jesli pole na ktore sie ruszamy jest w tym samym wierszu lub kolumnie co tower
        return false;

    int dy = abs(By- Ay);  // Różnica kolumn między polami a i b
    int dx = abs(Bx - Ax);  // Różnica wierszy między polami a i b

    if ((dx == 1 and dy == 2) or (dx == 2 and dy == 1)) {
        return true;
    }
    return false;
}

int Board::getKing() const {
    return king;
}
