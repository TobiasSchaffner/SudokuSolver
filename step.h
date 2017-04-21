//
// Created by confix on 4/20/17.
//

#include <iostream>

#ifndef SUDOKU_STEP_H
#define SUDOKU_STEP_H

#endif //SUDOKU_STEP_H

struct Step {

    /**
     * Creates a Step Object.
     * @param column Column index from 0 to 8.
     * @param row Row index from 0 to 8.
     * @param value A Bitmask representing the value.
     */
    Step(unsigned short column, unsigned short row, unsigned short value){
        this->column = column;
        this->row = row;
        this->value = value;
    }

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