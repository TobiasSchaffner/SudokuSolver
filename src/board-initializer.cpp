
#include <board-initializer.h>
#include <fstream>
#include "util.h"
#include <sstream>
#include <gameboard.h>
#include <vector>
#include <cstring>

#if defined(WIN32) || defined(_WIN32)
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

class file_not_found_exception : public std::exception {
    virtual const char *what() const throw() {
        return "Your requested gamefile was not found";
    }
};

class env_not_set_exception : public std::exception {
        virtual const char *what() const throw() {
            return "Set ENV \"SUDOKU_CONF\" to the config path";
        }
};



Gameboard* BoardInitializer::create(std::string gameName) {
    std::string path, contents, line, field;
    std::vector<std::vector<int>> board;

    char* confDir = std::getenv("SUDOKU_CONF");

    if(confDir == NULL)
        throw new env_not_set_exception;
    unsigned int i = 0;
    while(confDir[i] != '\0') {
        ++i;
    }


    path.reserve(i - 1 + gameName.length());

    path.append(confDir);
    path.append(PATH_SEPARATOR);
    path.append(gameName);


    std::cout << path << std::endl;
    std::ifstream config(path);

    if (config.fail()) {
        throw file_not_found_exception();
    }

    config.seekg(0, std::ios::end);
    contents.reserve((unsigned long) config.tellg()); // allocate space for file contents.
    config.seekg(0, std::ios::beg);

    contents.assign(std::istreambuf_iterator<char>(config), std::istreambuf_iterator<char>());

    std::istringstream input(contents);

    while(getline(input, line)) {
        std::istringstream l(line);
        std::vector<int> ld;
        while(getline(l, field, ',')) {
            ld.push_back(std::stoi(field));
        }
        board.push_back(ld);
    }

    auto gb = new Gameboard(board.size()); // since the board has to be quadratic

    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board.size(); ++j) {
            int val = board[i][j];
            if(val > 0)
                gb->nextMove(j+1, i + 1, board[i][j]);
        }
    }

    return gb;
}

char **BoardInitializer::getGamesSelection() {
    return nullptr;
}
