#include <iostream>
#include "gameboard.h"

using namespace std;

void printBinaryAsString(ostream& out, unsigned short byte);
unsigned short freeSlots(unsigned short row, unsigned short col, unsigned short segment);


int main() {

    Gameboard* gb = new Gameboard();
    Step s = gb->set(1,1,4);
    std::cout << s.row << " " << s.col << " ";
    printBinaryAsString(std::cout, s.value);
    std::cout << endl;
    return 0;
}

void printBinaryAsString(ostream& out, unsigned short byte) {

    for(int i = 0; i < 9; ++i)
        out << (byte & Gameboard::BIT_CONSTS[i] ? '1' : '0');
}
