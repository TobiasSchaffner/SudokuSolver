//
// Created by confix on 4/27/17.
//

#ifndef SUDOKU_BOARD_INITIALIZER_H
#define SUDOKU_BOARD_INITIALIZER_H

#endif //SUDOKU_BOARD_INITIALIZER_H

#include <string>
#include <vector>
#include <map>
#include "gameboard.h"

class BoardInitializer {
public:
    Gameboard *create(std::string gameName);

    char **getGamesSelection();

    /** Returns a map with the absolute paths of all files in the given directory.
     * Reading the directory path form environment variable: SUDOKU_CONF.
     */
    std::map<int, std::string> create();
};

