#ifndef SUDOKU_MOVE_H
#define SUDOKU_MOVE_H

#include<iostream>
#include <assert.h>

struct Move {

    /**
     * Creates a Step Object.
     * @param column Column index from 0 to 8.
     * @param row Row index from 0 to 8.
     * @param value A Bitmask representing the value.
     */
    Move(unsigned short column, unsigned short row, unsigned short value);

    /** Column index from 0 to 9. */
    unsigned short column;

    /** Row index from 0 to 8. */
    unsigned short row;

    /**
     * This is a Bitmask representing a value.
     * 1 = 000000001
     * 2 = 000000010
     * 3 = 000000100
     * ...
     * 9 = 100000000
     */
    unsigned short value;
};

#endif
