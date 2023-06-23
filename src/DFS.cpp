#include "../include/DFS.h"
#include <iostream>
#include <stack>

void dfs::doDFS(const Board& board)
{
    int start = board.getKnight();
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

            for(int i = board.graph.numberOfNodes() - 1; i >= 0; --i)
            //for(int i{0}; i < board.graph.numberOfNodes(); ++i)
            {
                if(board.graph.isEdge(current, i) and not _visited[i])
                    toVisit.push(i);
            }
        }
    }
    pathOrder(board, visited);
}

void dfs::foundPath(const Board &board, std::vector<int> &visited) {
    std::cout << "DFS - path found" << std::endl;
    for(const auto& node : visited)
        std::cout << board.alias[node] << " ";

    std::cout << std::endl << std::endl;
}

void dfs::pathOrder(const Board &board, std::vector<int> &visited) {
    std::cout << "DFS - visited nodes" << std::endl;
    for(const auto& node : visited)
        std::cout << board.alias[node] << " ";

    std::cout << std::endl <<std::endl;
}
