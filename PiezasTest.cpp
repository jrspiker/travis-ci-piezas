/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test {
  protected:
    PiezasTest(){} //constructor runs before each test
    virtual ~PiezasTest(){} //destructor cleans up after tests
    virtual void SetUp(){} //sets up before each test (after constructor)
    virtual void TearDown(){} //clean up after each test, (before destructor) 

};

TEST(PiezasTest, sanityCheck) {

  ASSERT_TRUE(true);

}

TEST(PiezasTest, check_tiegame) {

  Piezas game;
  for (int i=0; i < BOARD_ROWS; i++) {
    for (int j=0; j < BOARD_COLS; j++) {

      game.dropPiece(j);

    }
  }

  EXPECT_EQ(Blank, game.gameState());
  game.reset();
  EXPECT_EQ(Invalid, game.gameState());

}


TEST(PiezasTest, check_row_win)  {

  Piezas game;
  for (int i=0; i < BOARD_COLS-1; i++) {

    game.dropPiece(i); //drop an X piece in col i
    game.dropPiece(i); //drop an O piece in col i

  }

  game.dropPiece(BOARD_COLS-1); //drop an X in last col
  game.dropPiece(0);
  game.dropPiece(3);
  game.dropPiece(1);
  game.dropPiece(2);
  game.dropPiece(3);
  EXPECT_EQ(X, game.gameState());
  game.reset();
  EXPECT_EQ(Invalid, game.gameState());

}


TEST(PiezasTest, check_col_win) {

  Piezas game;
  for (int i=0; i < BOARD_COLS-2; i++) {

    game.dropPiece(i);
    game.dropPiece(i);

  }

  
    game.dropPiece(3);
    game.dropPiece(2);
    game.dropPiece(0);
    game.dropPiece(2);
    game.dropPiece(1);
    game.dropPiece(2);
    game.dropPiece(3);
    game.dropPiece(3);

    EXPECT_EQ(O, game.gameState());
    game.reset();
    EXPECT_EQ(Invalid, game.gameState());

}


TEST(PiezasTest, check_pieceAt) {

  Piezas game;

  game.dropPiece(3); //drop X into (0,3)
  game.dropPiece(1); //drop O into (0,1)
  game.dropPiece(1); //drop X into (1,1)
  game.dropPiece(3); //drop O into (1,3)
  EXPECT_EQ(X, game.pieceAt(0,3));
  EXPECT_EQ(X, game.pieceAt(1,1));
  EXPECT_EQ(O, game.pieceAt(0,1));
  EXPECT_EQ(O, game.pieceAt(1,3));

  EXPECT_EQ(Invalid, game.pieceAt(-2,3));
  EXPECT_EQ(Invalid, game.pieceAt(0,4));
  EXPECT_EQ(Invalid, game.pieceAt(-1,5));

}


TEST(PiezasTest, check_dropPieceOOB) {

  Piezas game;
 
  EXPECT_EQ(Invalid, game.dropPiece(-1));
  EXPECT_EQ(Invalid, game.dropPiece(4));

  for (int i=0; i < BOARD_ROWS; i++) {

    game.dropPiece(1);

  }

  EXPECT_EQ(Blank, game.dropPiece(1));

}


TEST(PiezasTest, check_Piece_enum) {

  Piezas game;

  EXPECT_EQ(X, game.dropPiece(1));
  EXPECT_EQ(O, game.dropPiece(1));

}
