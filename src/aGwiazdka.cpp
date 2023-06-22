#include "../include/aGwiazdka.h"

aGwiazdka::aGwiazdka()
{

}

aGwiazdka::~aGwiazdka()
{
    //dtor
}

void aGwiazdka::usunZeZbioru(std::vector <int> &zbior, int a)
{
    std::vector<int>::iterator it;

    for(it=zbior.begin();it!=zbior.end();++it)
    {
        if(*it==a)
        {
            zbior.erase(it);
            break;
        }
    }
}


bool aGwiazdka::wZbiorze(std::vector <int> zbior, int a)
{
    for(int i=0;i<zbior.size();i++)
    {
        if(zbior[i]==a)
        {
            return true;
        }

    }
    return false;
}

int aGwiazdka::heur(int a, int b)
{
    int h;

    h=abs(a/5-b/5)+abs(a%5-b%5);
    return h;

}


std::vector <int> aGwiazdka::doAGwiazdka(const plansza &plansz, int start, int cel)
{
    int g_score[plansz.grafik.ilosc_wierzcholkow()];
    int h_score[plansz.grafik.ilosc_wierzcholkow()];
    int f_score[plansz.grafik.ilosc_wierzcholkow()];
    int came_from[plansz.grafik.ilosc_wierzcholkow()];

    //dobra, teraz musimy utworzyc stos Frontier
    std::vector <int> odwiedzone;
    std::vector <int> doRozpatrzenia;
    int temp=std::numeric_limits<int>::max();
    int x;
    int niepewny_g_score;
    bool niepewny_lepszy;
    for(int i=0;i<plansz.grafik.ilosc_wierzcholkow();i++)  //wypelniamy tablice h
    {
        h_score[i]=heur(cel, i);
        came_from[i]=-1;
    }


    doRozpatrzenia.push_back(start); //dodajemy pierwszy element do stosu
    g_score[start]=0; //kosz dojscia do wierzcholka startowego to 0 :)
    f_score[start]=g_score[start]+h_score[start];

    while(!doRozpatrzenia.empty()) //dopoki stos nie bedzie pusty
    {
        temp=std::numeric_limits<int>::max();
        for(int i=0;i<doRozpatrzenia.size();i++)  //szukamy minimalnej oceny f wsrod naszych nod
        {
            temp=std::min(temp, f_score[doRozpatrzenia[i]]);
            if(temp==f_score[doRozpatrzenia[i]]) //jesli zamiana
            {
                x=doRozpatrzenia[i];
            }
        }


        if(x==cel)  //koniec funkcji - wypiszmy co sie da
        {
            odwiedzone.push_back(x);
            f_score[x]=g_score[x]+h_score[x];
            std::cout<<"A*: Odwiedzone wierzcholki"<<std::endl;
            for(int i=0;i<odwiedzone.size();i++)
            {
                std::cout<<plansz.tab[odwiedzone[i]]<<" "<< i+1<< ", f="<<f_score[odwiedzone[i]]<<", h="<<h_score[odwiedzone[i]]<< ", g="<<g_score[odwiedzone[i]]<<std::endl;

            }


            return odtworz_sciezke(came_from, cel);
        }

        std::vector<int>::iterator it;

        usunZeZbioru(doRozpatrzenia, x);
        odwiedzone.push_back(x);

        for(int i=plansz.grafik.ilosc_wierzcholkow()-1;i>=0;--i) //przeszukujemy nasz graf w poszukiwaniu sasiadow
        {
            if(plansz.grafik.czy_krawedz(x, i)&&!wZbiorze(odwiedzone, i))  //jesli to sasiad i jeszcze nie jest w zamknietym
            {
                niepewny_g_score=g_score[x]+1;
                niepewny_lepszy=false;

                if(!wZbiorze(doRozpatrzenia, i))
                {
                    doRozpatrzenia.push_back(i);
                    niepewny_lepszy=true;
                }
                else if (niepewny_g_score < g_score[i])
                {
                    niepewny_lepszy=true;
                }
                if(niepewny_lepszy)
                {
                    came_from[i]=x;
                    g_score[i]=niepewny_g_score;
                    f_score[i]=g_score[i]+h_score[i];
                }
            }
        }
    }
}



std::vector <int> aGwiazdka::odtworz_sciezke(int *cameFrom, int current)
{
    std::vector <int> total_path;
    total_path.push_back(current);

    while(cameFrom[current]!=-1)
    {
        current = cameFrom[current];
        total_path.push_back(current);
    }

    return total_path;
}