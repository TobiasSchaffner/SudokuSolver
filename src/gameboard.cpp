#include <cmath>
#include "../include/gameboard.h"
#include "util.h"

#define DEBUG 0

Gameboard::Gameboard(unsigned int size) {
    const unsigned int arrayLen = size - 1;
    this->rows = new unsigned short[arrayLen];
    this->columns = new unsigned short[arrayLen];
    this->segments = new unsigned short[arrayLen];

    this->class2position = new std::list<unsigned short>[21 + 1];
    this->position2class = new unsigned short[81];
    for (unsigned short i = 0; i<81; ++i) {
        position2class[i] = 0;
        class2position[0].push_back(i);
    }

    this->size = size;
    this->segLength = (unsigned int) sqrt(size);
}

Gameboard::~Gameboard() {
    delete(this->rows);
    delete(this->columns);
    delete(this->segments);
}

void Gameboard::adjustClasses(unsigned short inputColumn, unsigned short inputRow, short change){
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

void Gameboard::adjustClass(unsigned short position, unsigned short newClass){
    class2position[position2class[position]].remove(position);
    position2class[position] = newClass;
    class2position[position2class[position]].push_back(position);
    class2position[position2class[position]].sort();
}

bool Gameboard::evaluateNext() {
    if (isSolved()) return false;

    /* We step by step higher the number of possible numbers we allow for class2position by the window variable.
    * In the first run we only predict a number for positions when there is only one possible number left.
    * If we can not find such a position anymore we have to higher window by one and try our luck with a
    * position with two possibilities.
    * If we have more than one possibiliy we have to make a guess. In this case we save the position of the guess by
    * pushing the stack position of the corresponding move on the guesses stack.
    * If we can not find a position to set a number we have done something wrong and have to go back to the last guess.
    * If there are other Numbers left that we can try for that position we try the next higher number. (next set bit
    * left from the bit of the last try)
    * If we can't we have done something wrong before that guess and have to go back one guess and try to proceed
    * there instead.
    * We return false if there is no solution for the board or the board is already filled.
    */
    for (unsigned short window = 1; window <= 9; ++window) {

        /* Start with the class we know the most. */
        for (short predictionClass = 20; predictionClass >= 9 - window; --predictionClass) {
            if (!class2position[predictionClass].empty()) {

                /* Get every position in the class. */
                for (unsigned short position : class2position[predictionClass]) {
                    unsigned short column = position / size;
                    unsigned short row = position % size;

                    /* Get the intersection of possibles of the Row/Column/Field of the position. */
                    unsigned short possibles = getPossibleMoves(column, row);

                    /* If there are as many possible number as out window allows. */
                    if (__builtin_popcount(possibles) == window) {
                        nextMove(column + 1, row + 1, getRightestBitNumber(possibles));
                        /* If our window is bigger than 1 we had to make a guess and. */
                        if (window > 1) guesses.push(moves.size());
                        if (DEBUG) printf("Setting move Nr: %d column: %d row: %d value: %d\n", moves.size(), column+1, row+1, getRightestBitNumber(possibles));
                        return true;
                    }
                }
            }
        }
    }

    // We couldn't find position to set a move above. Now we roll back to the last guess and pick the next number.
    while (guesses.size() > 0) {
        while (moves.size() > guesses.top()) undo();
        Move wrongMove = moves.top();
        if (DEBUG) printf("Reverted to wrong move Nr: %d column: %d row: %d value: %d\n", guesses.top(), wrongMove.column, wrongMove.row, getRightestBitNumber(wrongMove.value));
        undo();

        unsigned short possibles = getPossibleMoves(wrongMove.column, wrongMove.row);
        unsigned short value = getBitLeft(possibles, wrongMove.value);

        // If there is a number left to try. We set that value and return.
        if (value) {
            nextMove(wrongMove.column + 1, wrongMove.row + 1, getRightestBitNumber(value));
            if (DEBUG) printf("Setting move Nr: %d colummn: %d row: %d value: %d\n", moves.size(), wrongMove.column, wrongMove.row, getRightestBitNumber(value));
            return true;
        }
        // Else we go back to the guess before and proceed.
        guesses.pop();
    }
    // If there are no positions anymore where we could have done a wrong decision we ran over the whole tree without a solution.
    printf("unsolvable!");
    return false;
}

bool Gameboard::nextMove(unsigned short column, unsigned short row, unsigned short value) {
    assert(0 < column <= this->size);
    assert(0 < row <= this->size);
    assert(0 < value <= this->size);
    bool moveValid = false;
    const unsigned short mask = (1 << (value - 1));
    if((mask & this->getPossibleMoves(column - 1, row - 1)) == mask) {
        Move nextMove(column - 1, row - 1, mask);
        next(nextMove);
        adjustClasses(column - 1, row - 1, 1);
        adjustClass((column - 1) * 9 + row - 1, 21);
        moveValid = true;
    }
    return moveValid;
}

bool Gameboard::undo() {
    if (moves.empty()) return false;
    Move m = this->moves.top();
    const int seg = getSegmentNumber(m.column, m.row);
    // apply reverse bitmask to rol/col/seg information
    this->columns[m.column] = this->columns[m.column] ^ m.value;
    this->rows[m.row] = this->rows[m.row] ^ m.value;
    this->segments[seg] = this->segments[seg] ^ m.value;

    adjustClasses(m.column, m.row, -1);

    moves.pop();
    return true;
}

bool Gameboard::isSolved() {
    return pow(this->size, 2) == this->moves.size();
}

void Gameboard::next(Move move) {
    const unsigned short seg = getSegmentNumber(move.column, move.row);
    this->columns[move.column] = this->columns[move.column] | move.value;
    this->rows[move.row] = this->rows[move.row] | move.value;
    this->segments[seg] = this->segments[seg] | move.value;
    this->moves.push(move);
}


unsigned short Gameboard::getPossibleMoves(unsigned short column, unsigned short row) {
    const unsigned short seg = getSegmentNumber(column, row);
    return SEGMENT_COMPLETE - (
            rows[row] | columns[column] | segments[seg]);
}

unsigned short** Gameboard::get2DArray(){
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

unsigned short* Gameboard::getClasses() {
    return position2class;
}
