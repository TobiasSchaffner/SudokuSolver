#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#include <stack>
#include <list>
#include "move.h"

/**
 * @file gameboard.h
 *
 * @brief Contains the declaration of the Gameboard.class.
 *
 * Implemented in gameboard.cpp.
 *
**/

/**
 * @class Gameboard
 *
 * @brief Contains the gameboard-information for a sudoku-game.
 *
 * That includes the rules, where moves are possible to be set. Also it remembers, which fields are already set.
*/
class Gameboard {

private:
    int size;
    int** boardData;

    int *rows;
    int *columns;
    int *segments;

    bool checkRow(Move* move);
    bool checkColumn(Move* move);
    bool checkField(Move* move);

    void revertBitMasks(Move* move);
    void applyBitMasks(Move* move);

    int getSetPositions(int column, int row);

public:
    Gameboard(int size);
    ~Gameboard();

    /**
     * @brief Get the size of the board.
     *
     * @return The size of the board.
     */
    int getSize() const;

    /**
     * @brief Search for the Position with the most set Positions around.
     *
     * @param move Pointer to a move object that will be filled with the data.
     *
     * @return true if an empty firld was found false otherwise.
     */
    bool getPromisingMove(Move *move);

    /**
     * @brief Search for an empty field.
     *
     * @param move pointer to a move object that will be filled with the data.
     *
     * @return true if an empty field was found false otherwise.
     */
    bool getFirstEmptyMove(Move *move);

    /**
     * @brief Set the value in the move object at the position set in the move object.
     *
     * @param move Pointer to a move object that contains the data where to set the number.
     */
    void applyMove(Move* move);

    /**
     * @brief Revert a move.
     *
     * @param move Pointer to a move object that shuld be reverted.
     */
     bool revertMove(Move* move);

    /**
     * @brief Check if a number can be set at a certain position.
     *
     * @param move the move object holds a the position and the value that should be set.
     *
     * @return true if possible false if not.
     */
    bool isPossible(Move* move);

    /**
     * @brief Return the gameboard as 2D Array.
     *
     * @return A 2D representation of the board.
     */
    int** get2DArray() const;
};

#endif