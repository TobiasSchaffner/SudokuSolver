#include "gtest/gtest.h"
#include "../../include/gameboard.h"
#include "../../include/util.h"
#include "../../include/generator.h"


class GameBoardTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        gb = new Gameboard(9);
    }

    virtual void TearDown() {
        delete gb;
        gb = NULL;
    }

    static Gameboard* gb;

};

Gameboard* GameBoardTest::gb = NULL;
static constexpr int nearlyfullGameboard[9][9] = {{ 7,  0,  4,  2,  5,  3,  8,  9,  6},
                                                  { 2,  0,  0,  6,  7,  9,  4,  1,  5},
                                                  { 6,  0,  0,  1,  4,  8,  3,  7,  2},
                                                  { 1,  4,  2,  8,  6,  5,  7,  3,  9},
                                                  { 5,  7,  3,  4,  9,  2,  1,  6,  8},
                                                  { 9,  8,  6,  3,  1,  7,  2,  5,  4},
                                                  { 4,  2,  1,  9,  3,  6,  5,  8,  7},
                                                  { 8,  6,  5,  7,  2,  1,  9,  4,  3},
                                                  { 3,  9,  7,  5,  8,  4,  6,  2,  0}};

static constexpr int fullGameboard[9][9] = {{ 7,  1,  4,  2,  5,  3,  8,  9,  6},
                                            { 2,  3,  8,  6,  7,  9,  4,  1,  5},
                                            { 6,  5,  9,  1,  4,  8,  3,  7,  2},
                                            { 1,  4,  2,  8,  6,  5,  7,  3,  9},
                                            { 5,  7,  3,  4,  9,  2,  1,  6,  8},
                                            { 9,  8,  6,  3,  1,  7,  2,  5,  4},
                                            { 4,  2,  1,  9,  3,  6,  5,  8,  7},
                                            { 8,  6,  5,  7,  2,  1,  9,  4,  3},
                                            { 3,  9,  7,  5,  8,  4,  6,  2,  1}};

TEST(Gameboard, GameBoardInitalTest) {
    EXPECT_NE(new Gameboard(9), nullptr);
}

/*
TEST_F(GameBoardTest, MoveInvalidWhenSameNumberInSeg) {
    gb->applyMove(new Move(1,1,4));
    EXPECT_FALSE(gb->applyMove(new Move(1,2,4)));
}

TEST_F(GameBoardTest, MoveValidWhenDifferentNumbersInSeg) {
    gb->nextMove(1,1,6);
    EXPECT_TRUE(gb->nextMove(1,2,7));
}

TEST_F(GameBoardTest, MoveValidWhenDifferentNumbersInCol) {
    auto gb = new Gameboard(9);
    gb->nextMove(1,2,5);
    EXPECT_TRUE(gb->nextMove(1,5,8));
}

TEST_F(GameBoardTest, MoveInvalidWhenSameNumberInCol) {
    gb->nextMove(1,1,5);
    EXPECT_FALSE(gb->nextMove(1,6,5));
}

TEST_F(GameBoardTest, NextMoveColumnOutOfLowerBounds) {
    //ASSERT_DEATH(gb->nextMove(-1,1,1), "");
}


TEST_F(GameBoardTest, NextMoveColumnOutOfUpperBounds) {
    //ASSERT_DEATH(gb->nextMove(10,9,1), "");
}

TEST_F(GameBoardTest, MoveValidWhenDifferentNumbersInRow) {
    gb->nextMove(2,1,6);
    EXPECT_TRUE(gb->nextMove(4,1,7));
}

TEST_F(GameBoardTest, MoveInvalidWhenSameNumberInRow) {
    gb->nextMove(1, 3, 3);
    EXPECT_FALSE(gb->nextMove(9, 3, 3));
}

TEST_F(GameBoardTest, NextMoveRowOutOfUpperBounds) {
    EXPECT_FALSE(gb->nextMove(9,11,1));
}
*/
TEST_F(GameBoardTest, InitializeEmptyTest) {
    auto smallergb = new Gameboard(9);
    EXPECT_TRUE(smallergb->get2DArray()[0][0] == 0 && smallergb->get2DArray()[0][1] == 0
                && smallergb->get2DArray()[1][0] == 0 && smallergb->get2DArray()[1][1] == 0 );
}

