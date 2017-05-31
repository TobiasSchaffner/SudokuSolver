#include "move.h"

Move::Move() {
    this->column = 0;
    this->row = 0;
    this->value = 0;
}

Move::Move(unsigned short column, unsigned short row, unsigned short value) {
    assert(0 <= column < 9);
    assert(0 <= row < 9);
    //assert(__builtin_popcount(value) == 1);

    this->column = column;
    this->row = row;
    this->value = value;
}
