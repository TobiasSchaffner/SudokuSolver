//
// Created by platypus on 5/31/17.
//

#include <assert.h>
#include <algorithm>
#include <ctime>
#include "../include/gameboard.h"
#include "../include/generator.h"
#include "../include/solver.h"

static int iteration = 1;

Gameboard* Generator::generate(int size, int solved) {
    assert(size * size >= solved);
    Gameboard* gameboard;

    bool solvableGameboardCreated = false;
    while (!solvableGameboardCreated) {
        gameboard = getSeededGameboard(size);
        auto solver = new Solver(gameboard);
        solvableGameboardCreated = solver->solve();
    }

    randomRemove(gameboard, solved);

    return gameboard;
}

void Generator::randomRemove(Gameboard* gameboard, int solved) {
    Move* move = new Move();
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
    std::srand(std::time(0) / iteration);
    iteration++;
    std::random_shuffle(&numbers[0], &numbers[size]);
    return numbers;
}

Gameboard* Generator::getSeededGameboard(int size) {
    auto firstRowValues = randomArray(size);
    auto firstColumnValues = randomArray(size);
    auto gameboard = new Gameboard(size);

    auto move = new Move();

    for (move->column = 0; move->column < size; move->column++) {
        move->value = firstRowValues[move->column];
        gameboard->applyMove(move);
    }

    int offset = 1;
    move->column = 0;
    for (move->row = 1; move->row < size; move->row++) {
        if (firstColumnValues[move->row -1] == firstRowValues[0]) offset = 0;
        move->value = firstColumnValues[move->row - offset];
        gameboard->applyMove(move);
    }

    delete(move);
    return gameboard;
}
