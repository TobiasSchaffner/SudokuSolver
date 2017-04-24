#include <cmath>
#include "../include/gameboard.h"
#include "../include/util.h"

Gameboard::Gameboard(unsigned int size) {
    const unsigned int arrayLen = size - 1;
    this->rows = new unsigned short[arrayLen];
    this->columns = new unsigned short[arrayLen];
    this->segments = new unsigned short[arrayLen];
    this->size = size;
    this->segLength = (unsigned int) sqrt(size);
}

Gameboard::~Gameboard() {
    delete(this->rows);
    delete(this->columns);
    delete(this->segments);
}

bool Gameboard::nextMove(unsigned short column, unsigned short row, unsigned short value) {
    assert(0 < column <= this->size);
    assert(0 < row <= this->size);
    assert(0 < value <= this->size);
    bool moveValid = false;
    const unsigned short mask = (1 << (value - 1));
    if((mask & this->getPossibleMoves(column - 1, row - 1)) == mask) {
        Move nextMove(column - 1, row - 1, mask);
        this->next(nextMove);
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

