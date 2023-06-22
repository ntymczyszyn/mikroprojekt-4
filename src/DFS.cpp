#include "../include/dfs.h"

dfs::dfs()
{
    //ctor
}

dfs::~dfs()
{
    //dtor
}

void dfs::doDFS(const plansza &plansz, int start, int cel)
{
    //dobra, teraz musimy utworzyc stos Frontier
    std::vector <int> odwiedzone;
    std::stack <int> doRozpatrzenia;

    bool _odwiedzone[plansz.grafik.ilosc_wierzcholkow()]; //opowiedniej wielkosci tablica

    for(int i=0;i<plansz.grafik.ilosc_wierzcholkow();i++)
        _odwiedzone[i] = false;

    doRozpatrzenia.push(start); //dodajemy pierwszy element do stosu
    while(!doRozpatrzenia.empty()) //dopoki stos nie bedzie pusty
    {
        start=doRozpatrzenia.top();
        doRozpatrzenia.pop();
        if(_odwiedzone[start] ==false)
        {
            odwiedzone.push_back(start);  //dodajemy jako element juz odwiedzony
            _odwiedzone[start]=true;

            if(start==plansz.getKrol())
            {
                std::cout<<"DFS: ZNALEZIONO SCIEZKE"<<std::endl;
                for(int i=0; i<odwiedzone.size();i++)
                {
                    std::cout<<plansz.tab[odwiedzone[i]];
                    if(i<odwiedzone.size()-1)
                        std::cout<<", ";
                }

                std::cout<<std::endl<<std::endl;
            }

            for(int i=plansz.grafik.ilosc_wierzcholkow()-1;i>=0;--i) //przeszukujemy nasz graf
            {
                if(plansz.grafik.czy_krawedz(start, i) && _odwiedzone[i] == false)
                {
                    doRozpatrzenia.push(i);//Wrzucamy na stos jego sasiadów
                }
            }

        }
    }

    std::cout<<"DFS: Kolejnosc odwiedzania wierzcholkow"<<std::endl;
    for(int i=0; i<odwiedzone.size();i++)
    {
        std::cout<<plansz.tab[odwiedzone[i]];
        if(i<odwiedzone.size()-1)
            std::cout<<", ";
    }
    std::cout<<std::endl;

}