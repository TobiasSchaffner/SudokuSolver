#include "gameboard.h"

/**
 * Bit constants for querying short high to low.
 */
const unsigned short Gameboard::BIT_CONSTS[] = {0x100, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};
const unsigned short Gameboard::SEGMENT_COMPLETE = 511;

Gameboard::Gameboard() {
    this->rows = new unsigned short[9];
    this->cols = new unsigned short[9];
    this->segs = new unsigned short[9];
}

Gameboard::~Gameboard() {
    delete(this->rows);
    delete(this->cols);
    delete(this->segs);
}

Step Gameboard::set(int col, int row, unsigned char value) {
    const unsigned short v = (1 << (value - 1));
    const int seg = col / 3 * row / 3;
    this->rows[row] = this->rows[row] | v;
    this->cols[col] = this->cols[col] | v;
    this->segs[seg] = this->segs[seg] | v;
    return Step(col, row, v);
}

void Gameboard::revert(Step s) {
    const int seg = s.col / 3 * s.row / 3;
    this->rows[s.row] = this->rows[s.row] ^ s.value;
    this->cols[s.col] = this->cols[s.col] ^ s.value;
    this->segs[seg] = this->segs[seg] ^ s.value;
}

unsigned short Gameboard::getPossibleMoves(int col, int row) {
    const int seg = col / 3 * row / 3;
    return SEGMENT_COMPLETE - (
            this->rows[row] | this->cols[col] | this->segs[seg]);
}

