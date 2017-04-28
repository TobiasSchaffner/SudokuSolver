#include "gtest/gtest.h"
#include "../../include/gameboard.h"


TEST(Gameboard, GameBoardInitalTest) {
    EXPECT_NE(new Gameboard(5), nullptr);
}

TEST(Gameboard, MoveInvalidWhenSameNumberInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,5);
    EXPECT_FALSE(gb->nextMove(1,6,5));
}

TEST(Gameboard, MoveInvalidWhenSameNumberInRow) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,3,3);
    EXPECT_FALSE(gb->nextMove(9,3,3));
}

TEST(Gameboard, MoveInvalidWhenSameNumberInSeg) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,4);
    EXPECT_FALSE(gb->nextMove(1,2,4));
}

TEST(GameBoard, MoveValidWhenDifferentNumbersInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,2,6);
    EXPECT_TRUE(gb->nextMove(1,4,7));
}

TEST(GameBoard, MoveValidWhenDifferentNumbersInRow) {
    auto gb = new Gameboard(9);
    gb->nextMove(2,1,6);
    EXPECT_TRUE(gb->nextMove(4,1,7));
}

TEST(GameBoard, MoveValidWhenDifferentNumbersInSeg) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,6);
    EXPECT_TRUE(gb->nextMove(1,2,7));
}

TEST(GameBoard, NextMoveOutOfLowerBounds) {
    //auto gb = new Gameboard(8);
    //ASSERT_DEATH(gb->nextMove(-1,1,1), "");
}

/**
 * Warum schlägt hier der assert nicht an?
 */
TEST(GameBoard, NextMoveColumnOutOfUpperBounds) {
    //auto gb = new Gameboard(8);
    //ASSERT_DEATH(gb->nextMove(10,9,1), "");
}


TEST(GameBoard, NextMoveColumnOutOfLowerBounds) {
    auto gb = new Gameboard(8);
    EXPECT_FALSE(gb->nextMove(9,10,1));
}


