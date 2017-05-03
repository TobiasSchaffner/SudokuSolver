
#include <board-initializer.h>
#include <fstream>
#include "util.h"
#include <sstream>


class file_not_found_exception : public std::exception {
    virtual const char *what() const throw() {
        return "Your requested gamefile was not found";
    }
};



Gameboard* BoardInitializer::create(std::string gameName) {
    std::ifstream config(gameName);

    std::string contents;
    if (config.fail()) {
        throw file_not_found_exception();
    }

    config.seekg(0, std::ios::end);
    contents.reserve((unsigned long) config.tellg()); // allocate space for file contents.
    config.seekg(0, std::ios::beg);

    contents.assign(std::istreambuf_iterator<char>(config), std::istreambuf_iterator<char>());

    std::istringstream input(contents);

    std::string line, field;
    std::vector<std::vector<int>> board;
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
