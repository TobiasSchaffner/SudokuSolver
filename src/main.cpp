#include <iostream>
#include <../include/board-initializer.h>
#include <../include/util.h>
#include <../include/generator.h>

/**
 * @mainpage Sudoku Solver
 * This innovative programm solves every solvable sudoku before you blink twice.\n
 * It also offers you to generate a sudoku with the difficulty you prefer.\n
 *
 * <img src="../images/sudoku.jpg" alt="Oldschool sudoku" title="Remember?">
 *  <center>Remember this? This is how it used to be done before this powerful tool.\n\n.</center>
 *
 * @author Johannes Bruehl , Manuel Lammich, Florian Pirchmoser, Tobias Schaffner
 */

/**
 * @file Main.cpp
 *
 * @brief Contains the program start, from where the programm gets initialized and the user commandline-interface is started.
 *
 **/


using namespace std;

int main() {
    auto binit = new BoardInitializer();
    auto paths = binit->create();
    auto gameboard = new Gameboard(9);

    int choice;
    auto index = ' ';
    while (index != 'q') {
        cout << "Choose: \nBuild board from file: f\nBuild board with generator: g\nSolve board: s" << endl;
        cin >> index;
        if (cin.fail()) {
            cout << "Please try again!: " << endl;
            cin.clear();
            cin.ignore(256, '\n');

        } else if(index == 'f'){
            cout << "Choose file: " << endl;
            for (auto const itr :paths)
                cout << itr.first << ": " << itr.second.substr(itr.second.find_last_of("/\\")+1, itr.second.size()) << endl;
            cin >> choice;
            gameboard = binit->create(paths[choice]);
            print2DArray(gameboard->get2DArray(), 9);

        } else if(index == 'g'){
            cout << "Choose filled fields: ";
            cin >> choice;
            auto generator = new Generator();
            gameboard = generator->generate(9, choice);
            print2DArray(gameboard->get2DArray(), 9);
        }else if(index == 's') {
            auto solver = new Solver(gameboard);
            solver->solve();
            print2DArray(gameboard->get2DArray(), 9);
        }else{
            cin.clear();
            cin.ignore(256,'\n');
        }
    }


    return 0;
}


