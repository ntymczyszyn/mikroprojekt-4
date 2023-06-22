#ifndef AGWIAZDKA_H
#define AGWIAZDKA_H
#include "plansza.h"
#include <cmath>
#include <limits>
class aGwiazdka
{
private:

public:
    static int heur(int a, int b);
    static bool wZbiorze(std::vector <int> zbior, int a);
    static void usunZeZbioru(std::vector <int> &zbior, int a);

    aGwiazdka();
    virtual ~aGwiazdka();
    static std::vector <int> doAGwiazdka (const plansza &plansz, int start, int cel);
    static std::vector <int> odtworz_sciezke(int *cameFrom, int current);

};

#endif // AGWIAZDKA_H