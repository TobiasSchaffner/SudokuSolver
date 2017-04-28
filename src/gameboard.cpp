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

void Gameboard::adjustClasses(unsigned short inputColumn, unsigned short inputRow, bool up){
    short class_change = 0;
    if (up) class_change = 1;
    else class_change = -1;

    unsigned short position = inputColumn*9+inputRow;
    adjustClass(position, 21);

    for(unsigned short column = 0; column < 9; ++column){
        position = column*9 + inputRow;
        adjustClass(position, position2class[position] + class_change);
    }

    for(unsigned short row = 0; row < 9; ++row){
        position = inputColumn*9 + row;
        adjustClass(position, position2class[position] + class_change);
    }

    unsigned short fieldStartRow = (inputRow / 3) * 3;
    unsigned short fieldStartColumn = (inputColumn / 3) * 3;

    for(unsigned short column = fieldStartColumn; column < fieldStartColumn + 3; ++column){
        for(unsigned short row = fieldStartRow; row < fieldStartRow + 3; ++row) {
            if (column != inputColumn && row != inputRow) {
                position = column * 9 + row;
                adjustClass(position, position2class[position] + class_change);
            }
        }
    }
}

void Gameboard::adjustClass(unsigned short position, unsigned short newClass){
    if (position2class[position] != 21) {
        class2position[position2class[position]].remove(position);
        position2class[position] = newClass;
        class2position[position2class[position]].push_back(position);
        class2position[position2class[position]].sort();
    }
}

bool Gameboard::evaluateNext() {
    /* We step by step higher the number of possible numbers we allow for a class2position.
    * In the first run we only predict a number for positions where theres only one possible number left.
    * If we can not find such a position anymore we have to higher window by one and try our luck with a
    * position with two possibilities.
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

                    if (__builtin_popcount(possibles) == window) {
                        nextMove(column + 1, row + 1, getRightestBitNumber(possibles));
                        if (window > 1) guesses.push(moves.size());
                        printf("Setting move Nr: %d column: %d row: %d value: %d\n", moves.size(), column+1, row+1, getRightestBitNumber(possibles));
                        return true;
                    }
                }
            }
        }
    }
    if (guesses.size() > 0) {
        while (moves.size() > guesses.top()) undo();
        printf("moves size: %d\n", moves.size());
        printf("guesses top: %d\n", guesses.top());
        Move wrongMove = moves.top();
        printf("Reverted to wrong move Nr: %d column: %d row: %d value: %d\n", guesses.top(), wrongMove.column, wrongMove.row, getRightestBitNumber(wrongMove.value));
        undo();

        unsigned short possibles = getPossibleMoves(wrongMove.column, wrongMove.row);
        unsigned short value = getBitLeft(possibles, wrongMove.value);
        if (value) {
            printf("wm c: %d\n", wrongMove.column);
            printf("wm r: %d\n", wrongMove.row);
            printf("rightest %d\n", getRightestBitNumber(value));

            nextMove(wrongMove.column + 1, wrongMove.row + 1, getRightestBitNumber(value));
            printf("Setting move Nr: %d colummn: %d row: %d value: %d\n", moves.size(), wrongMove.column, wrongMove.row, getRightestBitNumber(value));
            return true;
        }
        guesses.pop();
    }
    printf("unsolvable!");
    exit(1);
}

Move* Gameboard::getNextMove(Move *lastMove) {
    unsigned short possibles = getPossibleMoves(lastMove->column, lastMove->row);
    unsigned short mask = ~((lastMove->value << 1) - 1);
    possibles = possibles | mask;
    if (possibles != 0) {
        unsigned short result = getRightestBit(possibles);
        if (result != 0) {
            lastMove->value = result;
            return lastMove;
        }
    } else
        return NULL;
    printf("This may never be reached!");
    assert(false);
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
        adjustClasses(column - 1, row - 1, true);
        moveValid = true;
    }
    return moveValid;
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

bool Gameboard::undo() {
    if (moves.empty()) return false;
    Move m = this->moves.top();
    const int seg = getSegmentNumber(m.column, m.row);
    // apply reverse bitmask to rol/col/seg information
    this->columns[m.column] = this->columns[m.column] ^ m.value;
    this->rows[m.row] = this->rows[m.row] ^ m.value;
    this->segments[seg] = this->segments[seg] ^ m.value;

    adjustClasses(m.column, m.row, false);

    moves.pop();
    return true;
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

Move Gameboard::lastMove() {
    return moves.top();
}