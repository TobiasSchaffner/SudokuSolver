#include <iostream>
#include <board-initializer.h>
#include "../include/gameboard.h"
#include "util.h"

using namespace std;

int main() {

 auto binit = new BoardInitializer();

    auto gameboard = binit->create("/home/confix/Projects/cpp/sudoku/game-a");

    /*
    while (!gameboard->isSolved()) {
        int col, row, val;
        cout << "Please enter your next move:" << endl;
        cout << "Column:" << endl;
        cin >> col;
        cout << "Row:" << endl;
        cin >> row;
        cout << "Value:" << endl;
        cin >> val;
        if (gameboard->nextMove(col, row, val)) {
            gameboard->print();
            cout << endl;
            gameboard->printClasses();
        } else {
            cout << "Invalid move, try again pls" << endl;
        }
    }*/


    while(gameboard->evaluateNext()) {
        printBoard(gameboard->get2DArray(), 9);
        printBoard(gameboard->getClasses(), 9);
    }

    printBoard(gameboard->get2DArray(), 9);


    return 0;
}

