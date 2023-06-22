cmake_minimum_required(VERSION 3.22)
project(mikroprojekt_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(mikroprojekt_4 main.cpp include/aGwiazdka.h include/DFS.h include/graf.h include/graf_lista.h include/lista.h include/plansza.h
        src/aGwiazdka.cpp src/DFS.cpp src/graf_lista.cpp src/plansza.cpp)


