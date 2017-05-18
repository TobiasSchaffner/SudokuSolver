#include <iostream>
#include <board-initializer.h>
#include <tobi-solver.h>
#include <flo-solver.h>
#include <util.h>
#include <exception/no-such-move-exception.h>

using namespace std;

int main() {

    auto binit = new BoardInitializer();

    auto gameboard = binit->create().back();

    printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

    auto solver = new TobiSolver(gameboard);


    while (solver->evaluateNext()) {}

    if (gameboard->isSolved()) {
        std::cout << "Solved";
    } else {
        std::cout << "Unsolvable";
    }

    return 0;
}


