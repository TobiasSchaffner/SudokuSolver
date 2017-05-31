#include <iostream>
#include <board-initializer.h>
#include "../include/solver.h"
#include <util.h>

using namespace std;

int main() {

    auto binit = new BoardInitializer();

    auto gameboard = binit->create("/home/platypus/CLionProjects/sudoku/conf/game-a.su");

    printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

    auto solver = new Solver(gameboard);


    while (solver->evaluateNext()) {
        printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

    }


    printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());


    if (gameboard->isSolved()) {
        std::cout << "Solved";
    } else {
        std::cout << "Unsolvable";
    }

    return 0;
}


