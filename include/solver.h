//
// Created by confix on 5/8/17.
//

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include "solvers.h"
#include "kp.h"


class Solver : public Solvers {
private:

    /**
     * Gameboard instance to solve.
     */
    Gameboard* board;

    /**
     * Containg all moves.
     */
    std::stack<Kp>* moves;

    /**
     * Containing the points where to branch.
     */
    std::stack<int>* waypoints;

    /**
     * Try to evaluate the next move.
     */
    void makeNextMove();

    /**
     * Erase the moves stack until last branch
     * @return backtracking successful
     */
    bool trackBack();

    /**
     * Returns the next possible move.
     * @return
     */
    Move getNextMove() const;


public:

    Solver(Gameboard* board);

    bool evaluateNext();

    bool solve();
};



#endif //SUDOKU_SOLVER_H
