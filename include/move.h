#ifndef SUDOKU_MOVE_H
#define SUDOKU_MOVE_H

#include<iostream>
#include <assert.h>

/**
 * @file move.h
 *
 * @brief Contains the declaration of the Move.class.
 *
 * Implemented in move.cpp.
 *
**/

/**
 * @class Move
 * @brief a move, that can be executed on a gameboard.
 *
 * the move also is used to revert moves. It contains the comumn and row, where it is set, next to the value to be set.
 */
struct Move {

    Move();
    Move(int column, int row, int value);

    /**
     * @brief the column, where the move is to be set.
     */
    int column;
    /**
    * @brief the row, where the move is to be set.
    */
    int row;
    /**
     * the value to be set.
     */
    int value;
};

#endif
