#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#include <stack>
#include <list>
#include "move.h"

class Gameboard {

private:
    /** The number of values that have been set. */
    std::stack<Move> moves;

    /** A Stack of moves heights. Every time we have to make a guess we note the height of the move stack.
     * If we come to a situation where we can't go on anymore we go back to the last guess and go on there.
     */
    std::stack<unsigned short> guesses;

    unsigned int size;
    unsigned int segLength;
    unsigned short *rows;
    unsigned short *columns;
    unsigned short *segments;

    unsigned int max_possibles;

    /** holds the positions for a class. All positions start in class 0. If a position is set it goes to class 21 */
    std::list<unsigned short> *class2position;

    /** holds the classes for a position. There are 81 positions. 9*column + row */
    unsigned short *position2class;

     /**
     * Executes a Step.
     * @param step The step that shall be executed.
     */
    void next(Move);


    unsigned short getPossibleMoves(unsigned short column, unsigned short row);

    /**
     * Set the new Class for a Position.
     * @param position The Positon in 1D between 0 and 80.
     * @param newClass The new Class.
     */
    void adjustClass(unsigned short position, unsigned short newClass);

    /**
     * Adjust the classes around a position.
     * @param inputColumn The column of the 2D position.
     * @param inputRow The row of the 2D position.
     * @param up True if we want to push the classes after setting a value. False if we want to lower after removing a value.
     */
    void adjustClasses(unsigned short inputColumn, unsigned short inputRow, short change);

    /* We step by step increase the number of possible numbers we allow for class2position by the window variable.
     * In the first run we only predict a number for positions when there is only one possible number left.
     * If we can not find such a position anymore we have to increase window by one and try our luck with a
     * position with two possibilities.
     * If we have more than one possibility we have to make a guess. In this case we save guessed position by
     * pushing the stack position of the corresponding move on the guesses stack.
     * If we can not find a position to set a number we have done something wrong and have to go back to the last guess.
     * If there are other Numbers left that we can try for that position we try the next higher number. (next set bit
     * left from the bit of the last try)
     * If we can't we have done something wrong before that guess and have to go back one guess and try to proceed
     * there instead.
     * We return false if there is no solution for the board or the board is already filled.
     */
    bool hasMostPromisingField();

    bool guessNextMove();

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
     * Revert the last step.
     * @return True is reverted. False if there is nothing to revert.
     */
    bool undo();

    /**
     * Try to set the next position.
     * @return True if a value was set. False if already finished or unsolvable.
     */
    bool evaluateNext();

    /**
     * Reconstruct a 2D Array out of the internal bit masks.
     * @return A 2D Array board[columns][rows] representing the board.
     */
    unsigned short** get2DArray();

    /** Construct a printable array representation of the Classes. */
    unsigned short* getClasses();

    /** True if solved. False if not. */
    bool isSolved();
};

#endif