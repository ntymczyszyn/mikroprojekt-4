
#ifndef PLANSZA_H
#define PLANSZA_H
#include "graf_lista.h"
#include <iostream>
class plansza
{
private:
    //tablica przechowujaca litery odpowiadajace danym polom w tablicy
    int krol;
    int wieza;
    bool ruchMozliwy(int a, int b);
public:
    char tab[25];
    graf_lista grafik; //tworzymy graf oparty na listach stanowiacy dla nas graf wszystkich sytuacji na planszy
    plansza();
    int getKrol() const {return krol;};
    virtual ~plansza();
};

#endif // PLANSZA_H