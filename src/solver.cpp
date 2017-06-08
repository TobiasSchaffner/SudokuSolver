#include "../include/gameboard.h"
#include "../include/solver.h"

Solver::Solver(Gameboard *gameboard) {
    this->gameboard = gameboard;
}

Solver::~Solver() {}

bool Solver::solve() {
    Move *move = new Move();

    // Wenn kein freies Feld mehr verfügbar ist, ist das Board gelöst.
    if (!gameboard->getPromisingMove(move))
        return true;

    for (move->value = 1; move->value <= gameboard->getSize(); move->value++) {
        if (gameboard->isPossible(move)) {
            gameboard->applyMove(move);

            // Rekursiver Aufruf der solve() Methode.
            if (solve())
                return true;

            // Gibt solve() false zurück, gab es keine Möglichkeit mehr und wir sind in einem falschen Ast gelandet.
            gameboard->revertMove(move);
        }
    }
    return false;
}

