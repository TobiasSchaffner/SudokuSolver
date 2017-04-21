//
// Created by confix on 4/21/17.
//

#include <ostream>

#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

class Board {
private:
    int** board;

public:
    Board(int);
    void set(int, int, int);
};

Board::Board(int size) {
    int** b = new int*[size];
    for(int i = 0; i < size; ++i)
        b[i] = new int[size];
    this->board = b;
}

std::ostream& operator<<(std::ostream&, const Board&);

#endif //SUDOKU_BOARD_H