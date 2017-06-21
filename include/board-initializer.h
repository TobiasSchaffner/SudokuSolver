#ifndef SUDOKU_BOARD_INITIALIZER_H
#define SUDOKU_BOARD_INITIALIZER_H

#endif //SUDOKU_BOARD_INITIALIZER_H

#include <string>
#include <vector>
#include <map>
#include "gameboard.h"

/**
 * @file board-initializer.h
 *
 * @brief Contains the declaration of the BoardInitializer.class.
 *
 * Implemented in board-initializer.cpp.
 *
**/


/**
 * @class BoardInitializer
 *
 * @brief Loads gameboards from files, which are hold in the conf-folder.
 *
 * Also creates gameboards specific from given filenames.
 */
class BoardInitializer {
public:
    /**
    * @brief creates a new gameboard.
    *
    * Creates a new gameboard from the file with the given name.
    */
    Gameboard *create(std::string gameName);

    char **getGamesSelection();

    /**
    * @brief returns map with all found game-files.
    *
    * Returns a map with the absolute paths of all files in the given directory.
    * Reading the directory path form environment variable: SUDOKU_CONF.
    */
    std::map<int, std::string> create();
};

