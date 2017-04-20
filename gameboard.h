

#include "cmake-build-debug/step.h"

#ifndef SUDOKU_GAMEBOARD_H
#define SUDOKU_GAMEBOARD_H

#endif //SUDOKU_GAMEBOARD_H


class Gameboard {


private:
    unsigned short *rows;
    unsigned short *cols;
    unsigned short *segs;

    const static unsigned short SEGMENT_COMPLETE;


public:
    const static unsigned short BIT_CONSTS[];
    Gameboard();
    ~Gameboard();
    unsigned short getPossibleMoves(int col, int row);
    Step set(int col, int row, unsigned char value);
    void revert(Step step);
};