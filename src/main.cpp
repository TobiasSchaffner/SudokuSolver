#include <iostream>
#include <../include/board-initializer.h>
#include <../include/util.h>
#include <../include/generator.h>

using namespace std;

int main() {
    //auto binit = new BoardInitializer();

    auto generator = new Generator();
    auto gameboard = generator->generate(9, 50);
    auto solve = new Solver(gameboard);
    solve->solve();
    print2DArray(gameboard->get2DArray(), 9);
/*
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

            print2DArray(gameboard->get2DArray(), 9);
            auto solver = new Solver(gameboard);
            solver->solve();
            print2DArray(gameboard->get2DArray(), 9);
        }
    }
    */

    return 0;
}


