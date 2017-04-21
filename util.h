//
// Created by platypus on 4/21/17.
//

#ifndef SUDOKU_UTIL_H
#define SUDOKU_UTIL_H

#endif //SUDOKU_UTIL_H

/** The Bitmasks for the values 1 to 9 while [0] = 1, [1] = 2 and so on. */
const static unsigned short BIT_CONSTS[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100};

const unsigned short Gameboard::SEGMENT_COMPLETE = 511;

void printBinaryAsString(std::ostream& out, unsigned short byte) {
    for(int i = 0; i < 9; ++i)
        out << (byte & BIT_CONSTS[i] ? '1' : '0');
}