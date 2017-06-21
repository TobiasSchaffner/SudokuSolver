//
// Created by platypus on 5/31/17.
//

#ifndef SUDOKU_CREATOR_H
#define SUDOKU_CREATOR_H


#include "solver.h"

/**
 * @file generator.h
 *
 * @brief Contains the declaration of the Generator.class.
 *
 * Implemented in generator.cpp.
 *
**/

/**
 * @class Generator
 * @brief Generates gameboards with given number of unfilled fields.
 */
class Generator {

private:
    int* randomArray(int size);
    Gameboard* getSeededGameboard(int size);
    void randomRemove(Gameboard* gameboard, int solved);

public:
    /**
     * @brief
     *
     * @param size size of the board to be created. Boards will always be created as a square.
     * @param solved number of fields, that should be filled in the created board.
     * @return a gameboard with the given specs.
     */
    Gameboard* generate(int size, int solved);
};


#endif //SUDOKU_CREATOR_H
