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


TEST_F(SolverTest, SolverLeavesNoZeroes) {
    for (int numberOfZeroes = 0; numberOfZeroes < 81; ++numberOfZeroes) {
        for (int runs = 0; runs < 5; ++runs) {
            auto gameboard = generator->generate(9, numberOfZeroes);
            auto solver = new Solver(gameboard);
            solver->solve();
            EXPECT_TRUE(gameBoardHasNoZeroes(gameboard));
        }
    }
}


