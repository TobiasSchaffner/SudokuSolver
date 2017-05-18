
#include <tobi-solver.h>
#include <util.h>
#include <cmath>

TobiSolver::TobiSolver(Gameboard* board) {
    this->moves = std::stack<Move>();
    this->guesses = std::stack<long>();
    this->board = board;


    this->class2position = new std::list<unsigned short>[21 + 1];
    this->position2class = new unsigned short[81];
    for (unsigned short i = 0; i<81; ++i) {
        position2class[i] = 0;
        class2position[0].push_back(i);
    }

    int** arr = board->get2DArray();
    for(int i = 0; i < board->getSize(); ++i) {
        for(int j = 0; j < board->getSize(); ++j) {

        }
    }
}


void TobiSolver::adjustClass(unsigned short position, unsigned short newClass){
    class2position[position2class[position]].remove(position);
    position2class[position] = newClass;
    class2position[position2class[position]].push_back(position);
    class2position[position2class[position]].sort();
}


void TobiSolver::adjustClasses(unsigned short inputColumn, unsigned short inputRow, short change){
    unsigned short newPositionClass = 0;
    unsigned short position = 0;

    for(unsigned short column = 0; column < 9; ++column){
        if (column != inputColumn) {
            position = column * 9 + inputRow;
            if (position2class[position] != 21) {
                adjustClass(position, position2class[position] + change);
            } else newPositionClass++;
        }
    }

    for(unsigned short row = 0; row < 9; ++row){
        if (row != inputRow) {
            position = inputColumn * 9 + row;
            if (position2class[position] != 21) {
                adjustClass(position, position2class[position] + change);
            } else newPositionClass++;
        }
    }

    unsigned short fieldStartRow = (inputRow / 3) * 3;
    unsigned short fieldStartColumn = (inputColumn / 3) * 3;

    for(unsigned short column = fieldStartColumn; column < fieldStartColumn + 3; ++column){
        for(unsigned short row = fieldStartRow; row < fieldStartRow + 3; ++row) {
            if (column != inputColumn && row != inputRow) {
                position = column * 9 + row;
                if (position2class[position] != 21) {
                    adjustClass(position, position2class[position] + change);
                } else newPositionClass++;
            }
        }
    }

    position = inputColumn * 9 + inputRow;
    adjustClass(position, newPositionClass);
}

bool TobiSolver::undo() {
    if (moves.empty()) return false;
    Move m = this->moves.top();
    adjustClasses(m.column, m.row, -1);
    this->board->revertMove(m);
    moves.pop();
    return true;
}


bool TobiSolver::hasMostPromisingField() {

    for (unsigned short window = 1; window <= 9; ++window) {

        /* Start with the class we know the most. */
        for (short predictionClass = 20; predictionClass >= 9 - window; --predictionClass) {
            if (!class2position[predictionClass].empty()) {

                /* Get every position in the class. */
                for (unsigned short position : class2position[predictionClass]) {
                    unsigned short column = position / 9;
                    unsigned short row = position % 9;

                    /* Get the intersection of possibles of the Row/Column/Field of the position. */
                    unsigned short possibles = this->board->getPossibleMoves(column, row);

                    /* If there are as many possible number as out window allows. */
                    if (__builtin_popcount(possibles) == window) {
                        if(this->board->nextMove(column + 1, row + 1, getRightestBitNumber(possibles))) {
                            adjustClasses(column, row, 1);
                            adjustClass((column) * 9 + row, 21);
                        }
                        /* If our window is bigger than 1 we had to make a guess and. */
                        if (window > 1) guesses.push(moves.size());
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


bool TobiSolver::guessNextMove() {
    // We couldn't find position to set a move above. Now we roll back to the last guess and pick the next number.
    while (guesses.size() > 0) {
        while (moves.size() > guesses.top()) undo();
        Move wrongMove = moves.top();
        undo();

        unsigned short possibles = this->board->getPossibleMoves(wrongMove.column, wrongMove.row);
        unsigned short value = getBitLeft(possibles, wrongMove.value);

        // If there is a number left to try. We set that value and return.
        if (value) {
            if(this->board->nextMove(wrongMove.column + 1, wrongMove.row + 1, getRightestBitNumber(value))) {
                adjustClasses(wrongMove.column, wrongMove.row, 1);
                adjustClass((wrongMove.column) * 9 + wrongMove.row, 21);
            }
            return true;
        }
        // Else we go back to the guess before and proceed.
        guesses.pop();
    }
    // If there are no positions anymore where we could have done a wrong decision we ran over the whole tree without a solution.
    printf("unsolvable!");
    return false;

}


bool TobiSolver::isSolved() {
    return pow(9, 2) == this->moves.size();
}


bool TobiSolver::evaluateNext() {
    if (isSolved()) return false;

    return this->hasMostPromisingField() || this->guessNextMove();

}


/*
unsigned short** TobiSolver::get2DArray(){
    unsigned short** board = 0;
    board = new unsigned short*[9];
    for (unsigned short height = 0; height < 9; ++height) board[height] = new unsigned short[9] {0};
    std::stack<Move> temp;
    while (moves.size() > 0) {
        board[moves.top().column][moves.top().row] = getRightestBitNumber(moves.top().value);
        Move move = moves.top();
        temp.push(move);
        moves.pop();
    }
    while (temp.size() > 0) {
        Move move = temp.top();
        moves.push(move);
        temp.pop();
    }
    return board;
}
*/
unsigned short* TobiSolver::getClasses() {
    return position2class;
}