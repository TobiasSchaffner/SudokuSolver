//
// Created by confix on 5/3/17.
//

#ifndef SUDOKU_SOLVERS_H
#define SUDOKU_SOLVERS_H


class Solvers {
public:
    virtual bool evaluateNext() = 0;
    virtual bool solve() = 0;
};


#endif //SUDOKU_SOLVER_H
