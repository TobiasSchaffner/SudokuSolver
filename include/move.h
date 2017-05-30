#ifndef SUDOKU_MOVE_H
#define SUDOKU_MOVE_H

#include<iostream>
#include <assert.h>

struct Move {

    Move();
    Move(int column, int row, int value);

    int column;
    int row;
    int value;
};

#endif
