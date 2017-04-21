#include "gameboard.h"
#include "util.h"

Gameboard::Gameboard() {
    this->rows = new unsigned short[9];
    this->columns = new unsigned short[9];
    this->segments = new unsigned short[9];
}

Gameboard::~Gameboard() {
    delete(this->rows);
    delete(this->columns);
    delete(this->segments);
}

Step Gameboard::set(unsigned short column, unsigned short row, unsigned short value) {
    Step step(column - 1, row - 1, (1 << (value - 1)));
    this->set(step);
    return step;
}

void Gameboard::set(Step step) {
    const int seg = step.column / 3 * step.row / 3;
    this->columns[step.column] = this->columns[step.column] | step.value;
    this->rows[step.row] = this->rows[step.row] | step.value;
    this->segments[seg] = this->segments[seg] | step.value;
    this->steps.push(step);
}

bool Gameboard::revert() {
    if (steps.empty()) return false;
    Step step = steps.top();
    this->revert(step);
    steps.pop();
    return true;
}

void Gameboard::revert(Step step) {
    const int seg = step.column / 3 * step.row / 3;
    this->columns[step.column] = this->columns[step.column] ^ step.value;
    this->rows[step.row] = this->rows[step.row] ^ step.value;
    this->segments[seg] = this->segments[seg] ^ step.value;
}

unsigned short Gameboard::getPossibleMoves(unsigned short column, unsigned short row) {
    const int seg = column / 3 * row / 3;
    return SEGMENT_COMPLETE - (
            this->rows[row] | this->columns[column] | this->segments[seg]);
}

int** Gameboard::get2DArray(){
    int** board = 0;
    board = new int*[9];
    for (int height = 0; height < 9; ++height) board[height] = new int[9];
    for (unsigned short column = 0; column<9; column++) {
        unsigned short column_short = this->columns[column];
        for(unsigned short number = 1; number < 10; number++) {
            if (column_short & BIT_CONSTS[number - 1]) {
                for (unsigned short row = 0; row < 9; row++) {
                    if(this->rows[row] & (1 << (number - 1))) {
                        board[column][row] = number;
                    }
                }
            }
        }
    }
    return board;
}

void Gameboard::print(){
    int** board = this->get2DArray();
    for (int row = 0; row < 9; ++row) {
        for (int column = 0; column<9; ++column) {
            std::cout << board[column][row] << " ";
        }
        std::cout << std::endl;
    }
}

unsigned long Gameboard::getSteps() {
    return steps.size();
}
