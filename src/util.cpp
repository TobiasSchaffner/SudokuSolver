#include <iostream>
#include "../include/util.h"

void print2DArray(int **array, int size) {
    for (unsigned int row = 0; row < size; ++row) {
        for (unsigned int column = 0; column < size; ++column) {

            printf("%2d ", array[column][row]);
        }
        printf("\n");
    }
    printf("\n");
}

int getSegmentStart(int index) {
    return index - index % 3;
}

int getSegmentNumber(int column, int row) {
    return (row / 3) * 3 + column / 3;
}
