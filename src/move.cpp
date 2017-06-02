#include "../include/move.h"

Move::Move() {
    column = 0;
    row = 0;
    value = 0;
}

Move::Move(int column, int row, int value) {
    assert(0 <= column < 9);
    assert(0 <= row < 9);
    assert(0 < value <= 9);

    this->column = column;
    this->row = row;
    this->value = value;
}
