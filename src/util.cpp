#include <vector>
#include "../include/util.h"

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



unsigned short getBitLeft(unsigned short input, unsigned short position) {
    unsigned short mask = ~((position << 1) - 1);
    unsigned short possibles = input & mask;
    return getRightestBit(possibles);
}

unsigned short getRightestBit(unsigned short input) {
    unsigned short result = 0;
    for (unsigned short bitmask : BIT_CONSTS) {
        result = input & bitmask;
        if (result) {
            break;
        }
    }
    return result;
}

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


std::vector<std::string> split(std::string toSplit, char* deliminator) {
    std::vector<std::string> result;

    unsigned long next = 0;

    for(unsigned long pos = 0; pos < toSplit.length() - 1; pos = next + 1) {
        next = toSplit.find(deliminator, pos);
        result.push_back(toSplit.substr(pos, next - pos));
    }
    result.push_back(toSplit.substr(toSplit.length() - 1, 1));

    return result;
}