#ifndef SUDOKU_UTIL_H
#define SUDOKU_UTIL_H

#include "iostream"

/** The Bitmasks for the values 1 to 9 while [0] = 1, [1] = 2 and so on. */
const static unsigned short BIT_CONSTS[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100};

const unsigned short SEGMENT_COMPLETE = 511;

char* getBinaryAsString(unsigned short byte);

void printBoard(unsigned short **array, unsigned short size);

void printBoard(unsigned short *array, unsigned short size);

unsigned short getRightestBit(unsigned short input);

unsigned short getRightestBitNumber(unsigned short input);

unsigned short getSegmentNumber(unsigned short column, unsigned short row);

#endif