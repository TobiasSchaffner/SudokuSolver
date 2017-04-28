#include <assert.h>
#include "../include/util.h"
#include "string.h"

char* getBinaryAsString(unsigned short byte) {
    char* result = new char[10];
    for(int i = 0; i < 9; ++i) {
        if (byte & BIT_CONSTS[8 - i]) {
            result[i] = '1';
        } else {
            result[i] = '0';
        }
    }
    result[9] = '\0';
    return result;
}

void printBoard(unsigned short **array, unsigned short size){
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column<size; ++column) {
            printf("%2d ", array[column][row]);
        }
        printf("\n");
    }
    printf("\n");
}

void printBoard(unsigned short *array, unsigned short size){
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column<size; ++column) {
            printf("%2d ", array[column*size+row]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @param input a bitmask for example 000111010
 * @return would lead to 000000010
 */
unsigned short getRightestBit(unsigned short input) {
    unsigned short result;
    for (unsigned short bitmask : BIT_CONSTS) {
        result = input & bitmask;
        if (result) {
            break;
        }
    }
    return result;
}

/**
 * @param input a bitmask for example 000111010
 * @return in case of 000111010 2;  0 if 000000000
 */
unsigned short getRightestBitNumber(unsigned short input) {
    for (unsigned short i = 0; i < 9; ++i) {
        if (input & BIT_CONSTS[i]) {
            return i + 1;
        }
    }
    return 0;
}

unsigned short getSegmentNumber(unsigned short column, unsigned short row) {
    return (row / 3) * 3 + column / 3;
}