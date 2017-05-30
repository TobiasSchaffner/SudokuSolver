#include "move.h"

Move::Move() {
    this->column = 0;
    this->row = 0;
    this->value = 0;
}

Move::Move(int column, int row, int value) {
    assert(0 <= column < 9);
    assert(0 <= row < 9);
    assert(0 < value <= 9);

    this->column = column;
    this->row = row;
    this->value = value;
}
