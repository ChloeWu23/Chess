#ifndef QUEEN_H
#define QUEEN_H
#include"ChessBoard.h"
#include"piece.h"

class Queen: public Piece {
 public:
  Queen (string c);
  bool valid_move (int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  virtual ~Queen ();
  bool get_flag_king ();
};

#endif
