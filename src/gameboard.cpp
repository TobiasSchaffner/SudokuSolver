#include "../include/gameboard.h"
#include "../include/util.h"

Gameboard::Gameboard(int size) {
    // other sizes not implemented yet
    assert(size == 9 && "Other sizes than 9 not yet implemented!");

    this->size = size;
    boardData = new int*[size];
    for(int i = 0; i < size; ++i)
        boardData[i] = new int[size]{0};

    rows = new int[size]{0};
    columns = new int[size]{0};
    segments = new int[size]{0};
}

Gameboard::~Gameboard() {
    for(int i = 0; i < this->size; ++i)
        delete(boardData[i]);
    delete[] boardData;
    delete[] rows;
    delete[] columns;
    delete[] segments;
}

bool Gameboard::getFirstEmptyMove(Move *move) {
    for (move->row = 0; move->row < size; move->row++) {
        for (move->column = 0; move->column < size; move->column++) {
            if (boardData[move->column][move->row] == 0) {
                return true;
            }
        }
    }
    return false;
}

void Gameboard::applyBitMasks(Move* move) {
    auto seg = getSegmentNumber(move->column, move->row);
    columns[move->column] = columns[move->column] | (1 << (move->value - 1));
    rows[move->row] = rows[move->row] | (1 << (move->value - 1));
    segments[seg] = segments[seg] | (1 << (move->value - 1));
}

void Gameboard::applyMove(Move* move) {
    assert(0 <= move->column < this->size);
    assert(0 <= move->row < this->size);
    assert(0 <= move->value < this->size);

    this->boardData[move->column][move->row] = move->value;
    applyBitMasks(move);
}

void Gameboard::revertBitMasks(Move* move) {
    int seg = getSegmentNumber(move->column, move->row);
    columns[move->column] = columns[move->column] - (1 << (move->value - 1));
    rows[move->row] = rows[move->row] - (1 << (move->value - 1));
    segments[seg] = segments[seg] - (1 << (move->value - 1));
}

bool Gameboard::revertMove(Move* move) {
    assert(0 <= move->column < this->size);
    assert(0 <= move->row < this->size);
    assert(0 <= move->value < this->size);

    if (boardData[move->column][move->row] == 0) return false;
    boardData[move->column][move->row] = 0;
    revertBitMasks(move);
    return true;
}

bool Gameboard::checkRow(Move* move) {
    for (int col = 0; col < size; col++) {
        if (boardData[col][move->row] == move->value) {
            return true;
        }
    }
    return false;
}

bool Gameboard::checkColumn(Move* move) {
    for (int row = 0; row < size; row++) {
        if (boardData[move->column][row] == move->value) {
            return true;
        }
    }
    return false;
}

bool Gameboard::checkField(Move* move) {
    for (int rowOffset = 0; rowOffset < 3; rowOffset++) {
        for (int columnOffset = 0; columnOffset < 3; columnOffset++) {
            if (boardData[getSegmentStart(move->column) + columnOffset][getSegmentStart(move->row) + rowOffset] == move->value) {
                return true;
            }
        }
    }
    return false;
}

bool Gameboard::isPossible(Move* move) {
    return !checkRow(move) &&
           !checkColumn(move) &&
           !checkField(move);
}

int** Gameboard::get2DArray() const {
    return boardData;
}

int Gameboard::getSize() const {
    return size;
}

bool Gameboard::getPromisingMove(Move *move) {
    int max = 0;

    for (int column = 0; column < getSize(); column++) {
        for (int row = 0; row < getSize(); row++) {
            int valuesSet = getSetPositions(column, row);
            column;
            row;
            valuesSet;
            if (valuesSet > max) {
                move->column = column;
                move->row = row;
                max = valuesSet;
            }
        }
    }
    return max > 0;
}

int Gameboard::getSetPositions(int column, int row) {
    int seg = getSegmentNumber(column, row);
    return boardData[column][row] != 0 ? 0 : __builtin_popcount(rows[row] | columns[column] | segments[seg]);
}
