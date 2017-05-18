//
// Created by confix on 5/4/17.
//

#ifndef SUDOKU_TOBI_SOLVER_H
#define SUDOKU_TOBI_SOLVER_H

#include <stack>
#include "move.h"
#include "solver.h"
#include "gameboard.h"

class TobiSolver : public Solver {
private:
    Gameboard* board;
    std::stack<Move> moves;
    std::stack<long> guesses;

    /** holds the positions for a class. All positions start in class 0. If a position is set it goes to class 21 */
    std::list<unsigned short> *class2position;

    /** holds the classes for a position. There are 81 positions. 9*column + row */
    unsigned short *position2class;


    bool guessNextMove();



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

    bool isSolved();


    unsigned short* getClasses();
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

    bool undo();
public:
    TobiSolver(Gameboard* board);
    bool evaluateNext();

};


#endif //SUDOKU_TOBI_SOLVER_H
