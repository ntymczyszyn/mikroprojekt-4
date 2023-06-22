#include <iostream>
#include "include/graf_lista.h"
#include "include/plansza.h"
#include "include/DFS.h"
#include "include/aGwiazdka.h"
using namespace std;

int main()
{
    remove("wyniki.txt");
    plansza _plansza;
    std::vector <int> temp;
    std::vector<int>::iterator it;

    //DFS
    dfs::doDFS(_plansza, 22, 7);


    //A gwiazdka
    temp=aGwiazdka::doAGwiazdka(_plansza, 22, 7);

    _plansza.grafik.dijkstra("wyniki.txt");

    std::cout<<std::endl<<"A*: Sciezka znaleziona przez algorytm"<<std::endl;
    for(it=temp.end()-1;it>=temp.begin();--it)
    {
        std::cout<<_plansza.tab[*it]<<" ";;
    }


    return 0;
}