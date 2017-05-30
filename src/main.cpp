#include <iostream>
#include <board-initializer.h>
#include <solver.h>
#include <util.h>

using namespace std;

int main() {
    auto boardInitializer = new BoardInitializer();
    auto gameboard = boardInitializer->create("/home/platypus/CLionProjects/sudoku/conf/game-a.su");

    print2DArray(gameboard->get2DArray(), gameboard->getSize());

    auto solver = new Solver(gameboard);
    solver->solve();

    print2DArray(gameboard->get2DArray(), gameboard->getSize());

    return 0;
}


