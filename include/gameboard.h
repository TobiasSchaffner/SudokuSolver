#include <stack>
#include <list>
#include "move.h"

#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#endif //SUDOKU_GAMEBOARD_H


class Gameboard {

private:
    /** The number of values that have been set. */
    std::stack<Move> moves;

    unsigned int size;
    unsigned int segLength;
    unsigned short *rows;
    unsigned short *columns;
    unsigned short *segments;
    std::list<unsigned short> *class2position;
    unsigned short *position2class;

    int getSegmentNo(unsigned int col, unsigned int row) const;

     /**
     * Executes a Step.
     * @param step The step that shall be executed.
     */
    void next(Move);

    /**
     * Reconstruct a 2D Array out of the internal bit masks.
     * @return A 2D Array board[columns][rows] representing the board.
     */
    int** get2DArray();

    /**
     * Revert the last step.
     * @return True is reverted. False if there is nothing to revert.
     */
    bool undo();

    unsigned short getPossibleMoves(unsigned short column, unsigned short row);

    void adjustClass(unsigned short position, unsigned short newClass);

    void adjustClasses(unsigned short inputColumn, unsigned short inputRow, bool up);

public:
    Gameboard(unsigned int size);
    ~Gameboard();

    /**
     * A human readable setter with column, row and value as numbers from 1 to 9.
     * Returns the resulting step holding indexes from 0 to 8 and a value bitmask.
     * @param column The column from 1 to 9
     * @param row The row from 1 to 9
     * @param value The value from 1 to 9
     * @return A Step object containing this action.
     */
    bool nextMove(unsigned short column, unsigned short row, unsigned short value);

    /**
     * Prints a 2D Array representation of the board.
     */
    void print();
    void printClasses();


    bool isSolved();
};