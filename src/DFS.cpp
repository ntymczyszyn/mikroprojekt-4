#include "../include/DFS.h"

void dfs::doDFS(const Board& board, int start, int cel)
{
    std::vector <int> visited;
    std::stack <int> toVisit;

    const int size = board.graph.numberOfNodes();
    std::vector<bool> _visited(size, false);

    toVisit.push(start);

    while(not toVisit.empty())
    {
        int current = toVisit.top();
        toVisit.pop();
        if(not _visited[current])
        {
            visited.push_back(current);
            _visited[current] = true;

            if(current == board.getKing())
                foundPath(board, visited);

            for(int i = board.graph.numberOfNodes() - 1; i >= 0; --i) //przeszukujemy nasz graf
            {
                if(board.graph.isEdge(current, i) and not _visited[i])
                {
                    toVisit.push(i);//Wrzucamy na stos jego sasiadów
                }
            }

        }
    }
    pathOrder(board, visited);
}

void dfs::foundPath(const Board &board, std::vector<int> &visited) {
    std::cout<<"DFS: ZNALEZIONO SCIEZKE"<<std::endl;
    for(int i=0; i < visited.size(); i++)
    {
        std::cout << board.alias[visited[i]];
        if(i < visited.size() - 1)
            std::cout<<", ";
    }

    std::cout<<std::endl<<std::endl;
}

void dfs::pathOrder(const Board &board, std::vector<int> &visited) {
    std::cout<<"DFS: Kolejnosc odwiedzania wierzcholkow"<<std::endl;
    for(int i=0; i < visited.size(); i++)
    {
        std::cout << board.alias[visited[i]];
        if(i < visited.size() - 1)
            std::cout<<", ";
    }
    std::cout<<std::endl;

}