TEST_F(GameBoardTest, UndoTestWithNoMovesOnStackReturnsFalse) {
    EXPECT_FALSE(gb->revertMove(new Move(0,0,0)));
}


TEST_F(GameBoardTest, UndoTestWithMovesOnStackReturnsTrue) {
    auto move = new Move(1,1,1);
    gb->applyMove(move);
    EXPECT_TRUE(gb->revertMove(move));
}


TEST_F(GameBoardTest, UndoAfterOneMoveResultsInEmptyBoard) {
    auto move = new Move(1,1,1);
    gb->applyMove(move);
    EXPECT_TRUE(gb->get2DArray()[1][1] == 1);
    gb->revertMove(move);
    EXPECT_TRUE(gb->get2DArray()[1][1] == 0);
}

TEST_F(GameBoardTest, GetEmptyFieldReturnsTheFirstInRowWhenNoneIsSet) {
    auto move = new Move(9,9,9);
    EXPECT_TRUE(gb->getFirstEmptyMove(move));
    EXPECT_TRUE(move->row == 0);
    EXPECT_TRUE(move->column == 0);
    EXPECT_TRUE(move->value == 9);
}

TEST_F(GameBoardTest, GetEmptyFieldReturnsTheFirstInRowWhenOneAlreadySet) {
    gb->applyMove(new Move(0,0,1));
    auto move = new Move(9,9,9);
    EXPECT_TRUE(gb->getFirstEmptyMove(move));
    EXPECT_TRUE(move->row == 0);
    EXPECT_TRUE(move->column == 1);
    EXPECT_TRUE(move->value == 9);
}

TEST_F(GameBoardTest, GetEmptyFieldReturnsFalseWhenBoardIsFull) {
    auto localGameboard = new Gameboard(9);
    for(int row = 0; row < 9; ++row) {
        for(int col = 0; col < 9; ++col) {
            localGameboard->applyMove(new Move(col, row, fullGameboard[row][col]));
        }
    }

    EXPECT_FALSE(localGameboard->getFirstEmptyMove(new Move(9,9,9)));
}

TEST_F(GameBoardTest, GetPromisingMoveReturnsExpectedField) {
    auto localGameboard = new Gameboard(9);
    for(int row = 0; row < 9; ++row) {
        for(int col = 0; col < 9; ++col) {
            localGameboard->applyMove(new Move(col, row, nearlyfullGameboard[row][col]));
        }
    }

    auto move = new Move(1,1,1);
    localGameboard->getPromisingMove(move);
    printf("row: %d, column: %d", move->row, move->column);
    EXPECT_TRUE(move->row == 8 && move->column == 8);
}

TEST_F(GameBoardTest, IsPossibleReturnsTrueWhenPossible) {
    gb->applyMove(new Move(0,0,1));
    EXPECT_TRUE(gb->isPossible(new Move(1,0,2)));
}

TEST_F(GameBoardTest, IsPossibleReturnsFalseWhenAlreadySet) {
    gb->applyMove(new Move(0,0,1));
    EXPECT_FALSE(gb->isPossible(new Move(0,0,2)));
}

TEST_F(GameBoardTest, IsPossibleReturnsFalseWhenRowHasValue) {
    gb->applyMove(new Move(0,0,1));
    EXPECT_FALSE(gb->isPossible(new Move(8,0,1)));
}

TEST_F(GameBoardTest, IsPossibleReturnsFalseWhenColumnHasValue) {
    gb->applyMove(new Move(0,0,1));
    EXPECT_FALSE(gb->isPossible(new Move(0,9,1)));
}

TEST_F(GameBoardTest, IsPossibleReturnsFalseWhenSegmentHasValue) {
    gb->applyMove(new Move(0,0,1));
    EXPECT_FALSE(gb->isPossible(new Move(2,2,1)));
}

TEST_F(GameBoardTest, Get2DArrayReturnsValueAtRightPosition) {
    gb->applyMove(new Move(1,9,1));
    EXPECT_TRUE(gb->get2DArray()[1][9] == 1);
}