#ifndef SOLVER_H
#define SOLVER_H


class Solver {

private:
    Gameboard* gameboard;
public:

    Solver(Gameboard* gameboard);
    ~Solver();

    bool solve();

};

#endif