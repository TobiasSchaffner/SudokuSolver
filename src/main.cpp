#include <iostream>
#include <board-initializer.h>
#include "../include/gameboard.h"
#include "util.h"

using namespace std;

int main() {

 auto binit = new BoardInitializer();

    auto gameboard = binit->create("game-a.su");

    while(gameboard->evaluateNext()) {
        printBoard(gameboard->get2DArray(), 9);
        printBoard(gameboard->getClasses(), 9);
    }

    printBoard(gameboard->get2DArray(), 9);


    return 0;
}

