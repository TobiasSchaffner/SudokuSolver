#include <gameboard.h>
#include <move.h>
#include <solver.h>
#include <util.h>


Solver::Solver(Gameboard *gameboard) {
    this->gameboard = gameboard;
}

bool Solver::solve() {
    Move *move = new Move();

    //if (!gameboard->getEmptyField(move)) {
    if (!getNextMove(move)) {
        // Wenn kein freies Feld mehr verfügbar ist ist das Board gelöst.
        return true;
    }

    for (move->value = 1; move->value <= gameboard->getSize(); move->value++) {
        if (gameboard->isPossible(move)) {
            gameboard->applyMove(move);

            // Rekursiver Aufruf der solve() Methode.
            if (solve()) {
                return true;
            } else {
                // Gibt solve() false zurück, gab es keine Möglichkeit mehr und wir sind in einem falschen Ast gelandet.
                gameboard->revertMove(move);
            }
        }
    }
    return false;
}

bool Solver::getNextMove(Move *move) {
    int max = 0;

    for (int col = 0; col < this->gameboard->getSize(); ++col) {
        for (int row = 0; row < this->gameboard->getSize(); ++row) {
            int possibles = this->gameboard->getPossibleMoves(col, row);
            int count = __builtin_popcount(possibles);

            if (count > max) {
                move->column = col;
                move->row = row;
                max = count;
            }
        }
    }
    return max > 0;
}
