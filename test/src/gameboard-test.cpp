#include "gtest/gtest.h"
#include "../../include/gameboard.h"


TEST(Gameboard, GameBoardInitalTest) {
    EXPECT_NE(new Gameboard(5), nullptr);
}

/*
 * TODO
 * Failed öfter mal, checken warum.
 */
TEST(GameBoardSegmentTest, MoveInvalidWhenSameNumberInSeg) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,4);
    EXPECT_FALSE(gb->nextMove(1,2,4));
}

TEST(GameBoardSegmentTest, MoveValidWhenDifferentNumbersInSeg) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,6);
    EXPECT_TRUE(gb->nextMove(1,2,7));
}

TEST(GameboardColumnTest, MoveValidWhenDifferentNumbersInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,2,6);
    EXPECT_TRUE(gb->nextMove(1,4,7));
}

TEST(GameboardColumnTest, MoveInvalidWhenSameNumberInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,5);
    EXPECT_FALSE(gb->nextMove(1,6,5));
}

TEST(GameboardColumnTest, NextMoveColumnOutOfLowerBounds) {
    //auto gb = new Gameboard(8);
    //ASSERT_DEATH(gb->nextMove(-1,1,1), "");
}

/**
 * Warum schlägt hier der assert nicht an?
 */
TEST(GameboardColumnTest, NextMoveColumnOutOfUpperBounds) {
    //auto gb = new Gameboard(8);
    //ASSERT_DEATH(gb->nextMove(10,9,1), "");
}

TEST(GameboardRowTest, MoveValidWhenDifferentNumbersInRow) {
    auto gb = new Gameboard(9);
    gb->nextMove(2,1,6);
    EXPECT_TRUE(gb->nextMove(4,1,7));
}

TEST(GameboardRowTest, MoveInvalidWhenSameNumberInRow) {
    auto gb = new Gameboard(9);
    gb->nextMove(1, 3, 3);
    EXPECT_FALSE(gb->nextMove(9, 3, 3));
}

TEST(GameboardRowTest, NextMoveRowOutOfUpperBounds) {
    auto gb = new Gameboard(8);
    EXPECT_FALSE(gb->nextMove(9,10,1));
}

TEST(Gameboard, InitializeEmptyTest) {
    auto gb = new Gameboard(2);
    EXPECT_TRUE(gb->get2DArray()[0][0] == 0 && gb->get2DArray()[0][1] == 0
                && gb->get2DArray()[1][0] == 0 && gb->get2DArray()[1][1] == 0 );
}

TEST(GameboardUndoTest, UndoTestWithNoMovesOnStackReturnsFalse) {
    auto gb = new Gameboard(9);
    EXPECT_FALSE(gb->undo());
}

TEST(GameboardUndoTest, UndoTestWithMovesOnStackReturnsTrue) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,1);
    EXPECT_TRUE(gb->undo());
}

TEST(GameboardUndoTest, UndoAfterOneMoveResultsInEmptyBoard) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,1,1);
    EXPECT_TRUE(gb->get2DArray()[0][0] == 1);
    gb->undo();
    EXPECT_TRUE(gb->get2DArray()[0][0] == 0);
}

TEST(GameboardIsSolvedTest, IsSolvedReturnsFalseOnEmptyField) {
    auto gb = new Gameboard(9);
    EXPECT_FALSE(gb->isSolved());
}

/**
 * Warum gibt der erste EXPECT_TRUE false zurück?
 */
TEST(GameboardIsSolvedTest, IsSolvedReturnsTrueWhenGameboardIsFull) {
    auto gb = new Gameboard(3);
    gb->nextMove(1,1,1);
    gb->nextMove(1,2,2);
    EXPECT_TRUE(gb->nextMove(1,3,3));
    gb->nextMove(2,1,4);
    gb->nextMove(2,2,5);
    gb->nextMove(2,3,6);
    gb->nextMove(3,1,7);
    gb->nextMove(3,2,8);
    gb->nextMove(3,3,9);
    EXPECT_TRUE(gb->isSolved());
}

