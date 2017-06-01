#include <iostream>
#include <board-initializer.h>
#include "../include/solver.h"
#include <util.h>

using namespace std;

int main() {

    auto binit = new BoardInitializer();

//    auto gameboard = binit->create(
//            "C:\\Users\\M4NU\\Desktop\\FH\\Algorithmen_und_Datenstrukturen_II\\Sudoku\\blatt-2-sudoku07-1\\conf\\game-a.su");


    std::map<int, std::string> paths = binit->create();
    for (auto const itr :paths)
        cout << itr.first << ": " << itr.second.substr(itr.second.find_last_of("/\\"),itr.second.size()) << endl;


    int index;
    while (index != -1) {
        cout << "Choose the sudoku you want to solve: " << endl;
        cin >> index;
        if (cin.fail() || index >= paths.size()) {
            cout << "Please try again!: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }else{
            auto gameboard = binit->create(paths[index]);
            printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

            auto solver = new Solver(gameboard);

            while (solver->evaluateNext())
                printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

            printBoard((unsigned int **) gameboard->get2DArray(), gameboard->getSize());

            if (gameboard->isSolved()) {
                std::cout << "Solved" << endl;
            } else {
                std::cout << "Unsolvable" << endl;
            }
        }
    }

    return 0;
}


