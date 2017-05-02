#include <iostream>
#include <board-initializer.h>
#include "../include/gameboard.h"

using namespace std;

int main() {

    auto binit = new BoardInitializer();
    binit->initBoard("/home/confix/Projects/cpp/sudoku/game-a");

    auto gameboard = new Gameboard(9);

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
        } else {
            cout << "Invalid move, try again pls" << endl;
        }
    }
    return 0;
}

