#ifndef SUDOKU_UTIL_H
#define SUDOKU_UTIL_H

#include "iostream"

/** The Bitmasks for the values 1 to 9 while [0] = 1, [1] = 2 and so on. */
const static unsigned short BIT_CONSTS[] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x100};

/** Bitmask for a complete segment. */
const unsigned short SEGMENT_COMPLETE = 511;

/** Get a binary short as printable string. */
char* getBinaryAsString(unsigned short byte);

/** Print a 2D array as board. */
void printBoard(unsigned short **array, unsigned short size);

/** Print a 1D array as board. */
void printBoard(unsigned short *array, unsigned short size);

/**
 * Get only the rightest bit of bitmask if exists.
 * @param input a bitmask for example 000111010
 * @return would lead to 000000010
 */
unsigned short getRightestBit(unsigned short input);

/**
 * Get the rightest bit of a bitmask as number or 0 if theres no bit set.
 * @param input a bitmask for example 000111010
 * @return in case of 000111010 2; 0 if 000000000
 */
unsigned short getRightestBitNumber(unsigned short input);

/**
 * Get the first bit set left of position.
 * @param input the bitmask.
 * @param position the position as a bitmask with only one bit set.
 * @return a bitmask with the first bit set in mask thats left of the bit set in position.
 * Example: input: 000111010 position: 000000010 result: 000001000
 */
unsigned short getBitLeft(unsigned short input, unsigned short position);

/**
 * Get the segment number for a position.
 * @param column the column of the position.
 * @param row the row of the position.
 * @return the number of the segment.
 */
unsigned short getSegmentNumber(unsigned short column, unsigned short row);

#endif