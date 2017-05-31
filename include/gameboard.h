#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#include <stack>
#include <list>
#include "move.h"

class Gameboard {


private:

    static constexpr char* MS_ERR_ROW = "Row %d exceeds limits\n";
    static constexpr char* MS_ERR_COL = "Column %d exceeds limits\n";
    unsigned int size;
    unsigned int segLength;
    unsigned short *rows;
    unsigned short *columns;
    unsigned short *segments;

    unsigned int max_possibles;

     /**
     * Executes a Step.
     * @param step The step that shall be executed.
     */
    void next(Move);

    int** boardData;

public:
    Gameboard(unsigned int size);
    ~Gameboard();

    const unsigned short getPossibleMoves(unsigned short column, unsigned short row) const;

    const unsigned int getSize() const;

    int** get2DArray() const;

    bool isPosInBounds(unsigned short) const;

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
    bool revertMove(Move move);

    bool isSolved();

};

#endif