#include "move.h"

Move::Move(unsigned short column, unsigned short row, unsigned short value) {
    assert(0 <= column < 9);
    assert(0 <= row < 9);
    //assert(__builtin_popcount(value) == 1);

    this->column = column;
    this->row = row;
    this->value = value;
}
