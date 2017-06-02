#include <board-initializer.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include <dirent.h>

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

class directory_not_found_exception : public std::exception {
    virtual const char *what() const throw() {
        return "Your requested directory was not found";
    }
};

Gameboard *BoardInitializer::create(std::string gameName) {
    std::string contents, line, field;
    std::vector<std::vector<int>> board;

    std::ifstream config(gameName);

    if (config.fail()) throw file_not_found_exception();


    config.seekg(0, std::ios::end);
    contents.reserve((unsigned long) config.tellg()); // allocate space for file contents.
    config.seekg(0, std::ios::beg);

    contents.assign(std::istreambuf_iterator<char>(config), std::istreambuf_iterator<char>());

    std::istringstream input(contents);

    while (getline(input, line)) {
        std::istringstream l(line);
        std::vector<int> ld;
        while (getline(l, field, ',')) {
            ld.push_back(std::stoi(field));
        }
        board.push_back(ld);
    }

    auto gb = new Gameboard((int) board.size()); // since the board has to be quadratic

    for (int row = 0; row < board.size(); ++row) {
        for (int column = 0; column < board.size(); ++column) {
            int val = board[row][column];
            if (val > 0) {
                Move* move = new Move(column, row, val);
                gb->applyMove(move);
            }
        }
    }
    return gb;
}

char **BoardInitializer::getGamesSelection() {
    return nullptr;
}

std::map<int,std::string> BoardInitializer::create() {
    std::map<int,std::string> path;
    std::string directory;
    char *confDir = std::getenv("SUDOKU_CONF");

    if (confDir == NULL) throw new env_not_set_exception;

    directory.append(confDir);

    if (strcmp(&directory.back(), PATH_SEPARATOR) != 0)
        directory.append(PATH_SEPARATOR);

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(confDir)) != NULL) {
        int index = 0;
        // adding directory path for absolute path
        while ((ent = readdir(dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
                path.insert(std::make_pair(index++,directory+ent->d_name));
//                paths.push_back(directory + ent->d_name);
        }
        closedir(dir);

    } else {
        throw new directory_not_found_exception;
    }
    return path;
}
