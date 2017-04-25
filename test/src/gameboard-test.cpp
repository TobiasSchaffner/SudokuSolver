#include "gtest/gtest.h"
#include "../../include/gameboard.h"


TEST(Gameboard, SomeTest) {
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
    EXPECT_TRUE(gb->nextMove(4,4,6));
}