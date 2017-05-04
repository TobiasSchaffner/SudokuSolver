//
// Created by confix on 4/27/17.
//

#ifndef SUDOKU_BOARD_INITIALIZER_H
#define SUDOKU_BOARD_INITIALIZER_H

#endif //SUDOKU_BOARD_INITIALIZER_H

#include <string>
#include "gameboard.h"

class BoardInitializer {
public:
    Gameboard* create(std::string gameName);
    char** getGamesSelection();
};

