#include <iostream>
#include <../include/board-initializer.h>
#include <../include/util.h>
#include <../include/generator.h>

using namespace std;

int main() {
    auto binit = new BoardInitializer();
    std::map<int, std::string> paths = binit->create();
    auto gameboard = new Gameboard(9);
//    auto generator = new Generator();
//    auto gameboard = generator->generate(9, 50);
//    cout<< "print_" << endl;
//    print2DArray(gameboard->get2DArray(),9);
//    auto solver = new Solver(gameboard);
//    solver->solve();
//    print2DArray(gameboard->get2DArray(), 9);
//    auto solve = new Solver(gameboard);
//    solve->solve();
//    print2DArray(gameboard->get2DArray(), 9);


    // Build board from chosen file f
    // Build board with generator g
    // Solve board s
    // q = quit
    int choice;
    char index = ' ';
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


