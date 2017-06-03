#include <chrono>
#include "gtest/gtest.h"
#include "../../include/gameboard.h"
#include "../../include/generator.h"


class SolverTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        generator = new Generator();
    }

    virtual void TearDown() {
        delete generator;
        generator = NULL;
    }

    virtual bool gameBoardHasNoZeroes(Gameboard *gameboard) {
        int **array = gameboard->get2DArray();
        for (int cols = 0; cols < 9; ++cols) {
            for (int rows = 0; rows < 9; rows++) {
                if (array[cols][rows] == 0) {
                    return false;
                }
            }
        }
        return true;
    }



    static Generator *generator;
};

Generator *SolverTest::generator = NULL;

static constexpr int nearlyfullGameboard[9][9] = {{ 0,  0,  0,  0,  5,  0,  8,  0,  0},
                                                  { 2,  0,  0,  6,  0,  9,  4,  1,  0},
                                                  { 0,  0,  0,  1,  4,  8,  0,  7,  2},
                                                  { 1,  4,  0,  8,  0,  0,  7,  0,  0},
                                                  { 0,  7,  3,  4,  9,  2,  1,  6,  8},
                                                  { 9,  8,  0,  3,  0,  0,  2,  5,  4},
                                                  { 4,  0,  1,  9,  3,  6,  5,  8,  7},
                                                  { 8,  6,  0,  7,  2,  1,  0,  4,  0},
                                                  { 0,  9,  0,  5,  0,  0,  6,  2,  0}};


TEST_F(SolverTest, SolverLeavesNoZeroes) {
    for (int numberOfNonZeroes = 0; numberOfNonZeroes < 81; ++numberOfNonZeroes) {
        for (int runs = 0; runs < 5; ++runs) {
            auto gameboard = generator->generate(9, numberOfNonZeroes);
            auto solver = new Solver(gameboard);
            solver->solve();
            EXPECT_TRUE(gameBoardHasNoZeroes(gameboard));
            delete(gameboard);
            delete(solver);
        }
    }
     /*
    for (int runs = 0; runs < 1000; ++runs) {

        auto localGameboard = new Gameboard(9);
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                localGameboard->applyMove(new Move(col, row, nearlyfullGameboard[row][col]));
            }
        }
        auto solver = new Solver(localGameboard);
        solver->solve();
        EXPECT_TRUE(gameBoardHasNoZeroes(localGameboard));
        delete(localGameboard);
        delete(solver);
    }*/
}


