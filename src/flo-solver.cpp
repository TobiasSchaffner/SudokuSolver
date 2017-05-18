//
// Created by confix on 5/8/17.
//

#include <gameboard.h>
#include <util.h>
#include <exception/no-such-move-exception.h>
#include "flo-solver.h"


FloSolver::FloSolver(Gameboard *board) {
    if (board == NULL)
        throw std::invalid_argument("Whatever");
    this->board = board;
    this->moves = new std::stack<Kp>();
    this->waypoints = new std::stack<int>();
}

bool FloSolver::evaluateNext() {
    bool result = true;
    try {
        makeNextMove();
    } catch (NoSuchMoveException *ex) {
        if (!this->board->isSolved())
            result = trackBack();
        else
            return false;
    }
    return result;
}

void FloSolver::makeNextMove() {
    Move m = this->getNextMove();

    assert(this->board->nextMove(m.column, m.row, m.value));

    this->moves->push(Kp{m, (1 << (m.value - 1))});
}

bool FloSolver::trackBack() {
    bool wasSuccess = false;

    if (!this->waypoints->empty()) {

        int wp = this->waypoints->size();
        int top = this->waypoints->top();
        int mvs = this->moves->size();
        while (this->waypoints->top() < this->moves->size()) {
            this->board->revertMove(this->moves->top().move);
            this->moves->pop();
        }

        Kp m = this->moves->top();
        this->board->revertMove(m.move);
        int p = this->board->getPossibleMoves(m.move.column, m.move.row);
        unsigned short possibles = this->board->getPossibleMoves(m.move.column, m.move.row) - m.tryMask;
        unsigned short rightest = getRightestBitNumber(possibles);
        m.tryMask += rightest;
        this->board->nextMove(m.move.column, m.move.row, rightest);
        if(possibles == rightest) {
            this->waypoints->pop();
            this->moves->pop();
        }
        wasSuccess = true;
    }
    return wasSuccess;
}


Move FloSolver::getNextMove() const {
    int min = 10;
    int rowPos = -1;
    int colPos = -1;

    unsigned short possibleMoves = 0;

    for (int col = 0; col < this->board->getSize(); ++col) {
        for (int row = 0; row < this->board->getSize(); ++row) {
            int possibles = this->board->getPossibleMoves(col, row);
            int count = __builtin_popcount(possibles);
            if (count > 0) {
                if (count < min) {
                    rowPos = row;
                    colPos = col;
                    min = count;
                    possibleMoves = possibles;
                }
            }
        }
    }

    if (rowPos >= 0 && colPos >= 0 && min > 0) {
        unsigned short val = getRightestBitNumber(possibleMoves);

        if (min > 1) this->waypoints->push(this->moves->size() + 1);

        return Move(colPos, rowPos, val);
    }
    throw new NoSuchMoveException;
}
