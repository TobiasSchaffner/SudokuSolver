#include "gtest/gtest.h"
#include "../../include/gameboard.h"


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
static constexpr int nearlyfullGameboard[9][9] = {{ 0,  0,  0,  2,  5,  3,  8,  9,  6},
                                                  { 0,  0,  0,  6,  7,  9,  4,  1,  5},
                                                  { 0,  0,  0,  1,  4,  8,  3,  7,  2},
                                                  { 0,  4,  2,  8,  6,  5,  7,  3,  9},
                                                  { 0,  7,  3,  4,  9,  2,  1,  6,  8},
                                                  { 0,  8,  6,  3,  1,  7,  2,  5,  4},
                                                  { 0,  2,  1,  9,  3,  6,  5,  8,  7},
                                                  { 0,  6,  5,  7,  2,  1,  9,  4,  3},
                                                  { 3,  9,  7,  5,  8,  4,  6,  2,  1}};

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

TEST_F(GameBoardTest, InitializeEmptyTest) {
    auto smallergb = new Gameboard(9);
    EXPECT_TRUE(smallergb->get2DArray()[0][0] == 0 && smallergb->get2DArray()[0][1] == 0
                && smallergb->get2DArray()[1][0] == 0 && smallergb->get2DArray()[1][1] == 0 );
    delete(smallergb);
}

TEST_F(GameBoardTest, UndoTestWithNoMovesOnStackReturnsFalse) {
    EXPECT_FALSE(gb->revertMove(new Move(0,0,0)));
}


TEST_F(GameBoardTest, UndoTestWithMovesOnStackReturnsTrue) {
    auto move = new Move(1,1,1);
    gb->applyMove(move);
    EXPECT_TRUE(gb->revertMove(move));
    delete(move);
}


TEST_F(GameBoardTest, UndoAfterOneMoveResultsInEmptyBoard) {
    auto move = new Move(1,1,1);
    gb->applyMove(move);
    EXPECT_TRUE(gb->get2DArray()[1][1] == 1);
    gb->revertMove(move);
    EXPECT_TRUE(gb->get2DArray()[1][1] == 0);
    delete(move);
}

TEST_F(GameBoardTest, GetEmptyFieldReturnsTheFirstInRowWhenNoneIsSet) {
    auto move = new Move(9,9,9);
    EXPECT_TRUE(gb->getFirstEmptyMove(move));
    EXPECT_TRUE(move->row == 0);
    EXPECT_TRUE(move->column == 0);
    EXPECT_TRUE(move->value == 9);
    delete(move);
}

TEST_F(GameBoardTest, GetEmptyFieldReturnsTheFirstInRowWhenOneAlreadySet) {
    gb->applyMove(new Move(0,0,1));
    auto move = new Move(9,9,9);
    EXPECT_TRUE(gb->getFirstEmptyMove(move));
    EXPECT_TRUE(move->row == 0);
    EXPECT_TRUE(move->column == 1);
    EXPECT_TRUE(move->value == 9);
    delete(move);
}

TEST_F(GameBoardTest, GetEmptyFieldReturnsFalseWhenBoardIsFull) {
    auto localGameboard = new Gameboard(9);
    for(int row = 0; row < 9; ++row) {
        for(int col = 0; col < 9; ++col) {
            localGameboard->applyMove(new Move(col, row, fullGameboard[row][col]));
        }
    }

    EXPECT_FALSE(localGameboard->getFirstEmptyMove(new Move(9,9,9)));
    delete(localGameboard);
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
    EXPECT_TRUE(move->row == 3 && move->column == 0);
    delete(localGameboard);
    delete(move);
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