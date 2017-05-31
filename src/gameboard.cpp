#include <cmath>
#include "../include/gameboard.h"
#include "util.h"

Gameboard::Gameboard(unsigned int size) {
    const unsigned int arrayLen = size;

    this->rows = new unsigned short[arrayLen]{0};
    this->columns = new unsigned short[arrayLen]{0};
    this->segments = new unsigned short[arrayLen]{0};

    this->size = size;
    this->boardData = new int*[size];
    for(int i = 0; i < size; ++i)
        this->boardData[i] = new int[size]{0};

    this->segLength = (unsigned int) sqrt(size);
    this->max_possibles = (1 << size) - 1;
}

Gameboard::~Gameboard() {
    delete(this->rows);
    delete(this->columns);
    delete(this->segments);
    for(int i = 0; i < this->size; ++i)
        delete(this->boardData[i]);
    delete(this->boardData);
}


bool Gameboard::nextMove(unsigned short column, unsigned short row, unsigned short value) {

    assert(0 <= column < this->size);
    assert(0 <= row < this->size);
    assert(0 <= value < this->size);

    bool moveValid = false;
    const unsigned short mask = (1 << (value - 1));
    if((mask & this->getPossibleMoves(column, row)) == mask) {
        Move nextMove(column, row, mask);
        next(nextMove);

        // TODO ERROR nach Konvention liegen die Daten in boardData nach [column][row] vor. Das scheint mir hier nicht richtig zu sein.
        this->boardData[row][column] = value;
        moveValid = true;
    }

    return moveValid;
}

bool Gameboard::revertMove(Move m) {
    const int seg = getSegmentNumber(m.column, m.row);

    // If already 0 do nothing
    if (boardData[m.column][m.row] == 0)
        return false;

    // apply reverse bitmask to rol/col/seg information

    //TODO ERROR value liegt meiner Meinung nach schon als Bitmaske vor. Siehe nextMove. Hier wird aber trotzdem nochmal zu ner bitmaske geschiftet.
    this->columns[m.column] = this->columns[m.column] - (1 << (m.value - 1));
    this->rows[m.row] = this->rows[m.row] - (1 << (m.value - 1));
    this->segments[seg] = this->segments[seg] - (1 << (m.value - 1));

    this->boardData[m.column][m.row] = 0;
    return true;
}

void Gameboard::next(Move move) {
    const unsigned short seg = getSegmentNumber(move.column, move.row);
    this->columns[move.column] = this->columns[move.column] | move.value;
    this->rows[move.row] = this->rows[move.row] | move.value;
    this->segments[seg] = this->segments[seg] | move.value;
}


const unsigned short Gameboard::getPossibleMoves(unsigned short column, unsigned short row) const {

    if(!this->isPosInBounds(column)) {
        char res[50];
        std::sprintf(res, this->MS_ERR_COL, column);
        throw new std::invalid_argument(res);
    }

    if(!this->isPosInBounds(row)) {
        char res[50];
        std::sprintf(res, this->MS_ERR_ROW, row);
        throw new std::invalid_argument(res);
    }

    const unsigned short seg = getSegmentNumber(column, row);

    int r = rows[row];
    int c = columns[column];
    int s = segments[seg];
    int mp = this->max_possibles;

    // TODO ERROR nach Konvention liegen die Daten in boardData nach [column][row] vor. Das scheint mir hier nicht richtig zu sein.
    int currVal = this->boardData[row][column];
    return (unsigned short) this->boardData[row][column] != 0 ? 0 : this->max_possibles - (
            rows[row] | columns[column] | segments[seg]);
}

bool Gameboard::isSolved() {
    for(int i = 0; i < this->size; ++i) {
        if(this->max_possibles != (this->rows[i] & this->columns[i] & this->segments[i])) return false;
    }
    return true;
}

int** Gameboard::get2DArray() const {
    return this->boardData;
}

bool Gameboard::isPosInBounds(unsigned short pos) const {
    return 0 <= pos < this->size;
}

unsigned const int Gameboard::getSize() const {{}
    return this->size;
}