#include <iostream>
#include "include/Graph.h"
#include "include/Board.h"
#include "include/DFS.h"
#include "include/AStar.h"

int main()
{
    Board _plansza;
    std::vector <int> temp;
    std::vector<int>::iterator it;

    dfs::doDFS(_plansza, 22, 7);

//    temp = AStar::doAStar(_plansza, 22, 7);
//
//    std::cout<<std::endl<<"A*: Sciezka znaleziona przez algorytm"<<std::endl;
//    for(it=temp.end()-1;it>=temp.begin();--it)
//    {
//        std::cout<<_plansza.alias[*it]<<" ";;
//    }


    return 0;
}