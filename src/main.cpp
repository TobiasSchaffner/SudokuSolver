#include <iostream>
#include <board-initializer.h>
#include <tobi-solver.h>
#include <flo-solver.h>
#include <util.h>
#include <exception/no-such-move-exception.h>

using namespace std;

int main() {

    auto binit = new BoardInitializer();

    auto gameboard = binit->create("game-a.su");
    printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

    auto solver = new FloSolver(gameboard);


    while (solver->evaluateNext()) {}

    if (gameboard->isSolved()) {
        std::cout << "Solved";
    } else {
        std::cout << "Unsolvable";
    }
    std::cout << std::endl;


    printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());




//printBoard((unsigned int**) gameboard->get2DArray(), gameboard->getSize());
/*
while(gameboard->evaluateNext()) {
    printBoard(gameboard->get2DArray(), 9);
    printBoard(gameboard->getClasses(), 9);
}


printBoard(gameboard->get2DArray(), 9);
*/

    return 0;
}


