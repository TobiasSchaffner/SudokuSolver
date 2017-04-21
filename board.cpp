

#include "board.h"

void Board::set(int col, int row, int value) {
    this->board[col][row] = value;
}

std::ostream& operator<<(std::ostream & out, const Board & self) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            out << self.board[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}