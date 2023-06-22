#include "../include/plansza.h"

plansza::plansza():  krol(7), wieza(0), grafik(25, 22)  //graf 25 wierzcholkow, wieza na polu W, krol na polu H i wieza na polu A
{
    for(int i=0;i<25;i++) //tablica aliasow do numerow
    {
        tab[i]=i+65;
    }

    //wypelnienie grafu mozliwymi ruchami

    for(int i=0;i<25;i++)
        for(int j=0;j<25;j++)
        {
            if(ruchMozliwy(i,j))
            {
                if(!grafik.czy_krawedz(i,j))
                    grafik.dodaj_krawedz(i, j, 1); //tworzymy graf nieskierowany
            }
        }
}

plansza::~plansza()
{
    //dtor
}


bool plansza::ruchMozliwy(int a, int b) // z a ---> b
{
    //czy nie kolidujemy z wieza
    if(wieza/5==b/5||(b-wieza)%5==0)  //jesli pole na ktore sie ruszamy jest w tym samym wierszu lub kolumnie co wieza
        return false;
    if(wieza/5==a/5||(a-wieza)%5==0)  //jesli pole na ktore sie ruszamy jest w tym samym wierszu lub kolumnie co wieza
        return false;
    //czy nie wychodzimy poza plasze
    if(b<0||b>24)
        return false;
    //czy to ruch skoczka
    int temp=b-a;

    //czy da sie jeden w prawo dwa do gory
    if(temp==-9&&a%5<=3&&a/5>=2)
        return true;
    //czy da sie jeden w prawo dwa do dolu
    if(temp==11&&a%5<=3&&a/5<=2)
        return true;
    //czy da sie dwa w prawo jeden do gory
    if(temp==-3&&a%5<=2&&a/5>=1)
        return true;
    //czy da sie dwa w prawo jeden do dolu
    if(temp==7&&a%5<=2&&a/5<=4)
        return true;
    //czy da sie jeden w lewo dwa do gory
    if(temp==-11&&a%5>=1&&a/5>=2)
        return true;
    //czy da sie jeden w lewo dwa do dolu
    if(temp==9&&a%5>=1&&a/5<=2)
        return true;
    //czy da sie dwa w lewo jeden do gory
    if(temp==-7&&a%5>=2&&a/5>=1)
        return true;
    //czy da sie dwa w lewo jeden do dolu
    if(temp==3&&a%5>=2&&a/5<=4)
        return true;
    return false;

}