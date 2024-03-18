#ifndef CASTLE_H
#define CASTLE_H
#include"ChessBoard.h"
#include"piece.h"
class Castle : public Piece{
public:
  //constructor
  Castle(string c);
  bool valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  virtual ~Castle();
  bool get_flag_king();
};

#endif
