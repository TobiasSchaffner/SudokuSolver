#include <iostream>
#include "../include/util.h"

void print2DArray(int **array, int size) {
    for (int column = 0; column < size; ++column) {
        for (int row = 0; row < size; ++row) {
            printf("%2d ", array[column][row]);
        }
        printf("\n");
    }
    printf("\n");
}

unsigned short getSegmentStart(int index) {
    return index - index % 3;
}

unsigned short getSegmentNumber(unsigned short column, unsigned short row) {
    short seg = (row / 3) * 3 + column / 3;
    return seg;
}
