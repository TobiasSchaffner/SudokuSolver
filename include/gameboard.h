#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#include <stack>
#include <list>
#include "move.h"

class Gameboard {

private:
    unsigned int size;
    int** boardData;

    bool checkRow(Move* move);
    bool checkColumn(Move* move);
    bool checkField(Move* move);

public:
    Gameboard(unsigned int size);
    ~Gameboard();

    /**
     * Get the size of the board.
     * @return The size of the board.
     */
    int getSize() const;

    /**
     * Search for an empty field.
     * @param move Pointer to a move object that will be filled with the data.
     * @return true if an empty field was found else otherwise.
     */
    bool getEmptyField(Move* move);

    /**
     * Set the value in the move object at the position set in the move object.
     * @param move Pointer to a move object that contains the data where to set the number.
     */
    void applyMove(Move* move);

    /**
     * Revert a move.
     * @param move Pointer to a move object that shuld be reverted.
     */
     bool revertMove(Move* move);

    /**
     * Check if a number can be set at a certain position.
     * @param move the move object holds a the position and the value that should be set.
     * @return true if possible false if not.
     */
    bool isPossible(Move* move);

    /**
     * Return the gameboard as 2D Array.
     * @return A 2D representation of the board.
     */
    int** get2DArray() const;
};

#endif