#include <iostream>
#include "gameboard.h"

using namespace std;

int main() {
    Gameboard* gameboard = new Gameboard();
    for (unsigned short i = 1; i<10; ++i) gameboard->set(i,i,i);
    gameboard->print();
    cout << endl;
    while (gameboard->getSteps() > 0) gameboard->revert();
    gameboard->print();
    return 0;
}

