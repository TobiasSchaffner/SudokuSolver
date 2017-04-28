#include "gtest/gtest.h"
#include "../../include/gameboard.h"


TEST(Gameboard1, GameBoardInitalTest) {
    EXPECT_NE(new Gameboard(5), nullptr);
}

TEST(Gameboard2, MoveInvalidWhenSameNumberInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,5);
    EXPECT_FALSE(gb->nextMove(1,6,5));
}

TEST(Gameboard3, MoveInvalidWhenSameNumberInRow) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,3,3);
    EXPECT_FALSE(gb->nextMove(9,3,3));
}

TEST(Gameboard4, MoveInvalidWhenSameNumberInSeg) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,4);
    EXPECT_FALSE(gb->nextMove(1,2,4));
}

TEST(GameBoard5, MoveValidWhenDifferentNumbersInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,2,6);
    EXPECT_TRUE(gb->nextMove(1,4,7));
}

TEST(GameBoard6, MoveValidWhenDifferentNumbersInRow) {
    auto gb = new Gameboard(9);
    gb->nextMove(2,1,6);
    EXPECT_TRUE(gb->nextMove(4,1,7));
}

TEST(GameBoard7, MoveValidWhenDifferentNumbersInSeg) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,6);
    EXPECT_TRUE(gb->nextMove(1,2,7));
}

TEST(GameBoard8, NextMoveOutOfLowerBounds) {
    //auto gb = new Gameboard(8);
    //ASSERT_DEATH(gb->nextMove(-1,1,1), "");
}

/**
 * Warum schlägt hier der assert nicht an?
 */
TEST(GameBoard9, NextMoveColumnOutOfUpperBounds) {
    auto gb = new Gameboard(8);
    EXPECT_FALSE(gb->nextMove(10,9,1));
}


TEST(GameBoard10, NextMoveColumnOutOfLowerBounds) {
    auto gb = new Gameboard(8);
    EXPECT_FALSE(gb->nextMove(9,10,1));
}


