//
// Created by confix on 4/20/17.
//

#ifndef SUDOKU_STEP_H
#define SUDOKU_STEP_H

#endif //SUDOKU_STEP_H

struct Step {
    Step(int i, int i1, int i3, const unsigned short i2){
        this->col = i;
        this->row = i1;
        this->mask = i2;
        this->value = i3;
    }

    int col;
    int row;
    unsigned short value;
    int mask;
};