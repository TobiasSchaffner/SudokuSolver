#include "../include/gameboard.h"
#include "util.h"

Gameboard::Gameboard(unsigned int size) {
    // other sizes not implemented yet
    assert(size == 9 && "Other sizes than 9 not yet implemented!");

    this->size = size;
    this->boardData = new int*[size];
    for(int i = 0; i < size; ++i)
        this->boardData[i] = new int[size]{0};
}

Gameboard::~Gameboard() {
    for(int i = 0; i < this->size; ++i)
        delete(this->boardData[i]);
    delete(this->boardData);
}

bool Gameboard::getEmptyField(Move *move) {
    for (move->row = 0; move->row < size; move->row++) {
        for (move->column = 0; move->column < size; move->column++) {
            if (boardData[move->column][move->row] == 0) {
                return true;
            }
        }
    }
    return false;
}

void Gameboard::applyMove(Move* move) {
    assert(0 <= move->column < this->size);
    assert(0 <= move->row < this->size);
    assert(0 <= move->value < this->size);

    this->boardData[move->column][move->row] = move->value;
}

void Gameboard::revertMove(Move* move) {
    this->boardData[move->column][move->row] = 0;
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
    return this->boardData;
}

int Gameboard::getSize() const {
    return this->size;
}