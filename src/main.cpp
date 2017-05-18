#include <iostream>
#include <board-initializer.h>
#include <tobi-solver.h>
#include <flo-solver.h>
#include <util.h>
#include <exception/no-such-move-exception.h>

using namespace std;

int main() {

    auto binit = new BoardInitializer();

    auto gameboard = binit->create("/home/confix/Projects/cpp/sudoku/conf/game-a.su");

    printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

    auto solver = new FloSolver(gameboard);


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


