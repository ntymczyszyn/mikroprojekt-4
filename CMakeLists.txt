cmake_minimum_required(VERSION 3.22)
project(mikroprojekt_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(mikroprojekt_4 main.cpp include/AStar.h include/DFS.h include/Graph.h include/Board.h
        src/AStar.cpp src/DFS.cpp src/Graph.cpp src/Board.cpp)


