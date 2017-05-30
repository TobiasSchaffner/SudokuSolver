#include <iostream>
#include "../include/util.h"

void print2DArray(int **array, int size){
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column<size; ++column) {
            printf("%2d ", array[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}

unsigned short getSegmentStart(int index) {
    return index - index % 3;
}
