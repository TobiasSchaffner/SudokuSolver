#include <assert.h>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <util.h>
#include "../include/gameboard.h"
#include "../include/generator.h"

Gameboard* Generator::generate(int size, int solved) {
    assert(size * size >= solved);
    Gameboard* gameboard;

    gameboard = getSeededGameboard(size);
    auto solver = new Solver(gameboard);
    solver->solve();
    randomRemove(gameboard, solved);

    return gameboard;
}

void Generator::randomRemove(Gameboard* gameboard, int solved) {
    auto move = new Move();
    for (int i = 0; i < gameboard->getSize() * gameboard->getSize() - solved; i++) {
        move->row = rand() % gameboard->getSize();
        move->column = rand() % gameboard->getSize();
        while(!gameboard->revertMove(move)){
            move->row = rand() % gameboard->getSize();
            move->column = rand() % gameboard->getSize();
        }
    }
    delete(move);
}

int* Generator::randomArray(int size) {
    int* numbers = new int[size];
    for (int i = 0; i < size; i++) numbers[i] = i + 1;
    std::srand((unsigned int) std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::random_shuffle(&numbers[0], &numbers[size]);
    return numbers;
}

Gameboard* Generator::getSeededGameboard(int size) {
    auto firstRowValues = randomArray(size);
    auto firstColumnValues = randomArray(size);
    auto gameboard = new Gameboard(size);

    auto move = new Move();

    move->row = 0;
    for (move->column = 0; move->column < size; move->column++) {
        move->value = firstRowValues[move->column];
        gameboard->applyMove(move);
    }

    int frontIndex = 1;
    int backIndex = 3;
    move->column = 0;
    for (int row = 0; row < size; row++) {
        move->value = firstColumnValues[row];
        if (firstColumnValues[row] == firstRowValues[0]) {
            continue;
        } else if (firstColumnValues[row] == firstRowValues[1] ||
               firstColumnValues[row] == firstRowValues[2]) {
            move->row = backIndex++;
        } else {
            if (frontIndex < 3)
                move->row = frontIndex++;
            else
                move->row = backIndex++;
        }
        gameboard->applyMove(move);
    }

    print2DArray(gameboard->get2DArray(), 9);

    delete(move);
    return gameboard;
}
