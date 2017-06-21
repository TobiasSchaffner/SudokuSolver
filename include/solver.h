#ifndef SOLVER_H
#define SOLVER_H

/**
 * @file solver.h
 *
 * @brief Contains the declaration of the Solver.class.
 *
 * Implemented in solver.cpp.
 *
**/

/**
 * @class Solver
 * @brief provides the possibility to solve given gameboards.
 *
 * The solver solves given gameboards if possible. If it is given a not solvable board it will return false.
 */
class Solver {

private:
    Gameboard *gameboard;

public:
    Solver(Gameboard *gameboard);
    ~Solver();

    /**
     * @brief method, to solve the gameboard given in the constructor.
     *
     * the method will call itself recursively till the board is solved. If the recursive call returns false, the last move will be reverted on the board.
     * @return true, if the board was solved, false if no move can be applied in the given situation.
     */
    bool solve();
};

#endif