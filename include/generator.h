//
// Created by platypus on 5/31/17.
//

#ifndef SUDOKU_CREATOR_H
#define SUDOKU_CREATOR_H


#include "solver.h"

class Generator {
private:
    int* randomArray(int size);
    Gameboard* getSeededGameboard(int size);
    void randomRemove(Gameboard* gameboard, int solved);
public:
    Gameboard* generate(int size, int solved);
};


#endif //SUDOKU_CREATOR_H
