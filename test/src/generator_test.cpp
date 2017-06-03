#include "gtest/gtest.h"
#include "../../include/gameboard.h"
#include "../../include/util.h"
#include "../../include/generator.h"


class GeneratorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        generator = new Generator();
    }

    virtual void TearDown() {
        delete generator;
        generator = NULL;
    }

    virtual bool givenNumberOfFieldsAreZero(Gameboard *gameboard, int numberOfFieldsToBeZero) {
        int countedZeros = 0;
        int **array = gameboard->get2DArray();
        for (int cols = 0; cols < 9; ++cols) {
            for (int rows = 0; rows < 9; rows++) {
                if (array[cols][rows] == 0) {
                    countedZeros++;
                }
            }
        }
        if(countedZeros == numberOfFieldsToBeZero) {
            return true;
        } else {
            return false;
        }

    }

    static Generator *generator;
};

Generator *GeneratorTest::generator = NULL;


TEST_F(GeneratorTest, GeneratorCreatesFullGameBoardsWhenNoDeletesAreSet) {
    for (int runs = 0; runs < 10; ++runs) {
        auto gameboard = generator->generate(9, 81);
        EXPECT_TRUE(givenNumberOfFieldsAreZero(gameboard, 0));
        delete(gameboard);
    }
}


TEST_F(GeneratorTest, GeneratorCreatesGameBoardWith20Zeroes) {
    for (int runs = 0; runs < 10; ++runs) {
        auto gameboard = generator->generate(9, 61);
        EXPECT_TRUE(givenNumberOfFieldsAreZero(gameboard, 20));
        delete(gameboard);
    }
}
