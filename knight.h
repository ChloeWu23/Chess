#ifndef KNIGHT_H
#define KNIGHT_H

#include"piece.h"

class Knight: public Piece {
 public:
  Knight(string c);
  bool valid_move(int src_row, int src_col, int des_row, int des_col,ChessBoard* cb);
  virtual ~Knight();
  bool get_flag_king();
};

#endif
