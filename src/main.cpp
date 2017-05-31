#include <iostream>
#include <board-initializer.h>
#include <solver.h>
#include <util.h>
#include <generator.h>

using namespace std;

int main() {
    //auto boardInitializer = new BoardInitializer();
    //auto gameboard = boardInitializer->create("/home/platypus/CLionProjects/sudoku/conf/game-a.su");

    auto generator = new Generator();
    auto gameboard = generator->generate(9, 50);

    print2DArray(gameboard->get2DArray(), gameboard->getSize());

    auto solver = new Solver(gameboard);
    solver->solve();

    print2DArray(gameboard->get2DArray(), gameboard->getSize());

    return 0;
}


