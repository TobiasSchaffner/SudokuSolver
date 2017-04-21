#include <stack>
#include "step.h"

#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#endif //SUDOKU_GAMEBOARD_H


class Gameboard {

private:
    /** The number of values that have been set. */
    std::stack<Step> steps;

    unsigned short *rows;
    unsigned short *columns;
    unsigned short *segments;

     /**
     * Executes a Step.
     * @param step The step that shall be executed.
     */
    void set(Step step);

    /**
     * Reconstruct a 2D Array out of the internal bit masks.
     * @return A 2D Array board[columns][rows] representing the board.
     */
    int** get2DArray();

    /**
     * Reverts a Step.
     * @param step The step that shall be reverted.
     */
    void revert(Step step);

public:
    Gameboard();
    ~Gameboard();

    /**
     * A human readable setter with column, row and value as numbers from 1 to 9.
     * Returns the resulting step holding indexes from 0 to 8 and a value bitmask.
     * @param column The column from 1 to 9
     * @param row The row from 1 to 9
     * @param value The value from 1 to 9
     * @return A Step object containing this action.
     */
    Step set(unsigned short column, unsigned short row, unsigned short value);

    /**
     * Get the number of Steps done.
     * @return The size of the Stack holding the steps.
     */
    unsigned long getSteps();

    /**
     * Revert the last step.
     * @return True is reverted. False if there is nothing to revert.
     */
    bool revert();

    /**
     * Prints a 2D Array representation of the board.
     */
    void print();

    unsigned short getPossibleMoves(unsigned short column, unsigned short row);
};