#include <cmath>
#include "../include/gameboard.h"
#include "../include/util.h"

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
    const int seg = move.column / 3 * move.row / 3;
    this->columns[move.column] = this->columns[move.column] | move.value;
    this->rows[move.row] = this->rows[move.row] | move.value;
    this->segments[seg] = this->segments[seg] | move.value;
    this->moves.push(move);
}

bool Gameboard::undo() {
    if (moves.empty()) return false;
    Move m = this->moves.top();
    const int seg = this->getSegmentNo(m.column, m.row);
    // apply reverse bitmask to rol/col/seg information
    this->columns[m.column] = this->columns[m.column] ^ m.value;
    this->rows[m.row] = this->rows[m.row] ^ m.value;
    this->segments[seg] = this->segments[seg] ^ m.value;

    adjustClasses(m.column, m.row, false);

    moves.pop();
    return true;
}

unsigned short Gameboard::getPossibleMoves(unsigned short column, unsigned short row) {
    const int seg = column / 3 * row / 3;
    return SEGMENT_COMPLETE - (
            this->rows[row] | this->columns[column] | this->segments[seg]);
}

int** Gameboard::get2DArray(){
    int** board = 0;
    board = new int*[9];
    for (int height = 0; height < 9; ++height) board[height] = new int[9];
    for (unsigned short column = 0; column<9; column++) {
        unsigned short column_short = this->columns[column];
        for(unsigned short number = 1; number < 10; number++) {
            if (column_short & BIT_CONSTS[number - 1]) {
                for (unsigned short row = 0; row < 9; row++) {
                    if(this->rows[row] & (1 << (number - 1))) {
                        board[column][row] = number;
                    }
                }
            }
        }
    }
    return board;
}

int Gameboard::getSegmentNo(unsigned int col, unsigned int row) const {
    const int segLength = (const int) sqrt(this->size);
    return col / segLength * row / segLength;
}

void Gameboard::print(){
    int** board = this->get2DArray();
    for (int row = 0; row < 9; ++row) {
        for (int column = 0; column<9; ++column) {
            std::cout << board[column][row] << " ";
        }
        std::cout << std::endl;
    }
}

void Gameboard::printClasses(){
    for (int row = 0; row < 9; ++row) {
        for (int column = 0; column<9; ++column) {
            std::cout << position2class[column*9+row] << " ";
        }
        std::cout << std::endl;
    }
}

