#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#include <stack>
#include <list>
#include "move.h"

class Gameboard {

private:
    /** The number of values that have been set. */
    std::stack<Move> moves;
    std::stack<unsigned short> guesses;

    unsigned int size;
    unsigned int segLength;
    unsigned short *rows;
    unsigned short *columns;
    unsigned short *segments;

    /** holds the positions for a class. All positions start in class 0. If a position is set it goes to class 21 */
    std::list<unsigned short> *class2position;

    /** holds the classes for a position. There are 81 positions. 9*column + row */
    unsigned short *position2class;

     /**
     * Executes a Step.
     * @param step The step that shall be executed.
     */
    void next(Move);

    /**
     * Revert the last step.
     * @return True is reverted. False if there is nothing to revert.
     */
    bool undo();

    unsigned short getPossibleMoves(unsigned short column, unsigned short row);

    void adjustClass(unsigned short position, unsigned short newClass);

    void adjustClasses(unsigned short inputColumn, unsigned short inputRow, bool up);

    Move* getNextMove(Move *lastMove);

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

    Move lastMove();

    bool evaluateNext();

    /**
     * Reconstruct a 2D Array out of the internal bit masks.
     * @return A 2D Array board[columns][rows] representing the board.
     */
    unsigned short** get2DArray();

    unsigned short* getClasses();

    bool isSolved();
};

#endif