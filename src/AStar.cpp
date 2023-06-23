#include "../include/AStar.h"
#include <vector>
#include <algorithm>
#include <iostream>

void AStar::doAStar(const Board& board) {
    int start = board.getKnight();
    const int size = board.graph.numberOfNodes();
    std::vector<int> gScore(size, std::numeric_limits<int>::max());
    std::vector<int> hScore(size);
    std::vector<int> fScore(size, std::numeric_limits<int>::max());
    std::vector<int> cameFrom(size, -1);
    std::vector<int> visited;
    std::vector<int> toVisit;

    hScore[start] = heuristic(start,board.getKing());
    gScore[start] = 0;
    fScore[start] = gScore[start] + hScore[start];
    toVisit.push_back(start);
    int current;

    while (not toVisit.empty()) {

        int temp = std::numeric_limits<int>::max();
        for(int i{0}; i < toVisit.size(); ++i)
        {
            temp = std::min(temp, fScore[toVisit[i]]);
            if(temp == fScore[toVisit[i]])
                current = toVisit[i];
        }
        if (current == board.getKing()) {
            visited.push_back(current);
            pathOrder(board, visited, fScore, hScore, gScore);
            foundPath(board, cameFrom, board.getKing());
            return;
        }

        toVisit.erase(std::find(toVisit.begin(), toVisit.end(), current));
        visited.push_back(current);

        for (int i{0}; i < size; ++i) {
            if (board.graph.isEdge(current, i) and
                std::find(visited.begin(), visited.end(), i) == visited.end()) {
                int tempGScore = gScore[current] + 1;
                if (tempGScore < gScore[i]) {
                    cameFrom[i] = current;
                    gScore[i] = tempGScore;
                    hScore[i] = heuristic(i, board.getKing());
                    fScore[i] = gScore[i] + hScore[i];
                    if (std::find(toVisit.begin(), toVisit.end(), i) == toVisit.end())
                        toVisit.push_back(i);
                }
            }
        }
    }
}

int AStar::heuristic(int a, int b) {
    return abs(a / 5 - b / 5) + abs(a % 5 - b % 5);
}

void AStar::foundPath(const Board &board, const std::vector<int>& cameFrom, int current) {
    std::vector<int> total_path;
    total_path.push_back(current);
    while (cameFrom[current] != -1) {
        current = cameFrom[current];
        total_path.push_back(current);
    }
    std::cout << std::endl << "A* - path found" << std::endl;
    for(auto it{total_path.end()-1}; it >= total_path.begin(); --it)
        std::cout << board.alias[*it] << " ";

}

void AStar::pathOrder(const Board &board, std::vector<int> &visited, std::vector<int> &fScore, std::vector<int> &hScore,
                      std::vector<int> &gScore) {
    std::cout << "A* - visited nodes" << std::endl;
    for (int i = 0; i < visited.size(); ++i) {
        std::cout << board.alias[visited[i]] << " " << i + 1
                  << ", f = " << fScore[visited[i]]
                  << ", h = " << hScore[visited[i]]
                  << ", g = " << gScore[visited[i]] << std::endl;
    }
}
